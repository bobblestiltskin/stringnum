#include "stringnum.h"

int call_mul_int_string(const int, const int *, const char **, const char **);

int main(int argc, char **argv)
{
  int scalars[3] = {453, 79, 11};
  const char *input[3] = {
    "848420140399492297106356716875151822642872438767105649714481489956523636302090141899467854328695620784124526552974761438647138281062400000000000000000000000",
    "75415123591065981965009485944457939790477550112631613307953910218357656560185790391063809273661832958588846804708867683435301180538880000000000000000000000",
    "678736112319593837685085373500121458114297951013684519771585191965218909041672113519574283462956496627299621242379809150917710624849920000000000000000000000"
  };

  const char *output[3] = {
    "384334323600970010589179592744443775657221214761498859320660114950305207244846834280458938010899116215208410528497566931707153641321267200000000000000000000000",
    "5957794763694212575235749389612177243447726458897897451328358907250254868254677440894040932619284803728518897572000546991388793262571520000000000000000000000",
    "7466097235515532214535939108501336039257277461150529717487437111617407999458393248715317118092521462900295833666177900660094816873349120000000000000000000000"
  };

  int status = call_mul_int_string(0, scalars, input, output);
  if (!status)
    status = call_mul_int_string(1, scalars, input, output);
  if (!status)
    status = call_mul_int_string(2, scalars, input, output);

  int a = 97;
  const char *b = "1234";
  const char *opstring = string_mul_int_string(a, b);
  printf("a is %d b is %s and opstring is %s\n", a, b, opstring);
  free((void *)opstring);

  return(status);
}

int call_mul_int_string(const int index, const int *scalars, const char **input, const char **output)
{
  int a = scalars[index];
  char *b = (char *) calloc(strlen(input[index]) + 1, sizeof(char));
  strncpy(b, input[index], strlen(input[index]));
  char *c = (char *) calloc(strlen(b) + 1, sizeof(char));

  int status = mul_int_string(a, b, &c);
  if (strncmp(c, output[index], strlen(output[index])))
    printf("%d * %s is %s and should be %s\n", a, b, c, output[index]);

  free(c);
  free(b);
  return status;
}
