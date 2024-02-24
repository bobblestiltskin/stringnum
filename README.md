# stringnum
arbitrary length numbers - which are stored in strings - implemented in c

3 functions are provided, all of which pass the input string as const char *in_string, 
and require a char **out_string_ptr as a pointer to externally allocated output storage.

- int mul_digit_string(const int digit, const char *in_string, char **out_string_ptr)
  /multiplies the in_string by a single digit

- int add_digit_strings(const char *in_string_1, const char *in_string_2, char **out_string_ptr);
  /adds the two input strings and writes the output string pointer

- int mul_int_string(int alpha, const char *in_string, char **out_string_ptr)
  /multiplies the input string in_string by the integer alpha
