.PHONY: all clean

OBJ=list
EXE=main

all: main.o liblist.so
        gcc -fPIC -o $(EXE) main.o -L . -llist

clean:
        rm -f $(OBJ)/*.o $(EXE) *.o *.so

main.o: main.c
        gcc -c -o main.o main.c

$(OBJ)/list.o: $(OBJ)/list.c $(OBJ)/list.h
        gcc -fPIC -c $(OBJ)/list.c -o $(OBJ)/list.o

liblist.so: $(OBJ)/list.o
        gcc -fPIC -shared -o liblist.so $(OBJ)/list.c
