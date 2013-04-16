#
# Copyright (c) 2001, 2002 Swedish Institute of Computer Science.
# All rights reserved. 
# 
# Redistribution and use in source and binary forms, with or without modification, 
# are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission. 
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
# SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
# OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
# IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
# OF SUCH DAMAGE.
#
# This file is part of the lwIP TCP/IP stack.
# 
# Author: Adam Dunkels <adam@sics.se>
#
include ../../../../Makefile.src
include ../../../Makefile.comp
$(info $(CINC))

CCDEP=../../dietlibc-0.29/bin-i386/diet gcc
CC=../../dietlibc-0.29/bin-i386/diet gcc
#To compile for linux: make ARCH=linux
#To compile for cygwin: make ARCH=cygwin
#To compile for openbsd: make ARCH=openbsd
#ARCH=openbsd
#gap: CFLAGS=-g -Wall -pedantic -D$(ARCH) -DIPv4 -Os -fpack-struct -DLWIP_DEBUG
OPT=-O3 #-ggdb3
CFLAGS=-Wall -DIPv4 -nostdinc -nostdlib $(OPT)
ARFLAGS=rs

#Set this to where you have the lwip core module checked out from CVS
#default assumes it's a dir named lwip at the same level as the contrib module
LUADIR=../lua-5.2.1/src
DIET=../../dietlibc-0.29
DIETINC=$(DIET)/include
DIETI386=$(DIET)/bin-i386

INCLUDES=-I$(LUADIR)/include -I./include $(CINC) -I$(DIETINC) -I$(DIET)
CFLAGS:=$(CFLAGS) $(INCLUDES)

COREFILES=$(LUADIR)/lapi.c \
$(LUADIR)/lcode.c    \
$(LUADIR)/lctype.c   \
$(LUADIR)/ldebug.c   \
$(LUADIR)/ldo.c      \
$(LUADIR)/ldump.c    \
$(LUADIR)/lfunc.c    \
$(LUADIR)/lgc.c      \
$(LUADIR)/llex.c     \
$(LUADIR)/lmem.c     \
$(LUADIR)/lobject.c  \
$(LUADIR)/lopcodes.c \
$(LUADIR)/lparser.c  \
$(LUADIR)/lstate.c   \
$(LUADIR)/lstring.c  \
$(LUADIR)/ltable.c   \
$(LUADIR)/ltm.c      \
$(LUADIR)/lundump.c  \
$(LUADIR)/lvm.c      \
$(LUADIR)/lzio.c     \
$(LUADIR)/lauxlib.c  \
$(LUADIR)/lbaselib.c \
$(LUADIR)/lbitlib.c  \
$(LUADIR)/lcorolib.c \
$(LUADIR)/ldblib.c   \
$(LUADIR)/liolib.c   \
$(LUADIR)/lmathlib.c \
$(LUADIR)/loslib.c   \
$(LUADIR)/lstrlib.c  \
$(LUADIR)/ltablib.c  \
$(LUADIR)/loadlib.c  \
$(LUADIR)/linit.c    

DIETMATH=$(DIET)/libm/sinh.c  \
$(DIET)/libm/modf.c  \
$(DIET)/libm/tanh.c  \
$(DIET)/libm/rint.c  \
$(DIET)/libm/bessel.c \
$(DIET)/libm/bessel.c \
$(DIET)/libm/erf.c   \
$(DIET)/libm/erf.c   \
$(DIET)/libm/cosh.c  \
$(DIET)/libm/ipow.c  \
$(DIET)/libm/gamma.c \
$(DIET)/libm/gamma.c \
$(DIET)/libm/poly.c  \
$(DIET)/libm/pow.c   

DIETMIPS=$(DIET)/mips/divdi3.c

DIETMATHOBJ=$(DIET)/bin-i386/libm2.o \
$(DIETI386)/acos.o   \
$(DIETI386)/asin.o   \
$(DIETI386)/atan.o   \
$(DIETI386)/ceil.o   \
$(DIETI386)/cos.o    \
$(DIETI386)/exp.o    \
$(DIETI386)/fabs.o   \
$(DIETI386)/floor.o  \
$(DIETI386)/hypot.o  \
$(DIETI386)/log.o    \
$(DIETI386)/log10.o  \
$(DIETI386)/sin.o    \
$(DIETI386)/sqrt.o   \
$(DIETI386)/sincos.o \
$(DIETI386)/__half.o \
$(DIETI386)/ldexp.o  \
$(DIETI386)/log1p.o  \
$(DIETI386)/fmod.o   \
$(DIETI386)/libm2.o  \
$(DIETI386)/atan2.o  \
$(DIETI386)/tan.o    

DIETLIBCA=$(DIETI386)/dietlibc.a


# SNMPFILES: Extra SNMPv1 agent
# SNMPFILES=$(LUADIR)/core/snmp/asn1_dec.c $(LUADIR)/core/snmp/asn1_enc.c \
# 	$(LUADIR)/core/snmp/mib2.c $(LUADIR)/core/snmp/mib_structs.c \
# 	$(LUADIR)/core/snmp/msg_in.c $(LUADIR)/core/snmp/msg_out.c lwip_prvmib.c

# NETIFFILES: Files implementing various generic network interface functions.'
#NETIFFILES=$(LUADIR)/netif/etharp.c mintapif.c

# LWIPFILES: All the above.
LUAFILES=$(COREFILES) $(DIETMATH) $(DIETMIPS)
LUAFILESW=$(wildcard $(LUAFILES))
LUAOBJS=$(notdir $(LUAFILESW:.c=.o)) $(DIETLIBCA) $(DIETMATHOBJ)

OUTPUT_OBJ=lua_lang.o
# APPFILES
#APPFILES=echo.c timer.c

#LWIPLIB=liblwip4.a
#APPLIB=liblwipapps.a
#APPOBJS=$(notdir $(APPFILES:.c=.o))

#all ipv4 compile: echop
all: .depend $(OUTPUT_OBJ)
.PHONY: all

clean:
	rm -f *.o $(OUTPUT_OBJ) .depend* 

depend dep: .depend

include .depend

.depend: $(LUAFILES) 
	$(CCDEP) $(CFLAGS) -MM $^ > .depend || rm -f .depend

$(OUTPUT_OBJ): $(LUAOBJS)
	ld -r -o $@ $^

%.o:
	$(CC) $(CFLAGS) -c $(<:.o=.c) 
