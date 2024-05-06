cmake_minimum_required(VERSION 3.27)
project(liquid
        VERSION 0.0.1
        DESCRIPTION "OS Framework Library"
        LANGUAGES C CXX)

# Include modules for checking files and compiling conditions.
include(CheckIncludeFile)
include(CheckCSourceCompiles)

# Set the C standard to C11.
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set source files.
set(LIQUID_SOURCE_FILES
        src/array-raw.c
        src/exception.c
        src/str.c
        src/fs.c
        src/os.c)

# --------------------------------------------------------------------
# Collecting information about the target system
# --------------------------------------------------------------------

# Set preprocessor definitions based on the compiler id.
string(TOUPPER ${CMAKE_C_COMPILER_ID} COMPILER_ID_UPPER)
set(LIQUID_COMPILE_DEFINITIONS "LIQUID_COMPILER_${COMPILER_ID_UPPER}")

# Check for necessary system headers.
check_include_file("sys/stat.h" HAVE_SYS_STAT_H)
check_include_file("unistd.h" HAVE_UNISTD_H)

# Verify POSIX compatibility if unistd.h is available.
if (HAVE_UNISTD_H)
    set(CMAKE_REQUIRED_DEFINITIONS -D_POSIX_C_SOURCE=200809L)
    check_c_source_compiles("
      #include <unistd.h>
      int main() {
        #ifndef _POSIX_VERSION
              #error \"_POSIX_VERSION not defined\"
        #endif
        return 0;
      }
    " POSIX_VERSION_DEFINED)
endif ()


# Append platform-specific compile definitions based on checks.
if (POSIX_VERSION_DEFINED)
    list(APPEND LIQUID_SOURCE_FILES src/os-posix.c)
    list(APPEND LIQUID_SOURCE_FILES src/fs-posix.c)
    list(APPEND LIQUID_COMPILE_DEFINITIONS LIQUID_TARGET_OS_POSIX_LIKE)
endif ()

# Define platform target bits based on pointer size.
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    list(APPEND LIQUID_COMPILE_DEFINITIONS LIQUID_TARGET_PLATFORM=64)
elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
    list(APPEND LIQUID_COMPILE_DEFINITIONS LIQUID_TARGET_PLATFORM=32)
else ()
    message(FATAL_ERROR "Could not determine the bitness of the target system")
endif ()

# Append OS-specific compile definitions.
if (WIN32)
    list(APPEND LIQUID_SOURCE_FILES src/os-windows.c)
    list(APPEND LIQUID_SOURCE_FILES src/fs-windows.c)
    list(APPEND LIQUID_COMPILE_DEFINITIONS LIQUID_TARGET_OS_WINDOWS)
elseif (APPLE)
    list(APPEND LIQUID_SOURCE_FILES src/os-darwin.c)
    list(APPEND LIQUID_SOURCE_FILES src/fs-darwin.c)
    list(APPEND LIQUID_COMPILE_DEFINITIONS LIQUID_TARGET_OS_DARWIN)
elseif (UNIX AND NOT APPLE)
    list(APPEND LIQUID_SOURCE_FILES src/os-linux.c)
    list(APPEND LIQUID_SOURCE_FILES src/fs-linux.c)
    list(APPEND LIQUID_COMPILE_DEFINITIONS LIQUID_TARGET_OS_LINUX)
endif ()

# Create the library with specified source files.
add_library(${PROJECT_NAME} STATIC ${LIQUID_SOURCE_FILES})

# Creates the library with specified include files
set(LIQUID_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/inc")

# Configure the project with private compile definitions
# and set the public include directories.
target_compile_definitions(${PROJECT_NAME} PRIVATE ${LIQUID_COMPILE_DEFINITIONS})
target_include_directories(${PROJECT_NAME} PUBLIC ${LIQUID_INCLUDE_DIRS})

# The remaining lines involve the use of Doxygen
# for generating documentation based on the presence of the Doxygen tool in the system.
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # Path to Doxygen configuration file
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/doxyfile)

    # Replace variables in the Doxygen configuration file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # Create a build target to generate documentation
    add_custom_target(docs ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating documentation with Doxygen"
            VERBATIM
    )
endif ()

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

# Adding test source files
add_executable(tests
        test/limits.cpp
        test/os.cpp
        test/fs.cpp
        test/str.cpp
        test/gtest.cpp)

# The compilation target must include directories
target_include_directories(tests INTERFACE ${LIQUID_INCLUDE_DIRS})

# Adding dependencies and linking with libraries
target_link_libraries(tests gtest gmock liquid)

# Adding compiler options
target_compile_options(tests PRIVATE "-DUSE_LIB_OPTION")

# Adding compiler definitions
target_compile_definitions(tests PRIVATE ${LIQUID_COMPILE_DEFINITIONS})

# Enabling testing
enable_testing()

include(GoogleTest)
gtest_discover_tests(tests)