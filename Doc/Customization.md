# Customization Guide

This document provides instructions for customizing the **Better_Debugging** library to suit your development needs, including changing log colors, saving logs, and toggling debugging features. **All customization must be done before** `#include "Better_Debugging.cpp"`.

# Table of Contents

1. [Changing Log Colors](#changing-log-colors)
   - [Available Color Codes (ANSI Escape Sequences)](#available-color-codes-ansi-escape-sequences)
   - [Example](#example)
2. [Saving Logs](#saving-logs)
   - [DONT_SAVE_LOGS](#dont_save_logs)
   - [CREATE_NEW_LOGS_FILE](#create_new_logs_file)
3. [Disabling Debugging Features](#disabling-debugging-features)
   - [Example](#example-1)
4. [Adding Custom Behaviors](#adding-custom-behaviors)
   - [Custom Log Format](#custom-log-format)
5. [Example Configuration](#example-configuration)
6. [Troubleshooting](#troubleshooting)


## Changing Log Colors

You can customize the color of debug and error messages using the following macros:

- **DEBUG_COLOR**: Defines the color for debug messages.
- **ERROR_COLOR**: Defines the color for error messages.
- **TEST_CASE_FAILED**: Defines the color for successful test case messages.
- **RESET_COLOR**: Resets the terminal color to default after a log.

### Example of Color Codes (ANSI Escape Sequences):
- `\033[31m`: Red
- `\033[32m`: Green
- `\033[33m`: Yellow
- `\033[34m`: Blue
- `\033[35m`: Magenta
- `\033[36m`: Cyan
- `\033[0m`: Default/Reset

### Example:
```cpp
#define DEBUG_COLOR "\033[32m"  // Green
#define ERROR_COLOR "\033[31m"  // Red
#define RESET_COLOR "\033[0m"   // Default
```

## Saving Logs

By default all debug messages are saved inside **logs.txt** (assuming `DEBUG_MODE` is activated). Better Debugging offer to options for saving logs: `DONT_SAVE_LOGS` and `CREATE_NEW_LOGS_FILE`. Both options can't be used together.

### DONT_SAVE_LOGS
`DONT_SAVE_LOGS` avoid logs been saved in a text file.
#### Example
```c++
#define DONT_SAVE_LOGS
#include "Better_Debugging.cpp"
```

### CREATE_NEW_LOGS_FILE
When `CREATE_NEW_LOGS_FILE` is activated a new **.txt** file is created for each run of the program. 
#### Example
```c++
#define CREATE_NEW_LOGS_FILE
#include "Better_Debugging.cpp"
```