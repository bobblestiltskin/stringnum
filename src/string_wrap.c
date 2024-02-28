#include "stringnum.h"

const char *string_mul_digit_string(const int digit, const char *in_string)
{
  /* multiplies the in_string by a single digit it returns a pointer to the locally added array */

  int out_len = strlen(in_string);
  char *tmp = calloc(out_len + 1, sizeof(char));

  mul_digit_string(digit, in_string, &tmp); // discard returned status value
  return tmp;
}

const char *string_add_digit_strings(const char *in_1_string, const char *in_2_string)
{
  /* multiplies the in_string by a single digit it returns a pointer to the locally added array */

  int out_len = (strlen(in_1_string) > strlen(in_2_string)) ? strlen(in_1_string) : strlen(in_2_string);
  char *tmp = calloc(out_len + 1, sizeof(char));

  add_digit_strings(in_1_string, in_2_string, &tmp); // discard returned status
  return tmp;
}

const char *string_mul_int_string(const int alpha, const char *in_string)
{
  /* multiplies the in_string by an integer it returns a pointer to the locally added array */

  int out_len = strlen(in_string);
  char *tmp = calloc(out_len + 1, sizeof(char));

  mul_int_string(alpha, in_string, &tmp); // discard unused status return value
  return tmp;
}
