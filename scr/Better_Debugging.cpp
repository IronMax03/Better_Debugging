#include "Better_Debugging.hpp"
#include "customExceptions.hpp"
#include <sstream>
#include <string>

// save logs
#if defined(DONT_SAVE_LOGS) && defined(CREATE_NEW_LOGS_FILE)
    #error "You cant use DONT_SAVE_LOGS and CREATE_NEW_LOGS_FILE together."
#else
    #ifndef DONT_SAVE_LOGS

        #include <fstream>

        static void Debug_Message(std::string name, std::string messages)
        {
            std::ofstream logsTxt;
            std::cout << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;    
            logsTxt.open("logs.txt"); 
            logsTxt << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;
            logsTxt.close();
        }

        static void Success_Message(std::string name,std::string messages)
        {
            std::ofstream logsTxt;
            std::cout << TEST_CASE_PASSED << "[" << name << "] - " << messages << RESET_COLOR << std::endl;    
            logsTxt.open("logs.txt"); 
            logsTxt << DEBUG_COLOR << "√ - [" << name << "] - " << messages << RESET_COLOR << std::endl;
            logsTxt.close();
        }

        static void Error_Message(std::string name, std::string messages)
        {
            std::ofstream logsTxt;
            std::cout << ERROR_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;    
            logsTxt.open("logs.txt"); 
            logsTxt << "/!\\ - [" << name << "] - " << messages << std::endl;
            logsTxt.close();
        }

    #elif defined(CREATE_NEW_LOGS_FILE)

        #include <fstream>

        #define COMPILATION_DATE __DATE__
        #define COMPILATION_TIME __TIME__

        static void Debug_Message(std::string name,std::string messages)
        {
            std::ofstream logsTxt;
            std::cout << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;  
            std::string date = COMPILATION_TIME;
            std::string fileName = "logs-" + date + "-" + COMPILATION_TIME + ".txt";
            logsTxt.open(fileName); 
            logsTxt << "[" << name << "] - " << messages << std::endl;
            logsTxt.close();        
        }

        static void Success_Message(std::string name,std::string messages)
        {
            std::ofstream logsTxt;
            std::cout << TEST_CASE_PASSED << "[" << name << "] - " << messages << RESET_COLOR << std::endl;  
            std::string date = COMPILATION_TIME;
            std::string fileName = "logs-" + date + "-" + COMPILATION_TIME + ".txt";
            logsTxt.open(fileName); 
            logsTxt << "√ - [" << name << "] - " << messages << std::endl;
            logsTxt.close();        
        }
            
        static void Error_Message(std::string name,std::string messages)
        {
            std::ofstream logsTxt;
            std::cout << ERROR_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl; 
            std::string date = COMPILATION_TIME;
            std::string fileName = "logs-" + date + "-" + COMPILATION_TIME + ".txt"; 
            logsTxt.open(fileName); 
            logsTxt << "/!\\ - [" << name << "] - " << messages << std::endl;
            logsTxt.close();
        }

    #else

        static void Success_Message(std::string name, std::string messages)
        {
            std::cout << TEST_CASE_PASSED << "[" << name << "] - " << messages << RESET_COLOR << std::endl;       
        }

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
        Success_Message("Test Case Passed", message);
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
        Success_Message("Test Case Passed", message);
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