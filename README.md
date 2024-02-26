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

Each function now has a string_ variant which returns a const char * of a local string and returns the string, rather than the int status, output_ptr idiom.

- const char *string_mul_digit_string(const int digit, const char *in_string)
  -- returns a string containing the product of the digit and the in_string
- const char *string_add_digit_strings(const char *in_string_1, const char *in_string_2)
  -- returns a string containing the sum of the two input strings
- const char *string_mul_int_string(int alpha, const char *in_string)
   -- returns a string comprising the product of alpha and the in_string

  All of these veriants cause memory to be allocated so the local variable set from any of the functions should be free'd after use. (see the test programs for exemplars).
