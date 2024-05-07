#include <gtest/gtest.h>
#include <liquid/args.h>
#include <liquid/exception.h>
#include <liquid/str.h>

std::string buffer;

/**
 * @brief Test case for exception raising with a custom message.
 *
 * This test verifies that the custom exception handler correctly processes
 * an error message and compares the expected outcomes with the actual results.
 *
 * @test Tests the `exception_set_handler` function's ability to handle a custom
 *       message. It sets a custom exception handler that appends the message
 *       to a buffer, excluding the null terminator, and then returns the new
 *       size of the buffer.
 *
 *       The test then raises an exception
 *       with a test message and checks two conditions:
 *
 *       1. The return value of `LIQUID_EXCEPTION_RAISE`
 *          is equal to the raw size of the test message.
 *       2. The content of the buffer is equal to the test message.
 */
TEST(exception, raise_message)
{
    // Test message to be used for raising the exception.
    const char test_message[] = "Test message";

    // Setting a custom exception handler.
    exception_set_handler(
        [](const errmsg_t message, usize_t len) -> usize_t
        {
            // Clearing the buffer.
            buffer.clear();
            // Appending the message to the buffer and returning its new size.
            buffer.append(message, len - 1);
            return buffer.size();
        });

    // Expecting the exception raise to return the size of the test message.
    EXPECT_EQ(LIQUID_EXCEPTION_RAISE(test_message), STR_RAW_SIZE(test_message));

    // Expecting the buffer to contain the test message.
    EXPECT_STREQ(buffer.c_str(), test_message);
}

TEST(exception, raise_message_with_args)
{
    exception_set_handler(
        [](const errmsg_t message, usize_t len) -> usize_t
        {
            buffer.clear();
            buffer.append(message, len - 1);
            return buffer.size();
        });

    LIQUID_EXCEPTION_RAISE(LIQUID_ARGS_STRINGIFY(args : 1 2 3 4 5 6 7 8 9 10));
    EXPECT_STREQ(buffer.c_str(), "args : 1 2 3 4 5 6 7 8 9 10");
}