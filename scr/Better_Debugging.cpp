#include "Better_Debugging.hpp"
#include <exception>
#include <string>
#include <sstream>

using namespace std;

// save logs
#if defined(SAVE_LOGS_ALL_LOGS) && defined(SAVE_ALL_LOGS)
    #error "You cant use SAVE_LOGS and SAVE_ALL_LOGS together."
#else
    #ifdef SAVE_LOGS
        #include <fstream>
        static void Debug_Message(string name, string messages)
        {
            ofstream logsTxt;
            cout << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << endl;    
            logsTxt.open("logs.txt"); 
            logsTxt << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << endl;
            logsTxt.close();
        }

        static void Error_Message(string name, string messages)
        {
            ofstream logsTxt;
            cout << ERROR_COLOR << "[" << name << "] - " << messages << RESET_COLOR << endl;    
            logsTxt.open("logs.txt"); 
            logsTxt << "/!\\[" << name << "] - " << messages << endl;
            logsTxt.close();
        }

    #elif defined(SAVE_ALL_LOGS)
        #include <fstream>
        #define COMPILATION_DATE __DATE__
        #define COMPILATION_TIME __TIME__

        static void Debug_Message(string name, string messages)
        {
            ofstream logsTxt;
            cout << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << endl;  
            string date = COMPILATION_TIME;
            string fileName = "logs-" + date + "-" + COMPILATION_TIME + ".txt";
            logsTxt.open(fileName); 
            logsTxt << "[" << name << "] - " << messages << endl;
            logsTxt.close();        
        }
            
        static void Error_Message(string name, string messages)
        {
            ofstream logsTxt;
            cout << ERROR_COLOR << "[" << name << "] - " << messages << RESET_COLOR << endl; 
            string date = COMPILATION_TIME;
            string fileName = "logs-" + date + "-" + COMPILATION_TIME + ".txt"; 
            logsTxt.open(fileName); 
            logsTxt << "/!\\[" << name << "] - " << messages << endl;
            logsTxt.close();
        }
    #else
        static void Debug_Message(string name, string messages)
        {
            cout << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << endl;       
        }

        static void Error_Message(string name, string messages)
        {
            cout << ERROR_COLOR << "[" << name << "] - " << messages << RESET_COLOR << endl;    
        }
    #endif
#endif

class testcaseFailed : public exception 
{
    // to be improved
    private:
        string _message;

   public:
   explicit testcaseFailed(const string& msg = "Assertion failed") 
   {
        _message = msg;
   }

    ~testcaseFailed() _NOEXCEPT {} // Explicitly mark as noexcept

    const char* what() const _NOEXCEPT 
    {
        return _message.c_str();
    } 
};

static string Debug_Var_Assign(string var, string newValue, string varName, string* adresse)
{
    ostringstream messageStream;
    messageStream   << "Variable Name:" << varName 
                    << " Current value: " << var  
                    << ", New Value: " << newValue 
                    << ", var address: " << &adresse;

    Debug_Message("Variable Assignation", messageStream.str());

    return newValue;
}

static int Debug_Var_Assign(int  var, int newValue, string varName, int* adresse)
{
    ostringstream messageStream;
    messageStream   << "Variable Name:" << varName 
                    << " Current value: " << to_string(var)  
                    << ", New Value: " << to_string(newValue) 
                    << ", var address: " << &adresse;

    Debug_Message("Variable Assignation", messageStream.str());

    return newValue;
}

static void assertPP(string expected, string given, string message )
{
    try
    {
        if(expected != given)
        {
            throw testcaseFailed("expected:" + expected + ", got:" + given + ", from:" + message);
        }
        Debug_Message("Assert Passed", message);
    }
    catch(testcaseFailed& af)
    {
        Error_Message("Assert Fail", af.what());
        throw af;
    }
    catch(exception& e)
    {
        Error_Message("error in assert", e.what());
        throw e;
    }
    catch(...)
    {
        Error_Message("exception in assert","an unknown exception occured inside ASSERT");
        throw;
    }
}

static void assertPP(int expected, int given, string message )
{
    try
    {
        if(expected != given)
        {
            throw testcaseFailed("expected:" + to_string(expected) + ", got:" + to_string(given) + ", from:" + message);
        }
        Debug_Message("Assert Passed", message);
    }
    catch(testcaseFailed& af)
    {
        Error_Message("Assert Fail", af.what());
        throw af;
    }
    catch(exception& e)
    {
        Error_Message("error in assert", e.what());
        throw e;
    }
    catch(...)
    {
        Error_Message("exception in assert","an unknown exception occured inside ASSERT");
        throw;
    }
}