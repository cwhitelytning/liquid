/**
 * @file exception.h
 * @brief Exception handling mechanisms for the Liquid library.
 *
 * This header file provides the interface for raising and handling exceptions
 * in the Liquid library. It allows setting custom exception handlers and
 * raising exceptions with or without additional arguments.
 */

#ifndef LIQUID_EXCEPTION_H
#define LIQUID_EXCEPTION_H

#include "conditional.h"
#include "exception-handler.h"

/**
 * @def LIQUID_EXCEPTION_RAISE_IF(expr, ret, ...)
 * @brief Raises an exception if the given expression is true.
 *
 * This macro checks if the expression (expr) is true. If it is, it raises an
 * exception with the provided arguments and returns the specified return value.
 *
 * @param expr The expression to evaluate.
 * @param ret The value to return if the expression is true.
 * @param ... The arguments to pass to the exception_raise function.
 */
#define LIQUID_EXCEPTION_RAISE_IF(expr, ret, ...)                              \
    LIQUID_CONDITIONAL_IF(expr, exception_raise(__VA_ARGS__); return ret;)

/**
 * @def LIQUID_EXCEPTION_RAISE_IF_NOT(expr, ret, ...)
 * @brief Raises an exception if the given expression is false.
 *
 * This macro checks if the expression (expr) is false. If it is, it raises an
 * exception with the provided arguments and returns the specified return value.
 *
 * @param expr The expression to evaluate.
 * @param ret The value to return if the expression is false.
 * @param ... The arguments to pass to the exception_raise function.
 */
#define LIQUID_EXCEPTION_RAISE_IF_NOT(expr, ret, ...)                          \
    LIQUID_CONDITIONAL_IF_NOT(expr, exception_raise(__VA_ARGS__); return ret;)

/**
 * @brief Raises an exception with variadic arguments.
 *
 * This function checks if a custom exception handler is set and, if so,
 * initializes a va_list to pass the variadic arguments to the handler.
 * It is a convenient way to raise exceptions with additional context
 * provided by the variadic arguments.
 *
 * @param message The error message associated with the exception.
 * @param ... Variadic arguments providing additional context for the exception.
 */
void
exception_raise(const errmsg_t message, ...);

/**
 * @brief Sets a new exception handler.
 *
 * This function sets a new exception handler and returns the previous one.
 * It allows for custom handling of exceptions throughout the Liquid library.
 *
 * @param handler A pointer to the new exception handler function.
 * @return A pointer to the previous exception handler function.
 */
exception_handler_fn *
exception_set_handler(exception_handler_fn *handler);

#endif // LIQUID_EXCEPTION_H
