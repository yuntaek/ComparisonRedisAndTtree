SHELL = /bin/sh
CC = gcc

prefix = /usr/service
INSTALL_DIR         = ${DESTDIR}${prefix}

# this is in the .bash_profile

BASE		= $(shell pwd | sed -e 's/src$$//')
BIN_DIR			= $(BASE)bin
LIB_DIR			= $(BASE)lib
SOURCE_DIR		= $(BASE)src

DEBUGOPT	= -Wall -g -ggdb3 -std=gnu99

INCLUDEFLAGS= -I. -I$(BASE)header

CFLAGS	= $(DEBUGOPT) $(INCLUDEFLAGS)
VERSION = $(shell echo gmstm_2.0.0_`date +%Y%m%d` for DEBUG)

LDFLAGS	=-L. -L${LIB_DIR}
LDLIBS = -lhiredis

PROGRAM = crat

OBJS = main.o redis.o
		

all: $(PROGRAM)



$(PROGRAM): $(OBJS)
	@echo "Loading $(PROGRAM)"
	$(CC) $(CFLAGS) $(INCLUDE) -o $(BIN_DIR)/$(PROGRAM) $(OBJS) $(LDFLAGS) $(LDLIBS)
	@echo "Done."


.c.o:
	$(CC) $(CFLAGS) -c $<


version.c:
	echo "char *Version=\""$(VERSION)"\";" > version.c

clean:
	@rm -f version.c
	@rm -f *.o $(PROGRAM)

#install: ${PROGRAM}
#mkdir -p ${INSTALL_DIR}/bin
#	mkdir -p ${INSTALL_DIR}/etc
#	rm -f ${INSTALL_DIR}/bin/${PROGRAM}
#	cp -f ${BIN_DIR}/${PROGRAM} ${INSTALL_DIR}/bin
#	cp -f ${SOURCE_DIR}/dsm.init ${INSTALL_DIR}/bin
#	cp -f ${ETC_DIR}/dsm.conf ${INSTALL_DIR}/etc/gmstm2.conf.default
