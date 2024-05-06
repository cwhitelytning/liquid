/**
 * @file usize.h
 * @brief Defines a type for representing sizes
 *        that matches the pointer size of the system.
 *
 * This header includes the intptr.h header to use the uintptr_t type,
 * ensuring that the size type defined here (usize_t) is compatible
 * with the pointer size of the target architecture.
 */

#ifndef LIQUID_USIZE_H
#define LIQUID_USIZE_H

#include "ptr.h"

/**
 * @def LIQUID_USIZE_MIN
 * @brief Macro to define a minimum size
 *        for the liquid handling in unsigned memory operations.
 *
 * This macro alias pertains to the minimum value
 * that an unsigned size can take, typically zero.
 *
 * It is synonymous with LIQUID_UINTPTR_MIN, indicating it uses
 * the lowest possible addressable memory size represented with uintptr_t,
 * ensuring consistent interpretation across various parts of a system.
 *
 * It is crucial in scenarios where size underflows
 * (dropping below zero) need to be prevented.
 */
#define LIQUID_USIZE_MIN LIQUID_UPTR_MIN

/**
 * @def LIQUID_USIZE_MAX
 * @brief Macro to define a maximum size
 *        for the liquid handling in unsigned memory operations.
 *
 * This macro is an alias for LIQUID_UINTPTR_MAX,
 * representing the maximum valid size value that
 * can be assigned or dealt with in memory sizing.
 *
 * It matches the highest value storable in an uintptr_t,
 * which is crucial for avoiding overflows in memory allocations
 * and ensuring maximum use of available memory without exceeding
 * system-defined limits.
 *
 * This macro helps manage and check the boundary conditions during memory
 * intense operations, such as buffer sizes or large data set manipulations.
 */
#define LIQUID_USIZE_MAX LIQUID_UPTR_MAX

/**
 * @typedef usize_t
 * @brief Unsigned integer type used for size,
 *        based on the system's pointer size.
 *
 * This type is intended to be used in places where the object sizes or counts
 * need to be represented, matching the pointer size to efficiently utilize
 * the architectural capabilities and optimize memory alignment and access.
 */
typedef uptr_t usize_t;

#endif // LIQUID_USIZE_H
