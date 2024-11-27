#ifndef BETTER_DEBUGGING
#define BETTER_DEBUGGING

// imports
#include <iostream>

// colors
#define ERROR_COLOR  "\033[31m"
#define DEBUG_COLOR  "\033[33m"
#define RESET_COLOR   "\033[0m"


#define DEBUG_MODE true
#ifdef DEBUG_MODE

/**
 * ASSERT(v, ev) - Checks if `v` satisfies `ev`. Logs the variable name and condition in case of failure.
 * - `v`  : Variable to assert.
 * - `ev` : Expected value or condition.
 */
#define ASSERT(v, ev) assertPP(v, ev, #v)

/**
 * VAR_ASSIGNMENT(oldVar, newVar) - Wraps variable assignment with debugging. Logs the assignment.
 * - `oldVar` : Variable being assigned.
 * - `newVar` : New value to assign.
 */
#define VAR_ASSIGNMENT(oldVar, newVar) oldVar = Debug_Var_Assign(oldVar, newVar, #oldVar, &oldVar)

using namespace std;

static void Debug_Message(string name, string messages = "")
{
    if(DEBUG_MODE)
    {
        cout << DEBUG_COLOR << "[" << name << "]";

        if(messages != "")
            cout << " - " << messages;

        cout << RESET_COLOR << endl;
    }
}

static string Debug_Var_Assign(string var, string newValue, string varName, string* adresse)
{
    if(DEBUG_MODE)
    {
        cout << DEBUG_COLOR << "[Variable Assignation] - Variable Name:" << varName << " Initial value: " << var << ", New Value: " << newValue << ", Adresse: " << adresse << RESET_COLOR << endl;       
    }
    
    var = newValue;
    return var;
}

static int Debug_Var_Assign(unsigned int  var, unsigned int newValue, string varName, unsigned int* adresse)
{
    if(DEBUG_MODE)
        cout << DEBUG_COLOR << "[Variable Assignation] - Variable Name:" << varName << " Initial value: " << var << ", New Value: " << newValue << ", Adresse: " << adresse << RESET_COLOR << endl;
    
    var = newValue;
    return var;
}

static void assertPP(string expected, string given, string message = "")
{
    if(expected != given)
    {
        cout << ERROR_COLOR << "[Assert Failed] - expected:" << expected << ", got:" << given << ", " << message << RESET_COLOR << endl;
        throw;
    }

    if(DEBUG_MODE)
        cout << DEBUG_COLOR << "[Assert Passed] - " << message << RESET_COLOR << endl;
}

static void assertPP(int expected, int given, string message = "")
{
    if(expected != given)
    {
        cout << ERROR_COLOR << "[Assert Failed] - expected:" << expected << ", got:" << given << ", " << message << RESET_COLOR << endl;
        throw;
    }
    else
    {
        cout << DEBUG_COLOR << "[Assert Passed] - " << message << RESET_COLOR << endl;
    }
}



#else // Non-debug mode

#define ASSERT(v, ev)  // Empty, no assertions in non-debug mode.
#define VAR_ASSIGNMENT(oldVar, newVar) oldVar = newVar  // Direct assignment without debugging.

#endif
#endif