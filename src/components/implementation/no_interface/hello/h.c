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
	 lua_getglobal(L, "fib");
	lua_pushnumber(L,20);
	 lua_pcall(L,1,1,0);
	int new_num = (int)lua_tonumber(L, -1);
	printc("Lua from fib.lua:%d\n", new_num);
	
	int i = 0;	
	for (i = 0; i < 10; i++) {

		lua_getglobal(L,"linked_list");
		lua_pushnumber(L,40000);
		lua_pcall(L,1,0,0);
		char *str = lua_tostring(L,-1);
		printc("Lua string is %s\n", str); 
		printc("garbage %d\n", lua_gc(L, LUA_GCCOUNT,0));
	
		lua_getglobal(L,"clear_list");
		lua_pcall(L,0,0,0);
		// lua_gc(L, LUA_GCCOLLECT,9);
		printc("garbage %d\n", lua_gc(L, LUA_GCCOUNT,0));
	}
	// Closes lua
	lua_close(L);
	printc("End of Lua file\n");

	return;
}
