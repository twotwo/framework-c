INC=-I/usr/local/include/CUnit
LIB=-L/usr/local/lib/

CFLAGS = $(INC) $(LIB) $^ -lcunit


OBJ_DIR = build/obj/

objects = \
	$(OBJ_DIR)suite_sprintf.o \
	$(OBJ_DIR)suite_sscanf.o \
	$(OBJ_DIR)cunit_main.o

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CFLAGS += -static
endif

UNAME_P := $(shell uname -p)

ifeq ($(UNAME_P),x86_64)
	CFLAGS += -D AMD64
endif
ifneq ($(filter %86,$(UNAME_P)),)
	CFLAGS += -D IA32
endif
ifneq ($(filter arm%,$(UNAME_P)),)
	CFLAGS += -D ARM
endif



all:  $(objects)
	    $(CC)  -o build/test $(CFLAGS)
		build/test

$(OBJ_DIR)suite_sprintf.o:
	$(CC) -o $(OBJ_DIR)suite_sprintf.o -c suite_sprintf.c

$(OBJ_DIR)suite_sscanf.o:
	$(CC) -o $(OBJ_DIR)suite_sscanf.o -c suite_sscanf.c

$(OBJ_DIR)cunit_main.o: suite_sprintf.h suite_sscanf.h
	$(CC) -o $(OBJ_DIR)cunit_main.o -c cunit_main.c

# phony target, only action target
clean:
	rm -rf build
	mkdir -p $(OBJ_DIR)