/**
 * @file str.h
 * @brief String manipulation utilities for raw and wide character strings.
 *
 * Provides macros and functions for copying and manipulating both raw and
 * wide character strings, with a focus on safety and buffer size management.
 */

#ifndef LIQUID_STR_H
#define LIQUID_STR_H

#include "array-raw.h"

#ifndef __cplusplus
    #include <wchar.h>
#endif

/**
 * @def STR_RAW_SIZE(str)
 * @brief Calculates the size of a string literal, excluding the null
 * terminator.
 * @param str The string literal whose size is to be determined.
 * @return The size of the string literal without the null terminator.
 * @note This macro uses ARRAY_RAW_SIZE to determine the size of the string
 *       and subtracts 1 to exclude the null terminator. It is intended for
 *       use with string literals, not pointers to strings.
 */
#define STR_RAW_SIZE(str) (ARRAY_RAW_SIZE(str) - 1)

/**
 * @def STR_RAW_CPY(dest, dest_size, src)
 * @brief Copy a raw string to a destination buffer.
 * @param dest The destination buffer where the string will be copied.
 * @param dest_size The size of the destination buffer.
 * @param src The source raw string to copy.
 * @note The size of the destination buffer must be large enough
 *       to accommodate the source string.
 */
#define STR_RAW_CPY(dest, dest_size, src)                                      \
    str_raw_cpy(dest, dest_size, src, ARRAY_RAW_SIZE(src))

/**
 * @def WSTR_RAW_CPY(dest, dest_size, src)
 * @brief Copy a wide character string to a destination buffer.
 * @param dest Pointer to the destination buffer.
 * @param dest_size Size of the destination buffer.
 * @param src Pointer to the source wide character string.
 * @return The number of characters copied (excluding the null-terminator)
 *         if successful, otherwise a negative error code.
 */
#define WSTR_RAW_CPY(dest, dest_size, src)                                     \
    wstr_raw_cpy(dest, dest_size, src, ARRAY_RAW_SIZE(src))

/**
 * @def STR_CPY(dest, dest_size, src)
 * @brief Copy a null-terminated string to a destination buffer.
 * @param dest Pointer to the destination buffer.
 * @param dest_size Size of the destination buffer.
 * @param src Pointer to the source string.
 * @return The number of characters copied (excluding the null-terminator)
 *         if successful, otherwise a negative error code.
 */
#define STR_CPY(dest, dest_size, src)                                          \
    str_cpy(dest, dest_size, src, ARRAY_RAW_SIZE(src))

/**
 * @def WSTR_CPY(dest, dest_size, src)
 * @brief Copy a null-terminated wide character string to a destination buffer.
 * @param dest Pointer to the destination buffer.
 * @param dest_size Size of the destination buffer.
 * @param src Pointer to the source wide character string.
 * @return The number of characters copied (excluding the null-terminator)
 *         if successful, otherwise a negative error code.
 */
#define WSTR_CPY(dest, dest_size, src)                                         \
    wstr_cpy(dest, dest_size, src, ARRAY_RAW_SIZE(src))

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/**
 * @brief Copy raw string data.
 * @details Copies raw string data from source to destination with specified
 * sizes.
 * @param dest Destination buffer.
 * @param dest_size Size of the destination buffer.
 * @param src Source buffer.
 * @param src_size Size of the source buffer.
 * @return Number of bytes copied.
 */
char *
str_raw_cpy(char *dest, usize_t dest_size, const char *src, usize_t src_size);

/**
 * @brief Copy raw wide string data.
 * @details Copies raw wide string data from source to destination with
 * specified sizes.
 * @param dest Destination buffer.
 * @param dest_size Size of the destination buffer.
 * @param src Source buffer.
 * @param src_size Size of the source buffer.
 * @return Number of bytes copied.
 */
wchar_t *
wstr_raw_cpy(wchar_t *dest, usize_t dest_size, const wchar_t *src,
             usize_t src_size);

/**
 * @brief Copy string data.
 * @details Copies string data from source to destination with specified sizes
 * and null-terminates the destination.
 * @param dest Destination buffer.
 * @param dest_size Size of the destination buffer.
 * @param src Source buffer.
 * @param src_size Size of the source buffer.
 * @return Number of bytes copied.
 */
char *
str_cpy(char *dest, usize_t dest_size, const char *src, usize_t src_size);

/**
 * @brief Copy wide string data.
 * @details Copies wide string data from source to destination with specified
 * sizes and null-terminates the destination.
 * @param dest Destination buffer.
 * @param dest_size Size of the destination buffer.
 * @param src Source buffer.
 * @param src_size Size of the source buffer.
 * @return Number of bytes copied.
 */
wchar_t *
wstr_cpy(wchar_t *dest, usize_t dest_size, const wchar_t *src,
         usize_t src_size);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIQUID_STR_H
