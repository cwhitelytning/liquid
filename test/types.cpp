#include <climits>
#include <gtest/gtest.h>
#include <liquid/limits.h>
#include <liquid/offset.h>
#include <liquid/ptr.h>
#include <liquid/usize.h>

/**
 * @brief Tests for compatibility between custom
 *        and standard integer types.
 *
 * This unit test ensures that the maximum and minimum values of custom integer
 * types are equivalent to their corresponding standard integer types.
 * The types tested include signed and unsigned integers of various sizes.
 *
 * @test
 * - Compares the max value of custom signed and unsigned integer types
 *   with their equivalent standard types using std::numeric_limits.
 *   Assertions used:
 *   @code
 *     ASSERT_EQ(std::numeric_limits<schar_t>::max(),
 *               std::numeric_limits<int8_t>::max());
 *     ASSERT_EQ(std::numeric_limits<sshort_t>::max(),
 *               std::numeric_limits<int16_t>::max());
 *     // Other similar comparisons for different types...
 *   @endcode
 *
 * - Compares the min value of custom signed and unsigned integer types
 *   with their equivalent standard types.
 *   Assertions used:
 *   @code
 *     ASSERT_EQ(std::numeric_limits<uchar_t>::min(),
 *               std::numeric_limits<uint8_t>::min());
 *     ASSERT_EQ(std::numeric_limits<ushort_t>::min(),
 *               std::numeric_limits<uint16_t>::min());
 *     // Other similar comparisons for different types...
 *   @endcode
 *
 */
TEST(types, base_types_is_std_compatible)
{
    // Testing max values compatibility.
    ASSERT_EQ(std::numeric_limits<schar_t>::max(),
              std::numeric_limits<int8_t>::max());
    ASSERT_EQ(std::numeric_limits<sshort_t>::max(),
              std::numeric_limits<int16_t>::max());
    ASSERT_EQ(std::numeric_limits<sint_t>::max(),
              std::numeric_limits<int32_t>::max());
    ASSERT_EQ(std::numeric_limits<sllong_t>::max(),
              std::numeric_limits<int64_t>::max());

    // Testing min values compatibility.
    ASSERT_EQ(std::numeric_limits<schar_t>::min(),
              std::numeric_limits<int8_t>::min());
    ASSERT_EQ(std::numeric_limits<sshort_t>::min(),
              std::numeric_limits<int16_t>::min());
    ASSERT_EQ(std::numeric_limits<sint_t>::min(),
              std::numeric_limits<int32_t>::min());
    ASSERT_EQ(std::numeric_limits<sllong_t>::min(),
              std::numeric_limits<int64_t>::min());

    // Testing max values compatibility for unsigned types.
    ASSERT_EQ(std::numeric_limits<uchar_t>::max(),
              std::numeric_limits<uint8_t>::max());
    ASSERT_EQ(std::numeric_limits<ushort_t>::max(),
              std::numeric_limits<uint16_t>::max());
    ASSERT_EQ(std::numeric_limits<uint_t>::max(),
              std::numeric_limits<uint32_t>::max());
    ASSERT_EQ(std::numeric_limits<ullong_t>::max(),
              std::numeric_limits<uint64_t>::max());

    // Testing min values compatibility for unsigned types.
    ASSERT_EQ(std::numeric_limits<uchar_t>::min(),
              std::numeric_limits<uint8_t>::min());
    ASSERT_EQ(std::numeric_limits<ushort_t>::min(),
              std::numeric_limits<uint16_t>::min());
    ASSERT_EQ(std::numeric_limits<uint_t>::min(),
              std::numeric_limits<uint32_t>::min());
    ASSERT_EQ(std::numeric_limits<ullong_t>::min(),
              std::numeric_limits<uint64_t>::min());
}

/**
 * @brief Test suite for verifying compatibility of custom-defined numeric
 *        limits with the standard limits in <climits>.
 *
 * This test suite verifies that the constants defined in some custom
 * implementation (presumably in a header that defines LIQUID_UCHAR_MAX,
 * LIQUID_USHORT_MAX, etc.) are equivalent to the corresponding limits
 * defined in the C++ standard library (<climits>).
 *
 * @test
 * - Check if the maximum values for unsigned types defined by the custom
 *   implementation match the standard maximum values (UINT8_MAX, UINT16_MAX,
 *   UINT32_MAX, UINT64_MAX).
 * - Verify if the minimum values for signed types defined by the custom
 *   implementation match the standard minimum values (INT8_MIN, INT16_MIN,
 *   INT32_MIN, INT64_MIN).
 * - Check if the maximum values for signed types defined by the custom
 *   implementation match the standard maximum values (INT8_MAX, INT16_MAX,
 *   INT32_MAX, INT64_MAX).
 *
 * @note This test assumes that the relevant macros (e.g., LIQUID_UCHAR_MAX) are
 *       correctly defined in the concerned custom headers or configurations.
 */
TEST(types, base_limits_is_std_compatible)
{
    EXPECT_EQ(0, LIQUID_UCHAR_MIN);
    EXPECT_EQ(0, LIQUID_USHORT_MIN);
    EXPECT_EQ(0, LIQUID_UINT_MIN);
    EXPECT_EQ(0, LIQUID_ULLONG_MIN);

    EXPECT_EQ(UINT8_MAX, LIQUID_UCHAR_MAX);
    EXPECT_EQ(UINT16_MAX, LIQUID_USHORT_MAX);
    EXPECT_EQ(UINT32_MAX, LIQUID_UINT_MAX);
    EXPECT_EQ(UINT64_MAX, LIQUID_ULLONG_MAX);

    EXPECT_EQ(INT8_MIN, LIQUID_SCHAR_MIN);
    EXPECT_EQ(INT16_MIN, LIQUID_SSHORT_MIN);
    EXPECT_EQ(INT32_MIN, LIQUID_SINT_MIN);
    EXPECT_EQ(INT64_MIN, LIQUID_SLLONG_MIN);

    EXPECT_EQ(INT8_MAX, LIQUID_SCHAR_MAX);
    EXPECT_EQ(INT16_MAX, LIQUID_SSHORT_MAX);
    EXPECT_EQ(INT32_MAX, LIQUID_SINT_MAX);
    EXPECT_EQ(INT64_MAX, LIQUID_SLLONG_MAX);
}

/**
 * @brief Test pointer type standards compatibility.
 *
 * This test ensures that the minimum and maximum values of signed and unsigned
 * pointers within the Liquid library align with those of the standard C++
 * integer pointer types.
 *
 * @test
 * - Verify that the minimum and maximum values of signed pointer types are
 *   compatible between standard intptr_t and LIQUID_SPTR defined
 *   in the Liquid library.
 * - Check that the minimum and maximum values of unsigned pointer types are
 *   compatible between standard uintptr_t and LIQUID_UPTR defined
 *   in the Liquid library.
 */
TEST(types, ptr_is_std_compatible)
{
    // Verify that the system's intptr_t minimum
    // is equal to Liquid's LIQUID_SPTR_MIN
    EXPECT_EQ(INTPTR_MIN, LIQUID_SPTR_MIN);

    // Verify that the system's intptr_t maximum
    // is equal to Liquid's LIQUID_SPTR_MAX
    EXPECT_EQ(INTPTR_MAX, LIQUID_SPTR_MAX);

    // Verify that Liquid defines
    // the minimum unsigned pointer value as 0
    EXPECT_EQ(0, LIQUID_UPTR_MIN);

    // Verify that the system's uintptr_t maximum
    // is equal to Liquid's LIQUID_UPTR_MAX
    EXPECT_EQ(UINTPTR_MAX, LIQUID_UPTR_MAX);
}

/**
 * @test Test the compatibility of custom-defined offset values
 *       with standard C++ data types.
 *
 * This test case checks the predefined offset values against standard limits of
 * uintptr_t for unsigned offsets and intptr_t for signed offsets. The purpose
 * is to ensure that the range of these offsets covers the whole range of the
 * respective standard types.
 *
 * @subtest This subtest verifies that the minimum value for an unsigned offset
 *          is zero, which is compatible with the standard definition of
 *          uintptr_t minimum value.
 *
 * - EXPECT_EQ(0, LIQUID_UOFFSET_MIN)
 *
 * @subtest This subtest checks that the maximum value for an unsigned offset
 *          is equivalent to the maximum value of uintptr_t,
 *          ensuring the upper bound compatibility.
 *
 * - EXPECT_EQ(UINTPTR_MAX, LIQUID_UOFFSET_MAX)
 *
 * @subtest This subtest checks the minimum value for a signed offset
 *          against the minimum limit of intptr_t,
 *          confirming the lower bound compatibility.
 *
 * - EXPECT_EQ(INTPTR_MIN, LIQUID_SOFFSET_MIN)
 *
 * @subtest This subtest verifies that the maximum value for a signed offset is
 *          the same as the maximum value allowed by intptr_t,
 *          securing its upper limit compatibility.
 *
 * - EXPECT_EQ(INTPTR_MAX, LIQUID_SOFFSET_MAX)
 */
TEST(types, offset_is_std_compatible)
{
    EXPECT_EQ(0, LIQUID_UOFFSET_MIN);
    EXPECT_EQ(UINTPTR_MAX, LIQUID_UOFFSET_MAX);

    EXPECT_EQ(INTPTR_MIN, LIQUID_SOFFSET_MIN);
    EXPECT_EQ(INTPTR_MAX, LIQUID_SOFFSET_MAX);
}

/**
 * @brief Test to ensure that the custom type usize
 *        is compatible with the standard size type.
 *
 * This test case checks that the minimum value of usize
 * is zero and that the maximum value of usize matches
 * the maximum value of the standard size_t type.
 *
 * @test
 * - LIQUID_USIZE_MIN should equal 0.
 * - LIQUID_USIZE_MAX should equal SIZE_MAX,
 *                    the maximum value for size_t.
 */
TEST(types, usize_is_std_compatible)
{
    EXPECT_EQ(0, LIQUID_USIZE_MIN);
    EXPECT_EQ(SIZE_MAX, LIQUID_USIZE_MAX);
}