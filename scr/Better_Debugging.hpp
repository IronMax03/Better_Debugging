#ifndef BETTER_DEBUGGING
#define BETTER_DEBUGGING

// imports
#include <iostream>

// colors
#ifndef ERROR_COLOR
    #define ERROR_COLOR  "\033[31m"
#endif
#ifndef DEBUG_COLOR
    #define DEBUG_COLOR  "\033[33m"
#endif
#ifndef RESET_COLOR
    #define RESET_COLOR   "\033[0m"
#endif

/**
 * Logs a message with a given label and optional content, regardless of `DEBUG_MODE`.
 * This method is not intended to be directly used.
 * 
 * @param name      The label for the message (e.g., "Initialization").
 * @param messages  The message content (optional).
 */
static void Debug_Message(std::string name, std::string messages);

/**
 * Logs a error with a given label and optional content, regardless of `DEBUG_MODE`.
 * This method is not intended to be directly used.
 * 
 * @param name      The label for the message (e.g., "Initialization").
 * @param messages  The message content (optional).
 */
static void Error_Message(std::string name, std::string messages);

/**
 * Logs the variable's name, old value, new value, and address. Returns the new value.
 * This method is not intended to be directly used. Use VAR_ASSIGNMENT instead.
 * 
 * @param var        The current value of the variable.
 * @param newValue   The new value to assign.
 * @param varName    The name of the variable.
 * @param adresse    The address of the variable.
 * 
 * @return           The new value assigned to the variable.
 */
static std::string Debug_Var_Assign(std::string var, std::string newValue, std::string varName, std::string* adresse);

/**
 * Logs the variable's name, old value, new value, and address. Returns the new value.
 * This method is not intended to be directly used. Use VAR_ASSIGNMENT instead.
 * 
 * @param var        The current value of the variable.
 * @param newValue   The new value to assign.
 * @param varName    The name of the variable.
 * @param adresse    The address of the variable.
 * 
 * @return           The new value assigned to the variable.
 */
static int Debug_Var_Assign(int  var, int newValue, std::string varName, int* adresse);

/**
 * If values don't match, logs an error and throws an exception. Logs success if equal (in `DEBUG_MODE`).
 * 
 * @param expected  The expected std::string value.
 * @param given     The actual std::string value.
 * @param message   An optional message.
 */
static void assertPP(std::string expected, std::string given, std::string message);

/**
 * If values don't match, logs an error and throws an exception. Logs success if equal (in `DEBUG_MODE`).
 * 
 * @param expected  The expected std::string value.
 * @param given     The actual std::string value.
 * @param message   An optional message.
 */
static void assertPP(int expected, int given, std::string message);

#ifdef DEBUG_MODE
 
    /**
    * VAR_ASSIGNMENT(oldVar, newVar) - Wraps variable assignment with debugging. Logs the assignment.
    * @param oldVar Variable being assigned.
    * @param newVar New value to assign.
    */
    #define VAR_ASSIGNMENT(currentVar, newVar) ((currentVar) = Debug_Var_Assign((currentVar), (newVar), (#currentVar), (&currentVar)))

    /**
    * ASSERT(v, ev) - Checks if `v` satisfies `ev`. Logs the variable name and condition in case of failure.
    * @param v  Variable to assert.
    * @param ev Expected value or condition.
    */
    #define ASSERT(v, ev) assertPP(v, ev, #v)
    #define DEBUG_LOG(name, message) Debug_Message(name, message)

#else // Non-debug mode

    #define VAR_ASSIGNMENT(currentVar, newVar) currentVar = newVar  // Direct assignment without debugging.
    #define ASSERT(v, ev)  // Empty, no assertions in non-debug mode.
    #define DEBUG_LOG(name, message)

#endif
#endif // #ifndef BETTER_DEBUGGING
