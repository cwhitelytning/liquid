/**
 * @file exception-handler.h
 * @brief Exception handler interface for the Liquid project.
 *
 * This header defines the exception handler function type for the Liquid
 * project. It is used to handle exceptions by providing a custom message
 * and the length of that message.
 */

#ifndef LIQUID_EXCEPTION_HANDLER_H
#define LIQUID_EXCEPTION_HANDLER_H

#include "os.h"

/**
 * @typedef exception_handler_fn
 * @brief Function pointer type for exception handling.
 *
 * This function pointer is used to reference a custom exception handler
 * function. The function will receive an error message and its length
 * as parameters.
 *
 * @param message The error message to be handled.
 * @param len The length of the error message.
 */
typedef void(exception_handler_fn)(const errmsg_t message, usize_t len);

#endif // LIQUID_EXCEPTION_HANDLER_H
