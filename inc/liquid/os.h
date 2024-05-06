#ifndef LIQUID_OS_H
#define LIQUID_OS_H

#if defined(LIQUID_TARGET_OS_WINDOWS)
    #include "os-windows.h"
#elif defined(LIQUID_TARGET_OS_LINUX)
    #include "os-linux.h"
#elif defined(LIQUID_TARGET_OS_DARWIN)
    #include "os-darwin.h"
#else
    #error "Unsupported OS"
#endif

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/**
 * @brief Get the last error message.
 * @details Retrieves the error message corresponding
 *          to the last error code from the operating system.
 *
 * @param buffer Buffer to store the error message.
 * @param buffer_size Size of the buffer.
 * @return Size of the error message.
 */
usize_t
last_error_message(errmsg_t buffer, usize_t buffer_size);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LIQUID_OS_H
