/**
 * @file offset.h
 * @brief Defines types for representing signed
 *        and unsigned offsets based on system pointer size.
 *
 * This header includes the intptr.h header to use the uintptr_t and sintptr_t
 * types, ensuring that the offset types defined here (soffset_t and uoffset_t)
 * are compatible with the pointer size of the target architecture.
 *
 * These types are typically used to handle memory offsets in data structures
 * or for arithmetic operations that involve pointer manipulation.
 */

#ifndef LIQUID_OFFSET_H
#define LIQUID_OFFSET_H

#include "ptr.h"

/**
 * @def LIQUID_UOFFSET_MIN
 * @brief Macro defining the minimum unsigned offset.
 *
 * This macro resolves to the minimum value for an unsigned offset, effectively
 * equivalent to LIQUID_UINTPTR_MIN. It represents the smallest possible offset,
 * typically zero, which is used in the calculation and manipulation of memory
 * addresses. Ensuring that offsets do not drop below this value prevents
 * underflow errors in pointer arithmetic.
 */
#define LIQUID_UOFFSET_MIN LIQUID_UPTR_MIN

/**
 * @def LIQUID_UOFFSET_MAX
 * @brief Macro defining the maximum unsigned offset.
 *
 * Points to LIQUID_UINTPTR_MAX, denoting the maximum value that an unsigned
 * memory offset can hold. This value is paramount for avoiding overflow errors
 * during large memory address calculations or when defining maximum memory
 * buffer sizes. This macro is integral in ensuring safe memory allocations and
 * managing large indexes in data structures.
 */
#define LIQUID_UOFFSET_MAX LIQUID_UPTR_MAX

/**
 * @def LIQUID_SOFFSET_MIN
 * @brief Macro defining the minimum signed offset.
 *
 * Linked to LIQUID_SINTPTR_MIN, this macro specifies the lowest permissible
 * value for a signed offset, encapsulating the full negative range that a
 * signed pointer-type integer can represent. This ensures compatibility with
 * indices or positions that may need to express sub-zero offsetting in
 * calculations or memory operations.
 */
#define LIQUID_SOFFSET_MIN LIQUID_SPTR_MIN

/**
 * @def LIQUID_SOFFSET_MAX
 * @brief Macro defining the maximum signed offset.
 *
 * Corresponds to LIQUID_SINTPTR_MAX, representing the upper bound for signed
 * offsets. This ceiling is essential for preventing overflow errors in signed
 * arithmetic, particularly in pointer applications or when the negative to
 * positive transition in memory addressing and data indexing is crucial.
 */
#define LIQUID_SOFFSET_MAX LIQUID_SPTR_MAX

/**
 * @typedef soffset_t
 * @brief Signed integer type for offsets,
 *        based on the system's pointer size.
 *
 * This type is suitable for representing offsets that might be negative,
 * making it appropriate for operations where distance or displacement
 * calculations are required that can move in both directions
 * from a specific point.
 */
typedef sptr_t soffset_t;

/**
 * @typedef uoffset_t
 * @brief Unsigned integer type for offsets,
 *        based on the system's pointer size.
 *
 * Use this type for representing positive offsets only,
 * such as distances from the start of a data structure
 * to an element within it.
 *
 * The unsigned nature ensures that only non-negative values are held,
 * which is typical in scenarios where offset cannot be negative.
 */
typedef uptr_t uoffset_t;

#endif // LIQUID_OFFSET_H
