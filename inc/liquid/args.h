/**
 * @file args.h
 * @brief Utility macros for argument manipulation.
 *
 * This header defines preprocessor macros used for argument manipulation
 * and stringification within the codebase. These macros facilitate the
 * concatenation and conversion of macro arguments to string literals.
 */

#ifndef LIQUID_ARGS_H
#define LIQUID_ARGS_H

/**
 * @def LIQUID_ARGS_CONCAT(x, y)
 * @brief Concatenates two arguments.
 *
 * This macro concatenates two preprocessor arguments into a single token.
 * It is useful for combining two tokens at compile time.
 *
 * @param x The first argument to concatenate.
 * @param y The second argument to concatenate.
 *
 * @return The concatenated result of x and y.
 */
#define LIQUID_ARGS_CONCAT(x, y) x##y

/**
 * @def LIQUID_ARGS_STRINGIFY(...)
 * @brief Stringifies the given argument(s).
 *
 * This macro takes any number of arguments and uses the stringify operator
 * to turn them into a single string. This is useful for creating strings
 * out of tokens or macro values.
 *
 * @param ... Variable number of arguments to be stringified.
 * @return A string representation of the given arguments.
 */
#define LIQUID_ARGS_STRINGIFY(...) #__VA_ARGS__

#endif // LIQUID_ARGS_H
