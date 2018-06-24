
CC=gcc
CFLAGS=-I. -I./include  -ggdb

OBJ_DIR = ./obj
SOURCE_DIR=./src
TEST_DIR=./test
BIN_DIR=./bin
OUT_DIR=./out

OBJS=$(wildcard **/*.o) $(wildcard *.o)

.PHONY: clean dirs all

all: clean dirs testeOnibus.o dadosOnibus.o utils.o
	make testeOnibus

dirs:
	mkdir out/ obj/

teste.o: ${TEST_DIR}/teste.c 
	$(CC) -c  -o ${OBJ_DIR}/$@ $< $(CFLAGS)

teste: ${OBJS}
	$(CC) -o ${TEST_DIR}/$@ ${OBJS}  $(CFLAGS)


testeOnibus.o: testeOnibus.c 
	$(CC) -o ${OBJ_DIR}/$@ -c $< $(CFLAGS)

%.o: ${SOURCE_DIR}/%.c 
	$(CC) -o ${OBJ_DIR}/$@ -c $< $(CFLAGS)

testeOnibus : ${OBJS}
	$(CC) -o ${OUT_DIR}/$@ ${OBJS} $(CFLAGS)

clean:
	rm -rf  *.o **/*.o out/* out/ obj/
