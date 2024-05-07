/**
 * @file ptr.h
 * @brief Defines pointer-sized integer types based on the target platform.
 *
 * This header provides type definitions for integer types that match
 * the pointer size of the target architecture, which is determined
 * by the LIQUID_TARGET_PLATFORM macro.
 *
 * The types defined here facilitate cross-platform development
 * by abstracting integer size differences.
 */

#ifndef LIQUID_PTR_H
#define LIQUID_PTR_H

#include "limits.h"
#include "nullptr.h"

/**
 * @def LIQUID_PTR_DIFF(start, end)
 * @brief Compute the pointer difference between two array elements.
 *
 * This macro calculates the difference between two pointers, typically
 * representing the start and end positions in an array. It is used to
 * determine the number of elements between the two pointers.
 *
 * @param start The starting pointer of the array segment.
 * @param end The ending pointer of the array segment.
 * @return The number of elements between start and end.
 */
#define LIQUID_PTR_DIFF(start, end) ((end) - (start))

#if defined(LIQUID_TARGET_PLATFORM)
    #if LIQUID_TARGET_PLATFORM == 64
        /**
         * @def LIQUID_UPTR_MIN
         * @brief Macro defining the minimum value
         *        for an unsigned pointer-sized integer.
         *
         * Directs to LIQUID_ULLONG_MIN, which signifies the smallest possible
         * value for an unsigned long long integer, usually zero.
         *
         * It is crucial in pointer-sized unsigned integer operations to
         * establish a floor value, ensuring that calculations involving
         * sizes and offsets do not underflow.
         */
        #define LIQUID_UPTR_MIN LIQUID_ULLONG_MIN

        /**
         * @def LIQUID_UPTR_MAX
         * @brief Macro defining the maximum value
         *        for an unsigned pointer-sized integer.
         *
         * Points to LIQUID_ULLONG_MAX, denoting the highest possible value that
         * an unsigned long long integer can hold, utilized here for unsigned
         * pointer-sized integers.
         *
         * Ascertaining this maximum value is critical for preventing overflow
         * in memory size calculations and memory management operations.
         */
        #define LIQUID_UPTR_MAX LIQUID_ULLONG_MAX

        /**
         * @def LIQUID_SPTR_MIN
         * @brief Macro defining the minimum value
         *        for a signed pointer-sized integer.
         *
         * Mapped to LIQUID_SLLONG_MIN, this macro specifies the lowest
         * permissible value for a signed long long integer,
         * applied to signed pointer-sized integers.
         *
         * This lower bound helps facilitate safe and accurate signing
         * arithmetic operations, particularly in scenarios involving
         * negative indexing or negative offset placements.
         */
        #define LIQUID_SPTR_MIN LIQUID_SLLONG_MIN

        /**
         * @def LIQUID_SPTR_MAX
         * @brief Macro defining the maximum value
         *        for a signed pointer-sized integer.
         *
         * Set to LIQUID_SLLONG_MAX, representing the utmost value a signed long
         * long integer can achieve, utilized for signed pointer-sized integers.
         * This upper limit is paramount in ensuring overflow does not occur
         * during complex pointer or memory size operations that require
         * extensive positive range.
         */
        #define LIQUID_SPTR_MAX LIQUID_SLLONG_MAX

/**
 * @typedef uptr_t
 * @brief Unsigned integer type
 *        with the width of a pointer on a 64-bit platform.
 */
typedef ullong_t uptr_t;

/**
 * @typedef sptr_t
 * @brief Signed integer type
 *        with the width of a pointer on a 64-bit platform.
 */
typedef sllong_t sptr_t;
    #elif LIQUID_TARGET_PLATFORM == 32
        /**
         * @def LIQUID_UPTR_MIN
         * @brief Macro defining the minimum value
         *        for an unsigned pointer-sized integer.
         *
         * Resolved to LIQUID_UINT_MIN, which sets the lowest value
         * an unsigned integer can hold, typically zero.
         *
         * This macro is vital for establishing a baseline for unsigned
         * pointer-sized integer operations, preventing underflow
         * conditions during memory address computations
         * and data manipulation.
         */
        #define LIQUID_UPTR_MIN LIQUID_UINT_MIN

        /**
         * @def LIQUID_UPTR_MAX
         * @brief Macro defining the maximum value
         *        for an unsigned pointer-sized integer.
         *
         * References LIQUID_UINT_MAX, indicating the highest value that
         * an unsigned integer can achieve, utilized here for unsigned
         * pointer-sized integers.
         *
         * This maximum limit is crucial to prevent overflow in tasks
         * such as memory allocation and handling large data set indices.
         */
        #define LIQUID_UPTR_MAX LIQUID_UINT_MAX

        /**
         * @def LIQUID_SPTR_MIN
         * @brief Macro defining the minimum value
         *        for a signed pointer-sized integer.
         *
         * Set to LIQUID_SINT_MIN, this macro specifies the lowest value
         * possible for a signed integer, effectively applying it to signed
         * pointer-sized integers.
         *
         * This value is instrumental in ensuring safe signed arithmetic,
         * particularly useful in scenarios involving negative indexing
         * or offsets in data structures and memory operations.
         */
        #define LIQUID_SPTR_MIN LIQUID_SINT_MIN

        /**
         * @def LIQUID_SPTR_MAX
         * @brief Macro defining the maximum value
         *        for a signed pointer-sized integer.
         *
         * Aligned to LIQUID_SINT_MAX, representing the maximum value a signed
         * integer can hold, utilized in signed pointer-sized integers.
         *
         * This upper boundary is essential to ensure that signed memory and
         * data operations do not cause overflows, especially when dealing
         * with high-end computational tasks.
         */
        #define LIQUID_SPTR_MAX LIQUID_SINT_MAX

/**
 * @typedef uptr_t
 * @brief Unsigned integer type
 *        with the width of a pointer on a 32-bit platform.
 */
typedef uint_t uptr_t;

/**
 * @typedef sptr_t
 * @brief Signed integer type
 *        with the width of a pointer on a 32-bit platform.
 */
typedef sint_t sptr_t;
    #endif
#else
    #error "Unknown target platform"
#endif

#endif // LIQUID_PTR_H
