#include <gtest/gtest.h>
#include <liquid/array-raw.h>

/**
 * @test Test case for successful raw copy of an array.
 *
 * This test verifies that the array_raw_copy function can successfully copy
 * a C-style string from a source to a destination array.
 */
TEST(array_raw_copy, successful_copy)
{
    char src[] = "Test string";
    char dest[50];

    auto  size = ARRAY_RAW_SIZE(src);
    auto *result = array_raw_copy(dest, src, size);

    EXPECT_EQ(dest + size, result);
    EXPECT_STREQ(src, dest);
}

/**
 * @test Test case for self-copy error condition.
 *
 * This test ensures that the array_raw_copy function returns a nullptr
 * when attempting to copy an array onto itself, which is an error condition.
 */
TEST(array_raw_copy, self_copy_error)
{
    char buffer[] = "Test string";
    auto size = ARRAY_RAW_SIZE(buffer);

    EXPECT_EQ(array_raw_copy(buffer, buffer, size), nullptr);
}

/**
 * @test Test case for null pointer parameters.
 *
 * This test checks that the array_raw_copy function returns a nullptr
 * when either the source or destination pointers are null.
 */
TEST(array_raw_copy, dest_or_src_is_nullptr)
{
    char    src[] = "Test string";
    usize_t n = ARRAY_RAW_SIZE(src);

    EXPECT_EQ(array_raw_copy(nullptr, src, n), nullptr);
    EXPECT_EQ(array_raw_copy(src, nullptr, n), nullptr);
}

/**
 * @test Test case for finding a value within an array.
 *
 * This test verifies that the array_raw_pos function can successfully find
 * the position of a given value within an array.
 */
TEST(array_raw_copy, find_value)
{
    uchar_t array[] = {1, 2, 3, 4, 5};
    uchar_t value = 3;

    const auto *result = array_raw_pos(array, array + 5, value);
    EXPECT_EQ(array + 2, result);
}

/**
 * @test Test case for value not found within an array.
 *
 * This test ensures that the array_raw_pos function returns nullptr
 * when the specified value is not found within the array.
 */
TEST(array_raw_copy, value_not_found)
{
    uchar_t array[] = {1, 2, 3, 4, 5};
    uchar_t value = 6;

    const auto *result = array_raw_pos(array, array + 5, value);
    EXPECT_EQ(nullptr, result);
}

/**
 * @test Test case for an empty range within an array.
 *
 * This test checks that the array_raw_pos function returns nullptr
 * when the range specified is empty, meaning there is no valid range to search.
 */
TEST(array_raw_copy, empty_range)
{
    uchar_t array[] = {1, 2, 3, 4, 5};
    uchar_t value = 1;

    const auto *result = array_raw_pos(array, array, value);
    EXPECT_EQ(nullptr, result);
}

/**
 * @test Test case for array_raw_compare with equal arrays.
 *
 * This test case checks if the array_raw_compare function returns nullptr
 * when comparing two identical arrays, indicating that they are equal.
 */
TEST(array_raw_compare, equal_arrays)
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};

    const void *result =
        array_raw_compare(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]), arr2,
                          arr2 + sizeof(arr2) / sizeof(arr2[0]));

    EXPECT_EQ(result, nullptr);
}

/**
 * @test Test case for array_raw_compare with different arrays.
 *
 * This test case checks if the array_raw_compare function returns a pointer
 * to the first differing element when comparing two arrays that differ at
 * one position.
 */
TEST(array_raw_compare, different_arrays)
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 6};

    const void *result =
        array_raw_compare(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]), arr2,
                          arr2 + sizeof(arr2) / sizeof(arr2[0]));

    EXPECT_EQ(result, arr1 + 4);
}

/**
 * @test Test case for array_raw_compare with arrays of different lengths.
 *
 * This test case checks if the array_raw_compare function returns nullptr
 * when comparing two arrays of different lengths,
 * indicating that they cannot be equal.
 */
TEST(array_raw_compare, different_length_arrays)
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3};

    const void *result =
        array_raw_compare(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]), arr2,
                          arr2 + sizeof(arr2) / sizeof(arr2[0]));

    EXPECT_EQ(result, nullptr);
}

/**
 * @test Test case for array_raw_compare with empty arrays.
 *
 * This test case checks if the array_raw_compare function returns nullptr
 * when comparing two empty arrays, indicating that they are trivially equal.
 */
TEST(array_raw_compare, empty_arrays)
{
    int arr1[] = {};
    int arr2[] = {};

    const void *result = array_raw_compare(arr1, arr1, arr2, arr2);
    EXPECT_EQ(result, nullptr);
}