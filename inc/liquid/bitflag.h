/**
 * @file bitflag.h
 * @brief Utility macros for performing bit operations.
 */

#ifndef LIQUID_BITFLAG_H
#define LIQUID_BITFLAG_H

/**
 * @brief Sets the bits specified by mask v in variable x.
 *
 * @param x The variable whose bits are to be modified.
 * @param v The bit mask specifying which bits to set.
 * @return The new value of x with the specified bits set.
 */
#define BITFLAG_SET(x, v) ((x) | (v))

/**
 * @brief Checks if any bits specified by mask v are set in variable x.
 *
 * @param x The variable to check.
 * @param v The bit mask specifying which bits to check.
 * @return Non-zero if any of the specified bits are set, zero otherwise.
 */
#define BITFLAG_CHECK(x, v) ((x) & (v))

/**
 * @brief Clears the bits specified by mask v in variable x.
 *
 * @param x The variable whose bits are to be cleared.
 * @param v The bit mask specifying which bits to clear.
 * @return The new value of x with the specified bits cleared.
 */
#define BITFLAG_CLEAR(x, v) ((x) & ~(v))

/**
 * @brief Toggles the bits specified by mask v in variable x.
 *
 * @param x The variable whose bits are to be toggled.
 * @param v The bit mask specifying which bits to toggle.
 * @return The new value of x with the specified bits toggled.
 */
#define BITFLAG_TOGGLE(x, v) ((x) ^ (v))

/**
 * @brief Sets a bit at index i in variable x.
 *
 * @param x The variable whose bit is to be set.
 * @param i The index of the bit to set.
 */
#define BITFLAG_SET_BY_INDEX(x, i) ((x) |= (1ULL << (i)))

/**
 * @brief Clears a bit at index i in variable x.
 *
 * @param x The variable whose bit is to be cleared.
 * @param i The index of the bit to clear.
 */
#define BITFLAG_CLEAR_BY_INDEX(x, i) ((x) &= ~(1ULL << (i)))

/**
 * @brief Toggles a bit at index i in variable x.
 *
 * @param x The variable whose bit is to be toggled.
 * @param i The index of the bit to toggle.
 */
#define BITFLAG_TOGGLE_BY_INDEX(x, i) ((x) ^= (1ULL << (i)))

/**
 * @brief Checks if a bit at index i is set in variable x.
 *
 * @param x The variable to check.
 * @param i The index of the bit to check.
 * @return Non-zero if the specified bit is set, zero otherwise.
 */
#define BITFLAG_CHECK_BY_INDEX(x, i) ((x) & (1ULL << (i)))

/**
 * @brief Changes a bit at index i in variable x to n.
 *
 * @param x The variable whose bit is to be changed.
 * @param i The index of the bit to change.
 * @param n The new value for the bit (0 or 1).
 */
#define BITFLAG_CHANGE_BY_INDEX(x, i, n)                                       \
    ((x) = ((x) & ~(1ULL << (i))) | ((n) << (i)))

/**
 * @brief Gets a byte at index i from variable x.
 *
 * @param x The variable to extract the byte from.
 * @param i The index of the byte to extract.
 * @return The extracted byte.
 */
#define BITFLAG_GET_BYTE_BY_INDEX(x, i) (((x) >> (8 * (i))) & 0xFF)

/**
 * @brief Sets a byte at index i in variable x to n.
 *
 * @param x The variable whose byte is to be set.
 * @param i The index of the byte to set.
 * @param n The value to set the byte to.
 */
#define BITFLAG_SET_BYTE_BY_INDEX(x, i, n)                                     \
    ((x) = ((x) & ~(0xFFULL << (8 * (i)))) | ((n) << (8 * (i))))

/**
 * @brief Rotates the bits of x to the left n times.
 *
 * @param x The variable whose bits are to be rotated.
 * @param n The number of positions to rotate to the left.
 * @return The value of x after the bits have been rotated.
 */
#define BITFLAG_ROTATE_LEFT(x, n)                                              \
    (((x) << (n)) | ((x) >> (sizeof(x) * 8 - (n))))

/**
 * @brief Rotates the bits of x to the right n times.
 *
 * @param x The variable whose bits are to be rotated.
 * @param n The number of positions to rotate to the right.
 * @return The value of x after the bits have been rotated.
 */
#define BITFLAG_ROTATE_RIGHT(x, n)                                             \
    (((x) >> (n)) | ((x) << (sizeof(x) * 8 - (n))))

// -----------------------------------------------------------------------------
// Provides a set of bitflag definitions for easy access
// and manipulation of specific bits.
// -----------------------------------------------------------------------------
// Each BITFLAG_X macro corresponds to a specific bit in an integer.
// These macros can be used in bit manipulation operations such as setting,
// clearing, or toggling specific bits.
//
// The macros are named according to the bit they represent, so BITFLAG_0
// corresponds to the least significant bit (the "0th" bit), BITFLAG_1
// corresponds to the next bit, and so on, up to BITFLAG_31.
// -----------------------------------------------------------------------------

#define BITFLAG_0 (1 << 0)
#define BITFLAG_1 (1 << 1)
#define BITFLAG_2 (1 << 2)
#define BITFLAG_3 (1 << 3)
#define BITFLAG_4 (1 << 4)
#define BITFLAG_5 (1 << 5)
#define BITFLAG_6 (1 << 6)
#define BITFLAG_7 (1 << 7)
#define BITFLAG_8 (1 << 8)
#define BITFLAG_9 (1 << 9)
#define BITFLAG_10 (1 << 10)
#define BITFLAG_11 (1 << 11)
#define BITFLAG_12 (1 << 12)
#define BITFLAG_13 (1 << 13)
#define BITFLAG_14 (1 << 14)
#define BITFLAG_15 (1 << 15)
#define BITFLAG_16 (1 << 16)
#define BITFLAG_17 (1 << 17)
#define BITFLAG_18 (1 << 18)
#define BITFLAG_19 (1 << 19)
#define BITFLAG_20 (1 << 20)
#define BITFLAG_21 (1 << 21)
#define BITFLAG_22 (1 << 22)
#define BITFLAG_23 (1 << 23)
#define BITFLAG_24 (1 << 24)
#define BITFLAG_25 (1 << 25)
#define BITFLAG_26 (1 << 26)
#define BITFLAG_27 (1 << 27)
#define BITFLAG_28 (1 << 28)
#define BITFLAG_29 (1 << 29)
#define BITFLAG_30 (1 << 30)
#define BITFLAG_31 (1 << 31)

// -----------------------------------------------------------------------------
// The following macros are designed to compute the minimum and maximum values
// for integer data types. These macros employ bit manipulation techniques
// which are optimized for performance and can be used universally across
// various integer types.
//
// Bit manipulation is used due to its efficiency in computing bounds directly
// from the binary representations of integers, avoiding loops and condition
// checks.
// -----------------------------------------------------------------------------

/**
 * @def BITFLAG_MIN_INT(type)
 * @brief Macro to calculate the minimum value for a signed integer type.
 *        This is achieved by shifting a 1 to the left most position,
 *        turning it into the most negative number for that type
 *        (e.g., for int, it becomes 0x80000000).
 *
 * @param type The signed integer type
 *             for which to calculate the minimum value.
 *
 * @return The minimum value
 *         for the specified signed integer type.
 */
#define BITFLAG_MIN_INT(type) ((type)((type)1 << (sizeof(type) * 8 - 1)))

/**
 * @def BITFLAG_MAX_INT(type)
 * @brief Macro to calculate the maximum value for a signed integer type.
 *        This value is computed by inverting the minimum value,
 *        which sets all bits except the sign bit to 1
 *        (e.g., for int, it results in 0x7FFFFFFF).
 *
 * @param type The signed integer type
 *             for which to calculate the maximum value.
 *
 * @return The maximum value
 *         for the specified signed integer type.
 */
#define BITFLAG_MAX_INT(type) (~(type)(((type)1) << (sizeof(type) * 8 - 1)))

/**
 * @def BITFLAG_MAX_UINT(type)
 * @brief Macro to calculate the maximum value for an unsigned integer type.
 *        As unsigned types do not have a sign bit, all bits can be set to 1,
 *        which represents the maximum possible value for unsigned integers.
 *
 * @param type The unsigned integer type
 *             for which to calculate the maximum value.
 *
 * @return The maximum value
 *         for the specified unsigned integer type.
 */
#define BITFLAG_MAX_UINT(type) ((type)(-1))

/**
 * @def BITFLAG_MIN_UINT(type)
 * @brief Macro to calculate the minimum value for an unsigned integer type,
 *        which is always zero as all bits are set to 0.
 *
 * @param type The unsigned integer type
 *             for which to calculate the minimum value.
 *
 * @return The minimum value
 *         for the specified unsigned integer type.
 */
#define BITFLAG_MIN_UINT(type) ((type)0)

#endif /* LIQUID_BITFLAG_H */