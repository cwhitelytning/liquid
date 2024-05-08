/**
 * @file array-raw.h
 * @brief Utility functions for raw array operations.
 *
 * This header provides macros and functions for performing low-level
 * operations on raw arrays such as copying memory blocks and calculating
 * array sizes.
 */

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

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

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

/**
 * @brief Find the position of a value within an array.
 *
 * This function searches for the first occurrence of a specified value within
 * an array, starting from 'begin' and ending at 'end'. If the value is found,
 * a pointer to the location of the value in the array is returned.
 * If the value is not found, the function returns nullptr.
 *
 * @param begin A pointer to the beginning of the array.
 * @param end A pointer to the end of the array.
 * @param value The value to search for in the array.
 *
 * @return A void pointer to the found value within the array
 *         or nullptr if not found.
 */
const void *
array_raw_pos(const void *begin, const void *end, uchar_t value);

/**
 * @brief Compares two arrays of bytes byte-by-byte.
 *
 * This function compares two given arrays byte-by-byte up to the end of either
 * array. Comparison stops when a mismatch is found or when either of the array
 * ends are reached.
 *
 * @param arr1_begin Pointer to the beginning of the first array.
 * @param arr1_end Pointer to the end of the first array.
 * @param arr2_begin Pointer to the beginning of the second array.
 * @param arr2_end Pointer to the end of the second array.
 *
 * @return If there is a mismatch, returns a pointer to the current element
 *         in the first array at the point where the mismatch occurs.
 *
 *         If no mismatch is found, returns nullptr, indicating complete
 *         matching of array contents up to the length of the shorter array.
 */
const void *
array_raw_compare(const void *arr1_begin, const void *arr1_end,
                  const void *arr2_begin, const void *arr2_end);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LIQUID_ARRAY_RAW_H
