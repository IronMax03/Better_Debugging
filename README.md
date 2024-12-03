# Better_Debugging
Have you ever had a test case fail and struggled to understand the issue? Better_Debugging is here to make debugging easier.

**Better_Debugging** is a C++ library designed to simplify debugging by providing tools to log, assert, and monitor variable changes seamlessly. It allows you to maintain cleaner and more informative debugging code without impacting production code. Note that this library is not a debugger—it’s a tool to enhance your debugging experience.

## Current Features

- Easy Variable Assignment Logging: Track variable changes with detailed logs.
- Powerful Assertions: Validate conditions with custom messages.

## How to use it

1. Include `Better_Debugging.hpp` in your project.

2. Enable debugging mode by adding `#define DEBUG_MODE` before the include statement. This activates the debugging functionality. If omitted, the library will gracefully deactivate debugging without affecting your code.


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
    ASSERT(x, 2);

    return 0;
}
```

If `#define DEBUG_MODE` is removed,  Debuging functions will have no effect, ensuring minimal impact on production code.

## Debuging Functions

### ASSERT
Validates a condition and logs an error message if it fails. If the **DEBUG_MODE** is disable, All uses of **ASSERT** is remove from code and will **not be compiled**.

#### Usage:
```C++
ASSERT(variable, expectedValue);
```

#### Example:
```C++
ASSERT(x, 10);  // Passes if x == 10, logs an error otherwise.
```

### VAR_ASSIGNMENT
Logs the assignment of a variable, showing its current value, new value, and memory address.

#### Usage:
```C++
VAR_ASSIGNMENT(variable, newValue);
```

#### Example:
```C++
VAR_ASSIGNMENT(x, 5);  // Logs: "Variable x: initial value = 1, new value = 5"
```
If the `DEBUG_MODE` is disable in this example `VAR_ASSIGNMENT(x, 5)` will be replaced by `x = 5`.

### DEBUG_LOG

## Hidden Functions

### Debug_Var_Assign

### assertPP

### Debug_Message & Error_Message
Debug_Message and Error_Message are special Hidden Functions. The definition of those functions can differ during the compilation.

# Contributing
We welcome contributions to **Better_Debugging**! Whether you’re fixing bugs, adding features, or improving documentation, your efforts are greatly appreciated. Contributions help make this project better for everyone.

## Discutions
If you  have any idea that could fit in this project We are also open to discussions. But remenber that the main purpose of this project is too simplify programmers work whith minimal to no impact when `DEBUG_MOD` is disable.

## Guidelines

- **Coding Standards:**
Follow clean and consistent coding practices. Use meaningful variable and function names.

- **Document Your Code:**
Ensure all functions have clear and concise comments.

- **Test Your Changes:**
While we understand that fully testing this library may be challenging, ensure your code works as intended before submitting. Focus on edge cases and confirm that your changes integrate smoothly with existing functionality.

- **Be Respectful**:
Engage in discussions respectfully and constructively.