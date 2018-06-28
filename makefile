
CC=gcc
CFLAGS=-I. -I./include  -ggdb

OBJ_DIR = ./obj
SOURCE_DIR=./src
TEST_DIR=./test
BIN_DIR=./bin
OUT_DIR=./out

OBJS=$(wildcard **/*.o) $(wildcard *.o)
TEST_OBJS := $(filter-out obj/testeOnibus.o, ${OBJS})

.PHONY: clean dirs all

all: clean dirs testeOnibus.o dadosOnibus.o helpers.o
	make testeOnibus

dirs:
	mkdir out/ obj/

teste.o: ${TEST_DIR}/teste.c 
	$(CC) -c  -o ${OBJ_DIR}/$@ $< $(CFLAGS)

teste: ${TEST_OBJS}
	$(CC) -o ${TEST_DIR}/$@ $^  $(CFLAGS)


testeOnibus.o: testeOnibus.c 
	$(CC) -o ${OBJ_DIR}/$@ -c $< $(CFLAGS)

%.o: ${SOURCE_DIR}/%.c 
	$(CC) -o ${OBJ_DIR}/$@ -c $< $(CFLAGS)

testeOnibus : ${OBJS}
	$(CC) -o ${OUT_DIR}/$@ ${OBJS} $(CFLAGS)

clean:
	rm -rf  *.o **/*.o out/* out/ obj/
