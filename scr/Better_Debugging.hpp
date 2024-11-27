#ifndef BETTER_DEBUGGING
#define BETTER_DEBUGGING

// imports
#include <iostream>

// colors
#define ERROR_COLOR  "\033[31m"
#define DEBUG_COLOR  "\033[33m"
#define RESET_COLOR   "\033[0m"

using namespace std;

/**
 * Logs a message with a given label and optional content, regardless of `DEBUG_MODE`.
 * This method is not intended to be directly used.
 * 
 * @param name      The label for the message (e.g., "Initialization").
 * @param messages  The message content (optional).
 */
static void Debug_Message(string name, string messages = "");

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
static string Debug_Var_Assign(string var, string newValue, string varName, string* adresse);

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
static int Debug_Var_Assign(unsigned int  var, unsigned int newValue, string varName, unsigned int* adresse);

/**
 * If values don't match, logs an error and throws an exception. Logs success if equal (in `DEBUG_MODE`).
 * 
 * @param expected  The expected string value.
 * @param given     The actual string value.
 * @param message   An optional message.
 */
static void assertPP(string expected, string given, string message = "");

/**
 * If values don't match, logs an error and throws an exception. Logs success if equal (in `DEBUG_MODE`).
 * 
 * @param expected  The expected string value.
 * @param given     The actual string value.
 * @param message   An optional message.
 */
static void assertPP(int expected, int given, string message = "");

#define DEBUG_MODE true
#ifdef DEBUG_MODE

/**
 * VAR_ASSIGNMENT(oldVar, newVar) - Wraps variable assignment with debugging. Logs the assignment.
 * @param oldVar Variable being assigned.
 * @param newVar New value to assign.
 */
#define VAR_ASSIGNMENT(oldVar, newVar) oldVar = Debug_Var_Assign(oldVar, newVar, #oldVar, &oldVar)

/**
 * ASSERT(v, ev) - Checks if `v` satisfies `ev`. Logs the variable name and condition in case of failure.
 * @param v  Variable to assert.
 * @param ev Expected value or condition.
 */
#define ASSERT(v, ev) assertPP(v, ev, #v)

#define DEBUG_LOG(name, message) Debug_Message(name, message)


#else // Non-debug mode

#define VAR_ASSIGNMENT(oldVar, newVar) oldVar = newVar  // Direct assignment without debugging.
#define ASSERT(v, ev)  // Empty, no assertions in non-debug mode.
#define DEBUG_LOG(name, message) 

#endif
#endif