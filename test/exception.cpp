#include <cstdio>
#include <gtest/gtest.h>
#include <liquid/exception.h>

std::string buffer;

TEST(exception, raise_message)
{
    exception_set_handler(
        [](const char *message, usize_t len)
        {
            buffer = message;
        });

    LIQUID_EXCEPTION_RAISE("Test message");
    EXPECT_STREQ(buffer.c_str(), "Test message");
}