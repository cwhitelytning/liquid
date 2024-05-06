#ifndef LIQUID_ARRAY_RAW_H
#define LIQUID_ARRAY_RAW_H

#include "usize.h"

/**
 * @def ARRAY_RAW_SIZE(buffer)
 * @brief Macro to calculate the size of an array.
 * @param buffer The array whose size is to be calculated.
 * @return The size of the array.
 */
#define ARRAY_RAW_SIZE(buffer) (sizeof(buffer) / sizeof(buffer[0]))

/**
 * @brief Calculate the raw length of an array segment.
 *
 * This macro calculates the difference between two pointers or indices,
 * typically representing the start and end of an array segment.
 *
 * It is a straightforward measure of the number of elements between
 * the start and end, excluding the element pointed by 'end'.
 *
 * @param start The pointer or index to the beginning of the array segment.
 * @param end The pointer or index to the end of the array segment.
 *
 * @return The number of elements between start and end.
 *
 * @note This macro does not perform any type checking
 *       and assumes that end is greater than or equal to start.
 *
 *       If the pointers are not from the same array
 *       or compatible types of arrays, the behavior is undefined.
 *
 * Example usage:
 * @code{.c}
 * int array[10];
 * int length = ARRAY_RAW_LENGTH(array, array + 5); // length will be 5
 * @endcode
 */
#define ARRAY_RAW_LENGTH(start, end) ((end) - (start))

/**
 * @brief Copies 'n' bytes from source to destination.
 *
 * This function copies the first 'n' bytes from the memory area 'src' to
 * the memory area 'dest'. The memory areas must not overlap. After copying
 * the bytes, it returns a pointer to the next byte in 'dest' after the last
 * copied byte.
 *
 * @param dest Pointer to the destination array
 *             where the content is to be copied.
 * @param src Pointer to the source of data to be copied.
 * @param n The number of bytes to copy.
 * @return Pointer to the next byte in 'dest' after the last copied byte.
 */
void *
array_raw_copy(void *dest, const void *src, usize_t n);

#endif // LIQUID_ARRAY_RAW_H
