#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define BASE 10

int mul_digit_string(const int, const char *, char **);
int add_digit_strings(const char *, const char *, char **);
int mul_int_string(const int, const char *, char **);

const char *string_mul_digit_string(const int, const char *);
const char *string_add_digit_strings(const char *, const char *);
const char *string_mul_int_string(const int, const char *);
