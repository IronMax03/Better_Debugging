#include "Better_Debugging.hpp"
#include "customExceptions.hpp"
#include <string>
#include <sstream>

// save logs
#if defined(SAVE_LOGS_ALL_LOGS) && defined(SAVE_ALL_LOGS)
    #error "You cant use SAVE_LOGS and SAVE_ALL_LOGS together."
#else
    #ifdef SAVE_LOGS

        #include <fstream>
        static void Debug_Message(std::string name, std::string messages)
        {
            ofstream logsTxt;
            std::cout << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;    
            logsTxt.open("logs.txt"); 
            logsTxt << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;
            logsTxt.close();
        }

        static void Error_Message(std::string name, std::string messages)
        {
            ofstream logsTxt;
            std::cout << ERROR_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;    
            logsTxt.open("logs.txt"); 
            logsTxt << "/!\\[" << name << "] - " << messages << std::endl;
            logsTxt.close();
        }

    #elif defined(SAVE_ALL_LOGS)
        #include <fstream>
        #define COMPILATION_DATE __DATE__
        #define COMPILATION_TIME __TIME__

        static void Debug_Message(std::string name,std::string messages)
        {
            ofstream logsTxt;
            std::cout << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;  
           std::string date = COMPILATION_TIME;
           std::string fileName = "logs-" + date + "-" + COMPILATION_TIME + ".txt";
            logsTxt.open(fileName); 
            logsTxt << "[" << name << "] - " << messages << std::endl;
            logsTxt.close();        
        }
            
        static void Error_Message(std::string name,std::string messages)
        {
            ofstream logsTxt;
            std::cout << ERROR_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl; 
           std::string date = COMPILATION_TIME;
           std::string fileName = "logs-" + date + "-" + COMPILATION_TIME + ".txt"; 
            logsTxt.open(fileName); 
            logsTxt << "/!\\[" << name << "] - " << messages << std::endl;
            logsTxt.close();
        }

    #else

        static void Debug_Message(std::string name,std::string messages)
        {
            std::cout << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;       
        }

        static void Error_Message(std::string name,std::string messages)
        {
            std::cout << ERROR_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;    
        }
    #endif
#endif

static std::string Debug_Var_Assign(std::string var,std::string newValue,std::string varName,std::string* adresse)
{
    std::ostringstream messageStream;
    messageStream   << "Variable Name:" << varName 
                    << " Current value: " << var  
                    << ", New Value: " << newValue 
                    << ", var address: " << &adresse;

    Debug_Message("Variable Assignation", messageStream.str());

    return newValue;
}

static int Debug_Var_Assign(int  var, int newValue,std::string varName, int* adresse)
{
    std::ostringstream messageStream;
    messageStream   << "Variable Name:" << varName 
                    << " Current value: " << std::to_string(var)  
                    << ", New Value: " << std::to_string(newValue) 
                    << ", var address: " << &adresse;

    Debug_Message("Variable Assignation", messageStream.str());

    return newValue;
}

static void testCasePP(std::string expected, std::string given,std::string message )
{
    try
    {
        if(expected != given)
        {
            throw testCaseFailed("expected:" + expected + ", got:" + given + ", from:" + message);
        }
        Debug_Message("Test Case Passed", message);
    }
    catch(testCaseFailed& af)
    {
        Error_Message("Test Case Fail", af.what());
        throw af;
    }
    catch(std::exception& e)
    {
        Error_Message("Test Case Error", e.what());
        throw e;
    }
    catch(...)
    {
        Error_Message("Test Case Error", "an unknown exception occured inside the test case.");
        throw;
    }
}

static void testCasePP(int expected, int given,std::string message )
{
    try
    {
        if(expected != given)
        {
            throw testCaseFailed("expected:" + std::to_string(expected) + ", got:" + std::to_string(given) + ", from:" + message);
        }
        Debug_Message("Test Case Passed", message);
    }
    catch(testCaseFailed& af)
    {
        Error_Message("Test Case Fail", af.what());
        throw af;
    }
    catch(std::exception& e)
    {
        Error_Message("Test Case Error", e.what());
        throw e;
    }
    catch(...)
    {
        Error_Message("Test Case Error", "an unknown exception occured inside the test case.");
        throw;
    }
}