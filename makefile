
CC = gcc
CFLAGS = -Wall -g
SRC = $(wildcard *.c)
OUT = output/compiler

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: $(OUT)
	./$(OUT)
	
ls: $(OUT)
	./$(OUT) json.json

clean:
	rm -f $(OUT)
