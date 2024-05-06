/**
 * @file exception-handler.h
 * @brief Exception handler interface for the Liquid library.
 *
 * This header file defines the interface for exception handling in the Liquid
 * library. It includes the operating system specific configurations and
 * provides a typedef for a function pointer that is used as a callback for
 * handling exceptions with variadic arguments.
 */

#ifndef LIQUID_EXCEPTION_HANDLER_H
#define LIQUID_EXCEPTION_HANDLER_H

#include "os.h"
#include <stdarg.h>

/**
 * @typedef exception_handler_fn
 * @brief Function pointer type for error handling callbacks
 *        with variadic arguments.
 *
 * This type defines a pointer to a function that takes an error message and a
 * list of variadic arguments as input and does not return a value. It is used
 * by various components of the Liquid library to report and handle runtime
 * errors with additional context provided by the variadic arguments.
 *
 * @param message The error message to be handled.
 * @param args A pointer to a list of variadic arguments
 *             providing additional context.
 */
typedef void(exception_handler_fn)(const errmsg_t message, const va_list *args);

#endif // LIQUID_EXCEPTION_HANDLER_H
