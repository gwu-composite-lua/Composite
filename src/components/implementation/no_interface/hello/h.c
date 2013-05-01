#include <cos_component.h>
#include <print.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdlib.h>

int map_create(lua_State *lua);
int map_slice(lua_State *lua);

void
cos_init(void)
{
	printc("We welcome our new Lua overlords!\n");
	// Creates the lua state
	lua_State *L = luaL_newstate();

	// Pushes an int onto the Lua stack, pops it, 
	// Testing executing a string of Lua
	// returns a value which pushes it onto the stack, then
	// prints it
	
	// tests loding configuration from a file
	// loads the file, then executes it, which converts the variables
	// in the file to lua parsable data
	if (luaL_loadfile(L, "/home/cos/research/composite/src/components/implementation/no_interface/hello/foo.lua") || lua_pcall(L, 0, 0, 0)){
		// if either call fails, will return non-zero error code and print
		// it out here
		printc("error %s", lua_tostring(L, -1));
	}
	 lua_getglobal(L, "foo");
	lua_pushnumber(L, 40);
	 lua_pcall(L,1,1,0);
	int new_num = (int)lua_tonumber(L, -1);
	printc("Lua from foo.lua %d\n num", new_num);

	// Closes lua
	lua_close(L);
	printc("END OF LUA FILE\n");

	return;
}

int map_create(lua_State *lua)
{
	printc("mape create");
}

int map_slice(lua_State *lua)
{
	printc("map slice");
}

