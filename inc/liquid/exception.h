/**
 * @file exception.h
 * @brief Exception handling utilities for the Liquid library.
 *
 * Provides macros and functions for raising and handling exceptions.
 * This file includes conditional checks and exception handling mechanisms
 * that can be used throughout the Liquid project.
 */

#ifndef LIQUID_EXCEPTION_H
#define LIQUID_EXCEPTION_H

#include "array-raw.h"
#include "conditional.h"
#include "exception-handler.h"

/**
 * @def LIQUID_EXCEPTION_RAISE(msg)
 * @brief Raise an exception with a given message.
 * @param msg The error message to be used when raising the exception.
 */
#define LIQUID_EXCEPTION_RAISE(msg) exception_raise(msg, ARRAY_RAW_SIZE(msg))

/**
 * @def LIQUID_EXCEPTION_RAISE_IF(expr, ret, msg)
 * @brief Raise an exception if a condition is true and return a value.
 * @param expr The condition to evaluate.
 * @param ret The value to return if the condition is true.
 * @param msg The error message to be used when raising the exception.
 */
#define LIQUID_EXCEPTION_RAISE_IF(expr, ret, msg)                              \
    LIQUID_CONDITIONAL_IF(expr, LIQUID_EXCEPTION_RAISE(msg); return ret;)

/**
 * @def LIQUID_EXCEPTION_RAISE_IF_NOT(expr, ret, msg)
 * @brief Raise an exception if a condition is false and return a value.
 * @param expr The condition to evaluate.
 * @param ret The value to return if the condition is false.
 * @param msg The error message to be used when raising the exception.
 */
#define LIQUID_EXCEPTION_RAISE_IF_NOT(expr, ret, msg)                          \
    LIQUID_CONDITIONAL_IF_NOT(expr, LIQUID_EXCEPTION_RAISE(msg); return ret;)

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/**
 * @brief Raise an exception with a specific message and length.
 * @param message The error message.
 * @param len The length of the error message.
 */
void
exception_raise(const errmsg_t message, usize_t len);

/**
 * @brief Set a new exception handler.
 * @param handler A pointer to the function that will handle exceptions.
 */
void
exception_set_handler(exception_handler_fn *handler);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LIQUID_EXCEPTION_H
