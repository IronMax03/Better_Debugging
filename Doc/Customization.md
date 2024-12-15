# Customization Guide

This document provides instructions for customizing the **Better_Debugging** library to suit your development needs, including changing log colors, saving logs, and toggling debugging features.

---

## Changing Log Colors

You can customize the color of debug and error messages using the following macros:

- **DEBUG_COLOR**: Defines the color for debug messages.
- **ERROR_COLOR**: Defines the color for error messages.
- **RESET_COLOR**: Resets the terminal color to default after a log.

### Available Color Codes (ANSI Escape Sequences):
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
