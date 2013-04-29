#ifndef   	LUA_KEYVAL_H
#define   	LUA_KEYVAL_H

#include <cos_component.h>
#include <print.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdlib.h>

extern lua_State *L;
extern int scopetest;

char* luakv_getstring_bytable (lua_State *L, char *key, char *table_name);
char* luakv_getstring (lua_State *L, char *key);
int  luakv_getnumber_bytable (lua_State *L, char *key, char *table_name);
int  luakv_getnumber (lua_State *L, char *key);
void luakv_putstring_bytable (lua_State *L, char *key, char *value, char *table_name);
void luakv_putstring (lua_State *L, char *key, char *value);
void luakv_putnumber_bytable (lua_State *L, char *key, int intvalue, char *table_name);
void luakv_putnumber (lua_State *L, char *key, int intvalue);

#endif 	    /* !LUA_KEYVAL_H */
