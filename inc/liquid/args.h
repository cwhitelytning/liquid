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
 * @def LIQUID_ARG_STRINGIFY(x)
 * @brief Converts an argument to a string literal.
 *
 * This macro converts a preprocessor argument to a string literal.
 * It is useful for creating string representations of macro values.
 *
 * @param x The argument to stringify.
 * @return The string literal of the argument.
 */
#define LIQUID_ARG_STRINGIFY(x) #x

/**
 * @def LIQUID_ARGS_STRINGIFY(...)
 * @brief Converts multiple arguments to a string literal.
 *
 * This macro converts multiple preprocessor arguments to a single
 * string literal, after they are passed as a single argument to
 * LIQUID_ARG_STRINGIFY.
 *
 * @param ... The arguments to stringify.
 * @return The string literal of the arguments.
 */
#define LIQUID_ARGS_STRINGIFY(...) LIQUID_ARG_STRINGIFY((__VA_ARGS__))

#endif // LIQUID_ARGS_H
