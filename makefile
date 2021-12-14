CC=gcc
AR=ar
FLAGS=-Wall -g
LIBS=-lm
OBJECTS_PROG=stringProg.o
OBJECTS_STR_FUNCS=my_funcs.o

all: libmyfuncs.a libmyfuncs.so connections connectionsd

connections:	$(OBJECTS_PROG) libmyfuncs.a #static
	$(CC) $(FLAGS) -o connections $(OBJECTS_PROG) libmyfuncs.a $(LIBS)
connectionsd:	$(OBJECTS_PROG) libmyfuncs.so #dynamic
	$(CC) $(FLAGS) -o connectionsd $(OBJECTS_PROG) ./libmyfuncs.so $(LIBS)

libmyfuncs.a:	$(OBJECTS_STR_FUNCS)
	$(AR) -rcs libmyfuncs.a $(OBJECTS_STR_FUNCS)
libmyfuncs.so:	$(OBJECTS_STR_FUNCS)
	$(CC) $(FLAGS) -shared -o libmyfuncs.so $(OBJECTS_STR_FUNCS)
stringProg.o:	stringProg.c my_funcs.h
	$(CC) $(FLAGS) -c stringProg.c
my_funcs.o:		my_funcs.c my_funcs.h
	$(CC) $(FLAGS) -c my_funcs.c $(LIBS)

.PHONY: clean all

clean: 
	rm -f *.o *.a *.so connections connectionsd