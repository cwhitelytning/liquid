/**
 * @file conditional.h
 * @brief Conditional macros for the Liquid project.
 *
 * This header file defines macros for conditional execution of actions
 * based on the evaluation of expressions. These macros simplify control
 * flow in the code where they are used.
 */

#ifndef LIQUID_CONDITIONAL_H
#define LIQUID_CONDITIONAL_H

/**
 * @def LIQUID_CONDITIONAL(expr, exec)
 * @brief Executes an action if the expression evaluates to true.
 *
 * This macro checks if the given expression evaluates to true
 * and if so, executes the specified action.
 *
 * @param expr The expression to evaluate.
 * @param exec The action to execute if the expression is true.
 */
#define LIQUID_CONDITIONAL(expr, exec)                                         \
    if (expr)                                                                  \
    {                                                                          \
        exec                                                                   \
    }

/**
 * @def LIQUID_CONDITIONAL_IF(expr, action)
 * @brief A convenience wrapper for LIQUID_CONDITIONAL.
 *
 * This macro is a shorthand for LIQUID_CONDITIONAL, making the code
 * more readable by clearly indicating the intent of a conditional action.
 *
 * @param expr The expression to evaluate.
 * @param exec The action to execute if the expression is true.
 */
#define LIQUID_CONDITIONAL_IF(expr, exec) LIQUID_CONDITIONAL((expr), exec)

/**
 * @def LIQUID_CONDITIONAL_IF_NOT(expr, action)
 * @brief Executes an action if the expression evaluates to false.
 *
 * This macro inverts the logic of LIQUID_CONDITIONAL, executing the
 * specified action only if the expression evaluates to false.
 *
 * @param expr The expression to evaluate.
 * @param exec The action to execute if the expression is false.
 */
#define LIQUID_CONDITIONAL_IF_NOT(expr, exec) LIQUID_CONDITIONAL(!(expr), exec)

#endif // LIQUID_CONDITIONAL_H
