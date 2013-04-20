#include <cos_component.h>
#include <print.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

void
cos_init(void)
{
	printc("We welcome our new Lua overlords!");
	// Creates the lua state
	lua_State *L = luaL_newstate();

	// Pushes an int onto the Lua stack, pops it, 
	// then prints it out
	lua_pushnumber(L, 23);
	int num = (int)lua_tonumber(L,1);
	printc("Lua stack is %d\n", num);

	// Closes lua
	lua_close(L);
	printc("END OF LUA FILE\n");

	return;
}
