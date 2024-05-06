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

/**
 * @brief Include the exception handler definitions.
 */
#include "exception-handler.h"

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
