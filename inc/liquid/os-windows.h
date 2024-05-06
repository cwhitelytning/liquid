#ifndef LIQUID_OS_WINDOWS_H
#define LIQUID_OS_WINDOWS_H

#include "usize.h"

#if defined(UNICODE)
    #include <wchar.h>

/**
 * @typedef char_t
 * @brief Typedef for wide character type (wchar_t) if UNICODE is defined.
 */
typedef wchar_t char_t;
#else
/**
 * @typedef char_t
 * @brief Typedef for character type.
 */
typedef char char_t;
#endif

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/**
 * @typedef str_t
 * @brief Typedef for null-terminated character array.
 */
typedef char_t str_t[];

/**
 * @typedef errcode_t
 * @brief Typedef for error code.
 */
typedef uint_t errcode_t;

/**
 * @typedef errchar_t
 * @brief Typedef for error character type, which is the same as char_t.
 */
typedef char_t errchar_t;

/**
 * @typedef errmsg_t
 * @brief Typedef for error message.
 */
typedef errchar_t errmsg_t[];

/**
 * @typedef handle_t
 * @brief A pointer type used to represent a handle.
 *
 * This typedef defines a generic pointer type called `handle_t`,
 * typically used to represent a handle to a resource or object.
 *
 * Handles are often used in APIs to abstract away implementation details
 * and provide a level of indirection to access resources.
 */
typedef void *handle_t;

/**
 * @brief Get the last error code.
 * @details Retrieves the last error code from the operating system.
 * @return Error code.
 */
errcode_t
last_error_code();

/**
 * @brief Sets the last error code for the current thread.
 *
 * This function sets the last error code for the current thread to the
 * specified error code. Last error codes are typically used in error
 * handling to provide information about the cause of a failure.
 *
 * @param code The error code to set as the last error
 *             for the current thread.
 */
void
set_last_error_code(errcode_t code);

/**
 * @brief Get error message.
 * @details Retrieves the error message corresponding
 *          to the given error code.
 *
 * @param code Error code.
 * @param buffer Buffer to store the error message.
 * @param buffer_size Size of the buffer.
 *
 * @return Size of the error message.
 */
usize_t
error_message(errcode_t code, errmsg_t buffer, usize_t buffer_size);

/**
 * @brief Retrieves the handle of the current process.
 *
 * This function returns a handle representing the current process.
 * Handles are typically used in operating system APIs to interact
 * with processes.
 *
 * @return A handle representing the current process.
 */
handle_t
cur_proc();

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIQUID_OS_WINDOWS_H
