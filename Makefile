a.out: main.o  libass2_12CS30011.a
		cc -m32 main.o -L. -lass2_12CS30011 -g
main.o: main.c
		cc -Wall -m32 -c main.c -g
libass2_12CS30011.a : ass2_12CS30011.o
		ar -rcs libass2_12CS30011.a ass2_12CS30011.o
ass2_12CS30011.o : ass2_12CS30011.c myl.h
		cc -Wall -m32 -c ass2_12CS30011.c -g
clean:
		rm a.out main.o libass2_12CS30011.a ass2_12CS30011.o

