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

        static void debugMessage(std::string name, std::string messages)
        {
            std::ofstream logsTxt;
            std::cout << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;    
            logsTxt.open("logs.txt", std::ios::app); 
            logsTxt << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;
            logsTxt.close();
        }

        static void successMessage(std::string name,std::string messages)
        {
            std::ofstream logsTxt;
            std::cout << TEST_CASE_PASSED << "[" << name << "] - " << messages << RESET_COLOR << std::endl;    
            logsTxt.open("logs.txt", std::ios::app); 
            logsTxt << DEBUG_COLOR << "√ - [" << name << "] - " << messages << RESET_COLOR << std::endl;
            logsTxt.close();
        }

        static void errorMessage(std::string name, std::string messages)
        {
            std::ofstream logsTxt;
            std::cout << ERROR_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;    
            logsTxt.open("logs.txt", std::ios::app); 
            logsTxt << "/!\\ - [" << name << "] - " << messages << std::endl;
            logsTxt.close();
        }

    #elif defined(CREATE_NEW_LOGS_FILE)

        #include <fstream>

        #define COMPILATION_DATE __DATE__
        #define COMPILATION_TIME __TIME__

        static void debugMessage(std::string name,std::string messages)
        {
            std::ofstream logsTxt;
            std::cout << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;  
            std::string date = COMPILATION_TIME;
            std::string fileName = "logs-" + date + "-" + COMPILATION_TIME + ".txt";
            logsTxt.open(fileName, std::ios::app); 
            logsTxt << "[" << name << "] - " << messages << std::endl;
            logsTxt.close();        
        }

        static void successMessage(std::string name,std::string messages)
        {
            std::ofstream logsTxt;
            std::cout << TEST_CASE_PASSED << "[" << name << "] - " << messages << RESET_COLOR << std::endl;  
            std::string date = COMPILATION_TIME;
            std::string fileName = "logs-" + date + "-" + COMPILATION_TIME + ".txt";
            logsTxt.open(fileName, std::ios::app); 
            logsTxt << "√ - [" << name << "] - " << messages << std::endl;
            logsTxt.close();        
        }
            
        static void errorMessage(std::string name,std::string messages)
        {
            std::ofstream logsTxt;
            std::cout << ERROR_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl; 
            std::string date = COMPILATION_TIME;
            std::string fileName = "logs-" + date + "-" + COMPILATION_TIME + ".txt"; 
            logsTxt.open(fileName, std::ios::app); 
            logsTxt << "/!\\ - [" << name << "] - " << messages << std::endl;
            logsTxt.close();
        }

    #else

        static void successMessage(std::string name, std::string messages)
        {
            std::cout << TEST_CASE_PASSED << "[" << name << "] - " << messages << RESET_COLOR << std::endl;       
        }

        static void debugMessage(std::string name,std::string messages)
        {
            std::cout << DEBUG_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;       
        }

        static void errorMessage(std::string name,std::string messages)
        {
            std::cout << ERROR_COLOR << "[" << name << "] - " << messages << RESET_COLOR << std::endl;    
        }
    #endif
#endif

static std::string debugVarAssign(std::string var,std::string newValue,std::string varName,std::string* adresse)
{
    std::ostringstream messageStream;
    messageStream   << "Variable Name:" << varName 
                    << " Current value: " << var  
                    << ", New Value: " << newValue 
                    << ", var address: " << adresse;

    debugMessage("Variable Assignation", messageStream.str());

    return newValue;
}

static int debugVarAssign(int  var, int newValue,std::string varName, int* adresse)
{
    std::ostringstream messageStream;
    messageStream   << "Variable Name:" << varName 
                    << " Current value: " << std::to_string(var)  
                    << ", New Value: " << std::to_string(newValue) 
                    << ", var address: " << adresse;

    debugMessage("Variable Assignation", messageStream.str());

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
        successMessage("Test Case Passed", message);
    }
    catch(testCaseFailed& af)
    {
        errorMessage("Test Case Fail", af.what());
        throw af;
    }
    catch(std::exception& e)
    {
        errorMessage("Test Case Error", e.what());
        throw e;
    }
    catch(...)
    {
        errorMessage("Test Case Error", "an unknown exception occured inside the test case.");
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
        successMessage("Test Case Passed", message);
    }
    catch(testCaseFailed& af)
    {
        errorMessage("Test Case Fail", af.what());
        throw af;
    }
    catch(std::exception& e)
    {
        errorMessage("Test Case Error", e.what());
        throw e;
    }
    catch(...)
    {
        errorMessage("Test Case Error", "an unknown exception occured inside the test case.");
        throw;
    }
}