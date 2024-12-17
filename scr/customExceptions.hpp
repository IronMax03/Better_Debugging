#include <exception>

/**
 * @class testCaseFailed
 * @brief Custom exception class for handling test case assertion failures.
 *
 * This class extends the standard `exception` to provide descriptive 
 * error messages when a test case assertion fails. It is designed for use in
 * debugging and testing scenarios, allowing developers to identify and handle 
 * assertion failures in a structured manner.
 */
class testCaseFailed : private  std::exception 
{
    private:
       std::string _message;

   public:
        explicit testCaseFailed(const std::string& msg = "Assertion failed") 
        {
                _message = msg;
        }        

        ~testCaseFailed() _NOEXCEPT {} // Explicitly mark as noexcept

        const char* what() const _NOEXCEPT 
        {
            return _message.c_str();
        } 
};