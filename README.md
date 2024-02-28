# stringnum
arbitrary length integers - which are stored in strings - implemented in c

3 functions are provided, all of which pass the input string as const char *in_string, 
and require a char **out_string_ptr as a pointer to externally allocated output storage
and each routine returns a status code - 0 for success.

- int mul_digit_string(const int digit, const char *in_string, char **out_string_ptr)
   --multiplies the input string by a single digit

- int add_digit_strings(const char *in_string_1, const char *in_string_2, char **out_string_ptr);
  -- adds the two input strings and writes the output string pointer

- int mul_int_string(int alpha, const char *in_string, char **out_string_ptr)
  -- multiplies the input string by the integer alpha

# Lua
The C stringnum library was conceived as a simple example to allow Lua to call C code.

In https://www.lua.org/pil/27.2.html

The first two paragraphs are :

----

When a C function receives a string argument from Lua, there are only two rules that it must observe: Not to pop the string from the stack while accessing it and never to modify the string.

Things get more demanding when a C function needs to create a string to return to Lua. Now, it is up to the C code to take care of buffer allocation/deallocation, buffer overflow, and the like. Nevertheless, the Lua API provides some functions to help with those tasks.

----

So we create wrapper functions for each of the functions to facilitate the access of the C code from Lua.
Each function now has a string_ variant which returns a const char * of a local string and returns the string, rather than the int status, output_ptr idiom.

- const char *string_mul_digit_string(const int digit, const char *in_string)
  -- returns a string containing the product of the digit and the in_string
- const char *string_add_digit_strings(const char *in_string_1, const char *in_string_2)
  -- returns a string containing the sum of the two input strings
- const char *string_mul_int_string(int alpha, const char *in_string)
   -- returns a string comprising the product of alpha and the in_string

  All of these variants cause memory to be allocated so the local variable set from any of the functions should be free'd after use. (see the test programs for exemplars).

The lua subdirectory of the src directory contains lua code clib_factorial.lua, which computes factorials using the C library code and lua_factorial.lua, which uses lua code to implement the large integers as strings. Glue code in main.c is compiled by the makefile to allow linkage from Lua to the C stringnum library.

We see when we compare the run times of the two Lua programs, that the C library is much faster than the Lua implementation.
