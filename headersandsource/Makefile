all: build

build: clean main.o multiply.o
	@gcc -Xlinker bin/*.o -o bin/mutliply

main.o: 
	@gcc -c main.c -o bin/main.o -I multiply/include

multiply.o:
	@gcc -c multiply/lib/multiply.c -o bin/multiply.o

clean:
	@rm -rf bin/*
