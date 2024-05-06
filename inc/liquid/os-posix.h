#ifndef OS_POSIX_H
#define OS_POSIX_H

#include "int.h"
#include "usize.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/**
 * @typedef char_t
 * @brief Typedef for character type.
 */
typedef char char_t;

/**
 * @typedef str_t
 * @brief Typedef for null-terminated character array.
 */
typedef char_t str_t[];

/**
 * @typedef errcode_t
 * @brief Typedef for error code.
 */
typedef sint_t errcode_t;

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
 * @brief Get the last error code.
 * @details Retrieves the last error code from the operating system.
 * @return Error code.
 */
errcode_t
last_error_code();

/**
 * @brief Sets the last error code for the current thread.
 *
 * This function sets the last error code
 * for the current thread to the specified error code.
 *
 * Last error codes are typically used in error handling
 * to provide information about the cause of a failure.
 *
 * @param code The error code to set as the last error for the current thread.
 */
void
set_last_error_code(errcode_t code);

/**
 * @brief Get error message.
 * @details Retrieves the error message corresponding to the given error code.
 *
 * @param code Error code.
 * @param buffer Buffer to store the error message.
 * @param buffer_size Size of the buffer.
 *
 * @return Size of the error message.
 */
usize_t
error_message(errcode_t code, errmsg_t buffer, usize_t buffer_size);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // OS_POSIX_H
