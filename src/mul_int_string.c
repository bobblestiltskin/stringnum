#include "stringnum.h"

int mul_int_string(int alpha, const char *in_string, char **out_string_ptr)
{
#ifdef DEBUG
printf("ENTERING mul_int_string with alpha of %d and in_string of %s and outstring of %s\n", alpha, in_string, *out_string_ptr);
printf("out_string_ptr is %p\n", out_string_ptr);
#endif

  /* multiplies the input string in_string by the integer alpha */

  int in_length = strlen(in_string);
  char *in_copy = calloc(in_length + 1, sizeof(char));
  strncpy(in_copy, in_string, in_length);
  strncpy(*out_string_ptr, "0", 2);

  do {
    int modulo = alpha % BASE;
    int in_copy_len = strlen(in_copy);
    if (modulo)
    {
      if (modulo == 1)
      {
        char *out_current = (char *) calloc(strlen(*out_string_ptr) + 1, sizeof(char));
        strncpy(out_current, *out_string_ptr, strlen(*out_string_ptr) + 1);
        add_digit_strings(out_current, in_copy, out_string_ptr);
        free(out_current);
      }
      else
      {
        char *row = (char *) calloc(in_copy_len + 2, sizeof(char));
        int mds_ret = mul_digit_string(modulo, in_copy, &row);
        assert (mds_ret == 0);
        char *out_current = (char *) calloc(strlen(*out_string_ptr) + 1, sizeof(char));
        strncpy(out_current, *out_string_ptr, strlen(*out_string_ptr) + 1);
        add_digit_strings(out_current, row, out_string_ptr);
        free(out_current);
        free(row);
      }
    }
    in_copy = realloc(in_copy, strlen(in_copy) + 2);
    strcat(in_copy, "0");
  } while ((alpha = alpha / BASE));
  free(in_copy);

#ifdef DEBUG
printf("LEAVING mul_int_string with alpha of %d and in_string of %s and outstring of %s\n", alpha, in_string, *out_string_ptr);
#endif
  
  return 0;
}

const char *string_mul_int_string(const int alpha, const char *in_string)
{
  /* multiplies the in_string by an integer it returns a pointer to the locally added array */

  int out_len = strlen(in_string);
  char *tmp = calloc(out_len + 1, sizeof(char));

  mul_int_string(alpha, in_string, &tmp); // discard unused status return value
  return tmp;
}

