#include <gtest/gtest.h>
#include <liquid/os.h>

/**
 * @brief Test case for setting the last error code.
 *
 * This test verifies the behavior of the `set_last_error_code`
 * function by setting the last error code to 0
 * and then checking if it was properly set.
 *
 * @param os Test case name.
 * @param set_last_error_code Name of the test case function.
 */
TEST(os, set_last_error_code)
{
    set_last_error_code(0);
    EXPECT_EQ(last_error_code(), 0);

    set_last_error_code(14);
    EXPECT_EQ(last_error_code(), 14);
}