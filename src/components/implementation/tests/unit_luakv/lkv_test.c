//#include <cos_component.h>
//#include <print.h>
//#include <lua.h>
//#include <lualib.h>
//#include <lauxlib.h>
//#include <stdlib.h>
#include <lua_keyval.h>

int scopetest;

void 
cos_init(void)
{
	printc("Trying out some keyval operations\n");
	// Creates the lua state
	lua_State *L = luaL_newstate();
	scopetest = (int)42;
	printc("Starting lua keyvalue storage test. New Lua state has been set.\n");
	// Test for an empty value
	char *nilField = luakv_getstring(L,"EMPTY");
	printc("trying to getString before fields are entered. received %s\n", nilField);
	// Test putting a string value and retrieving it
	luakv_putstring(L,"key1","value1");
	printc("Put string of value1 into the default table at key1\n");
	char *get1 = luakv_getstring(L,"key1");
	printc("Retrieved the value at key1, return was: %s\n", get1);
	// Test putting a number value and retrieving it
	luakv_putnumber(L,"key2",(int)2);
	printc("Put number value of 2 into the default table at key2\n");
	int get2 = luakv_getnumber(L,"key2");
	printc("pull from the table key2: %d\n", get2);
	// Try storing values into another tablespace
	luakv_putstring_bytable(L,"key3","value3","TABLE2");
	luakv_putnumber_bytable(L,"key4",(int)4,"TABLE2");
	printc("Placed key3=value3 and key4=4 into TABLE2\n");
	// Try to retrieve the other tables valus from the default table
	printc("attempting to retrieve TABLE2 values from DEFAULT table\n");	
	char *get3_fail = luakv_getstring(L,"key3");
	int get4_fail = luakv_getnumber(L,"key4");
	printc("should have no values returned, retrieved key3=%s and key4=%d\n",get3_fail,get4_fail);
	// Now get TABLE 2 values from table2
	char *get3 = luakv_getstring_bytable(L,"key3", "TABLE2");
	int get4 = luakv_getnumber_bytable(L,"key4", "TABLE2");
	printc("should now have returned values from table 2 key3=%s and key4=%d\n",get3, get4);
	// Test duplicate key but in different table
	luakv_putstring(L,"key3","default_value3");
	printc("stored key3=default_value3 in default table\n");
	char *default3 = luakv_getstring(L,"key3");
	char *bytable3 = luakv_getstring_bytable(L,"key3", "TABLE2");
	printc("Pulled key3 from both tables. DEFAULT=%s and TABLE2=%s\n", default3, bytable3);
	
	// Closes lua
	lua_close(L);
	printc("lua_state has been closed\n");
	return;
}



