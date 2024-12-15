# Debugging Functions

This document outlines the functionalities provided by the Better_Debugging library, detailing the usage, behavior, and customization options.

# Table of Contents

1. [TEST_CASE](#test_case)
   - [Usage](#usage)
   - [Example](#example)
2. [VAR_ASSIGNMENT](#var_assignment)
   - [Usage](#usage-1)
   - [Example](#example-1)
3. [DEBUG_LOG](#debug_log)
4. [Hidden Functions](#hidden-functions)
   - [Debug_Var_Assign](#debug_var_assign)
   - [testCasePP](#testcasepp)
   - [Debug_Message & Error_Message](#debug_message--error_message)


## TEST_CASE
Validates a condition and logs an error message if it fails. If the **DEBUG_MODE** is disable, All uses of **ASSERT** is remove from code and will **not be compiled**.

### Usage:
```C++
TEST_CASE(variable, expectedValue);
```

### Example:
```C++
TEST_CASE(x, 10);  // Passes if x == 10, logs an error otherwise.
```

## VAR_ASSIGNMENT
Logs the assignment of a variable, showing its current value, new value, and memory address. When **DEBUG_MODE** is disabled, `VAR_ASSIGNMENT(variable, newValue)` will simply assign the new value without logging.

### Usage:
```C++
VAR_ASSIGNMENT(variable, newValue);
```

### Example:
```C++
VAR_ASSIGNMENT(x, 5);  // Logs: "Variable x: initial value = 1, new value = 5"
```
In this example if the `DEBUG_MODE` is disable `VAR_ASSIGNMENT(x, 5)` is replaced by `x = 5` durring compilation.

## DEBUG_LOG
Allows you to output debug messages. The logs are styled based on the type of message (e.g., debug or error). By default, these messages are printed to the console, and they can optionally be saved to files.

## Hidden Functions
### Debug_Var_Assign
Used internally to handle variable assignment with logging.

### testCasePP
Handles assertion logic for testing conditions.

### Debug_Message & Error_Message
Debug_Message and Error_Message are special Hidden Functions. The definition of those functions can differ during the compilation.