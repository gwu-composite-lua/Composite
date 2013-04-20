#include <cos_component.h>
#include <print.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

void
cos_init(void)
{
	printc("Hello, dinosaur!");
	lua_State *L = luaL_newstate();
	int top = lua_gettop(L);

	printc("Lua stack is %d", top);


	lua_close(L);
	printc("END OF LUA FILE\n");

	return;
}