# Makefile

CC=clang
FLAGS= -Wall
OUTPUT=output

all:
	$(CC) -S operations.c
	$(CC) $(FLAGS) operations.c -o $(OUTPUT)
	chmod +x ./$(OUTPUT)
exec:
	./$(OUTPUT)
clean:
	rm -f *.o output
