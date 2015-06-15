CC = gcc
LDFLAGS += -lX11 -lXtst

all: steamIA

steamIA : steamIA.c
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ $<
