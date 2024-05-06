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
