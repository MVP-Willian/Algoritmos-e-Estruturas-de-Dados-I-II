CC = gcc
LDFLAGS = -lm
TARGET = src/experimento

SRCS = src/main.c src/hash.c src/arquivo.c src/tempo.c src/arvore.c src/listaEncadeada.c

all:
	$(CC) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)