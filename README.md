# Better_Debugging
This project objective is to make a C++ library that make debugin eazy.  

## How to use it
In order to use the functionalitys of the library you must include **Better_Debuging.cpp** and add `#define DEBUG_MODE` above the include.

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

If `#define DEBUG_MODE` is removed the functions **ASSERT** and **VAR_ASSIGNMENT** will have no effect on the code.

## Debuging Functions

### ASSERT

### VAR_ASSIGNMENT

### DEBUG_LOG

## Hidden Functions

### Debug_Var_Assign

### assertPP

### Debug_Message & Error_Message
Debug_Message and Error_Message are special Hidden Functions becaus there definition can change.

