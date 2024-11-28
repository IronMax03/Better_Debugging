#include "Better_Debugging.hpp"
#include <exception>
#include <string>

class AssertPPFail : public exception {
    // to be improved
};

static string Debug_Var_Assign(string var, string newValue, string varName, string* adresse)
{
    Debug_Message("Variable Assignation", "Variable Name:" + varName + " Initial value: " + var + ", New Value: " + newValue);

    return var;
}

static int Debug_Var_Assign(unsigned int  var, unsigned int newValue, string varName, unsigned int* adresse)
{
    Debug_Message("Variable Assignation", "Variable Name:" + varName + " Initial value: " + to_string(var) + ", New Value: " + to_string(newValue));

    var = newValue;
    return var;
}

static void assertPP(string expected, string given, string message = "")
{
    try
    {
        if(expected != given)
        {
            throw AssertPPFail();
        }
    }
    catch(AssertPPFail af)
    {
        Error_Message("Assert Fail", "expected:" + expected + ", got:" + given + ", from:" + message);
    }
    catch(exception e)
    {
        cout << e.what() << endl;
    }

    Debug_Message("Assert Passed", message);
}

static void assertPP(int expected, int given, string message = "")
{
    try
    {
        if(expected != given)
        {
            throw AssertPPFail();
        }
    }
    catch(AssertPPFail af)
    {
        Error_Message("Assert Fail", "expected:" + to_string(expected) + ", got:" + to_string(given) + ", from:" + message);
    }
    catch(exception e)
    {
        cout << e.what() << endl;
    }

    Debug_Message("Assert Passed", message);
}