CC ?= cc
CFLAGS = -Wall -Wextra -O2 -std=c11

all: gestor

gestor: src/main.c
	$(CC) $(CFLAGS) -o $@ $<

run: gestor
	./gestor notas.txt

clean:
	rm -f gestor

.PHONY: all run clean
