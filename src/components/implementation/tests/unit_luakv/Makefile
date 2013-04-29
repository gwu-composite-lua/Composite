
pre: first all
first:
	@echo PRE
	$(info |     [CP]  Copying lua library)
	@cp $(LUAOBJ) .

C_OBJS=lkv_test.o
COMPONENT=unit_luakv.o
INTERFACES=
IF_LIB=$(LUAOBJ)
DEPENDENCIES=lua_keyval printc

include ../../Makefile.subsubdir
