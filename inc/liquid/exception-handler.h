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
 * @typedef usize_t(exception_handler_fn)(const errmsg_t message, usize_t len)
 * @brief A type definition for a function pointer
 *        that represents an exception handler.
 *
 * @param message The error message associated with the exception.
 * @param len The length of the error message.
 * @return The length of the message that was processed by the handler,
 *         analogous to the return value of fwrite.
 *
 * @note This handler function is intended to process an exception
 *       and return the length of the message that was handled.
 *
 *       It is similar in behavior to the fwrite function,
 *       which returns the number of elements successfully written.
 */
typedef usize_t(exception_handler_fn)(const errmsg_t message, usize_t len);

#endif // LIQUID_EXCEPTION_HANDLER_H
