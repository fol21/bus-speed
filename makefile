
CC=gcc
CFLAGS=-I. -I./include
OBJ_DIR = ./obj
OBJS=$(wildcard **/*.o)
SOURCE_DIR=./src
TEST_DIR=./test

.PHONY: clean

testeOnibus.o: ${TEST_DIR}/testeOnibus.c 
	$(CC) -c -o ${OBJ_DIR}/$@ $< $(CFLAGS)

testeOnibus: ${OBJS}
	$(CC) -o ${TEST_DIR}/$@ ${OBJS} $(CFLAGS)

%.o: ${SOURCE_DIR}/%.c 
	$(CC) -c -o ${OBJ_DIR}/$@ $< $(CFLAGS)



clean:
	rm -rf **/*.o 
