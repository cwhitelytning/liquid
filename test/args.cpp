#include <gtest/gtest.h>
#include <liquid/args.h>

/**
 * @brief Test concatenating numeric values.
 *
 * The test verifies if the LIQUID_ARGS_CONCAT macro
 * correctly concatenates pairs of integer values.
 *
 * @test
 * - Checks if 2 and 3 are concatenated to form 23.
 * - Checks if 4 and 56 are concatenated to form 456.
 * - Checks if 78 and 90 are concatenated to form 7890.
 */
TEST(args, concating_numeric_values)
{
    EXPECT_EQ(23, LIQUID_ARGS_CONCAT(2, 3));
    EXPECT_EQ(456, LIQUID_ARGS_CONCAT(4, 56));
    EXPECT_EQ(7890, LIQUID_ARGS_CONCAT(78, 90));
}

/**
 * @brief Test converting numeric values to strings.
 *
 * Verifies the functionality of LIQUID_ARG_STRINGIFY and LIQUID_ARGS_STRINGIFY
 * macros by checking their output against expected string literals.
 *
 * @test
 * - Converts single values (1, 100, -10) to their string representations.
 * - Converts multiple values (1, 2, 3), (a, b, c), (10, 20, 30) to string
 *   representations formatted as tuples.
 */
TEST(args, converting_numeric_values_to_strings)
{
    EXPECT_STREQ("1", LIQUID_ARG_STRINGIFY(1));
    EXPECT_STREQ("100", LIQUID_ARG_STRINGIFY(100));
    EXPECT_STREQ("-10", LIQUID_ARG_STRINGIFY(-10));

    EXPECT_STREQ("(1, 2, 3)", LIQUID_ARGS_STRINGIFY(1, 2, 3));
    EXPECT_STREQ("(a, b, c)", LIQUID_ARGS_STRINGIFY(a, b, c));
    EXPECT_STREQ("(10, 20, 30)", LIQUID_ARGS_STRINGIFY(10, 20, 30));
}
