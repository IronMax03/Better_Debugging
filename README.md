# Better_Debugging
Have you ever had a test case fail and struggled to understand the issue? Better_Debugging is here to make debugging easier.

**Better_Debugging** is a C++ library designed to simplify debugging by providing tools to log, assert, and monitor variable changes seamlessly. It allows you to maintain cleaner and more informative debugging code without impacting production code. Note that this library is not a debugger—it’s a tool to enhance your debugging experience.

## Current Features
To find a complete documentation of the features click [here](Doc/Documentation.md).
- Easy Variable Assignment Logging: Track variable changes with detailed logs.
- Powerful Test Cases: Validate conditions with custom messages.








## How to use it

1. **Download the Project**  
   Clone or download the **Better_Debugging** project to your local machine.

2. **Compile the Library**  
   Navigate to the `src` directory:
   ```bash
   g++ -c Better_Debugging.cpp -o Better_Debugging.o
- This command compiles the library into an object file (Better_Debugging.o)
- **Note:** The project is tested with GCC but should also work with **clang++**.

3. **Include the Object File in Your Project**  
   Add the Better_Debugging.o file to your repository or build system.

4. **Include the Header File**  
   In your source file(s), include the library header:
   ```cpp
   #include "Better_Debugging.cpp"
   ```

5. **Enable Debugging Mode**
    You can activate debugging functionality in one of two ways:
    - **Using the Compiler Flag:** <br>
    Pass `-DEBUG_MODE` when compiling your project:
    ```bash
    g++ -DEBUG_MODE main.cpp
    ```
    - **Using a Preprocessor Directive:**

6. **Run Your Program** <br>
    Execute the compiled program, and debugging logs or assertions will be printed as expected.

## How to use it
2.  Include `Better_Debugging.o` in your repository.

3. Add `#include "Better_Debugging.cpp"` to the header.

4. Enable debugging mode by using the flag `-DEBUG_MODE` when compiling your project. This activates the debugging functionality. If omitted, the library will gracefully deactivate debugging without affecting your code. An alternative methode to activates **DEBUG_MODE** is by adding `#define DEBUG_MODE` before `#include "Better_Debugging.cpp"`.










### For example:

```C++
#define DEBUG_MODE

#include"Better_Debuging.cpp"
#include<iostream>

using namespace std;

int main()
{
    int x = 1

    VAR_ASSIGNMENT(x, 2); // those function will be explain later  
    TEST_CASE(x, 2);

    return 0;
}
```

If `#define DEBUG_MODE` is removed,  Debuging functions will have no effect, ensuring minimal impact on production code.

# Contributing
We welcome contributions to **Better_Debugging**! Whether you’re fixing bugs, adding features, or improving documentation, your efforts are greatly appreciated. Contributions help make this project better for everyone.

### Discutions
If you  have any idea that could fit in this project We are also open to discussions. But remenber that the main purpose of this project is too simplify programmers work whith minimal to no impact when `DEBUG_MOD` is disable.

### Guidelines

- **Coding Standards:**
Follow clean and consistent coding practices. Use meaningful variable and function names.

- **Document Your Code:**
Ensure all functions have clear and concise comments/description.

- **Test Your Changes:**
While we understand that fully testing this library may be challenging, ensure your code works as intended before submitting. Focus on edge cases and confirm that your changes integrate smoothly with existing functionality.

- **Be Respectful**:
Engage in discussions respectfully and constructively.