CC = gcc
CFLAGS = -I include -g -std=c11
SRC = $(wildcard *.c src/*.c)
HEAD = $(wildcard include/*.h)
OBJ = $(SRC:.c=.o)
EXEC = bin/tera
WIN_EXEC=bin/tera.exe

all: clean $(OBJ) $(EXEC) $(HEAD)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@
	$(CC) $^ -o $(WIN_EXEC)
	rm -rf src/*.o

%.o: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

build:
	make
	cd bin
	zip tera.zip ./tera
	zip windows.zip ./$(WIN_EXEC)
	cd ..
	make clean

install:
	chmod +x install.sh
	./install.sh

clean:
	rm -rf *.o src/*.o $(EXEC) $(WIN_EXEC)