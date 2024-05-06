/**
 * @file limits.h
 * @brief Defines macros to calculate the maximum
 *        and minimum values for signed and unsigned integer types.
 */

#ifndef LIQUID_LIMITS_H
#define LIQUID_LIMITS_H

#include "bitflag.h"
#include "int.h"

/**
 * @def LIQUID_SCHAR_MIN
 * @brief Minimum value for a signed 8-bit integer type.
 */
#define LIQUID_SCHAR_MIN BITFLAG_MIN_INT(schar_t)

/**
 * @def LIQUID_SCHAR_MAX
 * @brief Maximum value for a signed 8-bit integer type.
 */
#define LIQUID_SCHAR_MAX BITFLAG_MAX_INT(schar_t)

/**
 * @def LIQUID_SSHORT_MIN
 * @brief Minimum value for a signed 16-bit integer type.
 */
#define LIQUID_SSHORT_MIN BITFLAG_MIN_INT(sshort_t)

/**
 * @def LIQUID_SSHORT_MAX
 * @brief Maximum value for a signed 16-bit integer type.
 */
#define LIQUID_SSHORT_MAX BITFLAG_MAX_INT(sshort_t)

/**
 * @def LIQUID_SINT_MIN
 * @brief Minimum value for a signed 32-bit integer type.
 */
#define LIQUID_SINT_MIN BITFLAG_MIN_INT(sint_t)

/**
 * @def LIQUID_SINT_MAX
 * @brief Maximum value for a signed 32-bit integer type.
 */
#define LIQUID_SINT_MAX BITFLAG_MAX_INT(sint_t)

/**
 * @def LIQUID_SLLONG_MIN
 * @brief Minimum value for a signed 64-bit integer type.
 */
#define LIQUID_SLLONG_MIN BITFLAG_MIN_INT(sllong_t)

/**
 * @def LIQUID_SLLONG_MAX
 * @brief Maximum value for a signed 64-bit integer type.
 */
#define LIQUID_SLLONG_MAX BITFLAG_MAX_INT(sllong_t)

/**
 * @def LIQUID_UCHAR_MIN
 * @brief Minimum value for an unsigned 8-bit integer type.
 */
#define LIQUID_UCHAR_MIN BITFLAG_MIN_UINT(uchar_t)

/**
 * @def LIQUID_UCHAR_MAX
 * @brief Maximum value for an unsigned 8-bit integer type.
 */
#define LIQUID_UCHAR_MAX BITFLAG_MAX_UINT(uchar_t)

/**
 * @def LIQUID_USHORT_MIN
 * @brief Minimum value for an unsigned 16-bit integer type.
 */
#define LIQUID_USHORT_MIN BITFLAG_MIN_UINT(ushort_t)

/**
 * @def LIQUID_USHORT_MAX
 * @brief Maximum value for an unsigned 16-bit integer type.
 */
#define LIQUID_USHORT_MAX BITFLAG_MAX_UINT(ushort_t)

/**
 * @def LIQUID_UINT_MIN
 * @brief Minimum value for an unsigned 32-bit integer type.
 */
#define LIQUID_UINT_MIN BITFLAG_MIN_UINT(uint_t)

/**
 * @def LIQUID_UINT_MAX
 * @brief Maximum value for an unsigned 32-bit integer type.
 */
#define LIQUID_UINT_MAX BITFLAG_MAX_UINT(uint_t)

/**
 * @def LIQUID_ULLONG_MIN
 * @brief Minimum value for an unsigned 64-bit integer type.
 */
#define LIQUID_ULLONG_MIN BITFLAG_MIN_UINT(ullong_t)

/**
 * @def LIQUID_ULLONG_MAX
 * @brief Maximum value for an unsigned 64-bit integer type.
 */
#define LIQUID_ULLONG_MAX BITFLAG_MAX_UINT(ullong_t)

#endif // LIQUID_LIMITS_H