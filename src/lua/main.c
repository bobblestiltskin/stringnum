#ifdef __cplusplus
  #include "lua.hpp"
#else
  #include "lua.h"
  #include "lualib.h"
  #include "lauxlib.h"
#endif
#include <math.h>

#include "../stringnum.h"

//so that name mangling doesn't mess up function names
#ifdef __cplusplus
extern "C"{
#endif

static int my_string_mul_digit_string (lua_State *L) {
    int alpha = luaL_checknumber (L, 1);
    const char *in_string = luaL_checkstring (L, 2);
    lua_pushstring(L, string_mul_digit_string(alpha, in_string));
    return 1;
}

static int my_string_add_digit_strings (lua_State *L) {
    const char *in_string_1 = luaL_checkstring (L, 1);
    const char *in_string_2 = luaL_checkstring (L, 2);
    lua_pushstring(L, string_add_digit_strings(in_string_1, in_string_2));
    return 1;
}

static int my_string_mul_int_string (lua_State *L) {
    int alpha = luaL_checknumber (L, 1);
    const char *in_string = luaL_checkstring (L, 2);
    lua_pushstring(L, string_mul_int_string(alpha, in_string));
    return 1;
}

static const struct luaL_Reg mylib [] = {
      {"mul_digit_string", my_string_mul_digit_string}, 
      {"add_digit_strings", my_string_add_digit_strings}, 
      {"mul_int_string", my_string_mul_int_string}, 
      {NULL, NULL}  /* sentinel */
    };

//name of this function is not flexible
int luaopen_mylib (lua_State *L){
    luaL_newlib(L, mylib);
    return 1;
}

#ifdef __cplusplus
}
#endif
