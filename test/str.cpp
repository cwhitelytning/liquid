#include <gtest/gtest.h>
#include <liquid/str.h>

/**
 * @brief Test case for raw string copy
 *        without null-terminated char array.
 *
 * This test verifies the behavior of the `STR_RAW_CPY`
 * macro when copying a null-terminated char array into a buffer.
 *
 * @param str Test case name.
 * @param str_raw_cpy Name of the test case function.
 */
TEST(str, str_raw_cpy)
{
    // Buffer to copy the string into.
    char buf[1024] = {0};

    // Copy the string "hello" into the buffer.
    STR_RAW_CPY(buf, 1024, "hello");

    // Assert that the buffer contains the expected string.
    ASSERT_STREQ(buf, "hello");
}

/**
 * @brief Test case for raw string copy
 *        without null-terminated wide char array.
 *
 * This test verifies the behavior of the `WSTR_RAW_CPY`
 * macro when copying a null-terminated wide char array into a buffer.
 *
 * @param str Test case name.
 * @param wstr_raw_cpy Name of the test case function.
 */
TEST(str, wstr_raw_cpy)
{
    // Buffer to copy the wide string into.
    wchar_t buf[1024] = {0};

    // We fill the buffer with garbage so
    // that we can check the correctness
    // of inserting the null terminator.
    memset(buf, 0xF7, ARRAY_RAW_SIZE(buf));

    // Copy the wide string "hello, world" into the buffer.
    WSTR_RAW_CPY(buf, ARRAY_RAW_SIZE(buf), L"hello, world");

    // Assert that the buffer contains the expected wide string.
    ASSERT_STREQ(buf, L"hello, world");
}

/**
 * @brief Test case for string copy
 *        with null-terminated char array.
 *
 * This test verifies the behavior of the `STR_CPY`
 * function when copying a null-terminated char array into a buffer.
 *
 * @param str Test case name.
 * @param str_cpy Name of the test case function.
 */
TEST(str, str_cpy)
{
    // Buffer to copy the string into.
    char buf[1024];

    // We fill the buffer with garbage so
    // that we can check the correctness
    // of inserting the null terminator.
    memset(buf, 0x7F, ARRAY_RAW_SIZE(buf));

    // Copy the string into the buffer.
    auto last_ptr = STR_CPY(buf, ARRAY_RAW_SIZE(buf),
                            "Lorem Ipsum is simply dummy text of the printing "
                            "and typesetting industry.");

    // Assert that the return value indicates successful copying.
    ASSERT_EQ(LIQUID_PTR_DIFF(buf, last_ptr), 75);
}

/**
 * @brief Test case for string copy
 *        with null-terminated wide char array.
 *
 * This test verifies the behavior of the `WSTR_CPY`
 * function when copying a null-terminated wide char array into a buffer.
 *
 * @param str Test case name.
 * @param wstr_cpy Name of the test case function.
 */
TEST(str, wstr_cpy)
{
    // Buffer to copy the wide string into.
    wchar_t buf[1024];

    // Copy the wide string into the buffer.
    auto last_ptr =
        WSTR_CPY(buf, ARRAY_RAW_SIZE(buf),
                 L"Lorem Ipsum is simply dummy text of the printing "
                 "and typesetting industry.");

    // Assert that the return value indicates successful copying.
    ASSERT_EQ(LIQUID_PTR_DIFF(buf, last_ptr), 75);
}
