*This project has been created as part of the 42 curriculum by mzbair*

# ft_printf

## Description
This project involves recoding the popular and versatile C library function, `printf()`. The primary goal is to learn how to use variadic functions in C while building a well-structured and extensible codebase. 

As per the requirements of 42 subject, this implementation handles the following mandatory conversions without implementing the original `printf()` buffer management:
* `%c` - Prints a single character.
* `%s` - Prints a string.
* `%p` - Prints a void pointer in hexadecimal format.
* `%d` - Prints a decimal (base 10) number.
* `%i` - Prints an integer in base 10.
* `%u` - Prints an unsigned decimal (base 10) number.
* `%x` - Prints a number in hexadecimal (base 16) lowercase.
* `%X` - Prints a number in hexadecimal (base 16) uppercase.
* `%%` - Prints a percent sign.

## Algorithm
The core algorithm relies on sequentially parsing the provided format string. A main loop iterates through each character:
1. If the character is not a `%`, it is immediately written to the standard output.
2. If a `%` is encountered, the algorithm checks the subsequent character to determine the conversion specifier.
3. Based on the specifier, a dispatch mechanism (using simple `if-else`) routes the variable argument to the appropriate helper function (e.g., `print_char`, `print_number`, `print_hex`).

The `stdarg.h` macros (`va_start`, `va_arg`, `va_end`) are used to iterate through the undefined number of arguments.

## Instructions
To compile and use the library:

1. **Clone the repository and compile:**
   Navigate to the repository root and run `make`. This will compile the source files and generate the static library `libftprintf.a`.
   ```bash
   make
   ```

2. **Include it in your project:**
   Include the header in your C files:
   ```c
   #include "ft_printf.h"
   ```

3. **Compile your executable:**
   Link the library when compiling your project:
   ```bash
   cc -Wall -Wextra -Werror your_file.c libftprintf.a
   ```

To clean the object files, run `make clean`. To remove all compiled files including the library, run `make fclean`. 

## Resources
*   **Documentation:** `man 3 printf`, `man 3 stdarg`
*   **AI Usage:** AI was used purely as an explanatory learning tool in this project, in accordance with the 42 AI Instructions. It was consulted to clarify foundational concepts. all reasoning and implementation were developed independently to build strong programming foundations.