
pre: first all
first:
	@echo PRE
	$(info |     [CP]  Copying lua library)
	@cp $(LUAOBJ) .

C_OBJS=h.o
ASM_OBJS=
COMPONENT=hello.o
INTERFACES=
IF_LIB=$(LUAOBJ)
DEPENDENCIES=sched printc

include ../../Makefile.subsubdir
