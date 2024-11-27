#include "Better_Debugging.hpp"


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
    {
        cout << DEBUG_COLOR << "[Variable Assignation] - Variable Name:" << varName << " Initial value: " << var << ", New Value: " << newValue << ", Adresse: " << adresse << RESET_COLOR << endl;
    }

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