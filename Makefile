exec = a.out
source = $(wildcard src/*.c)
objects = $(source:.c=.o)
flags = -g -Wall -lm -ldl -fPIC -rdynamic 

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec) 

%.o: %.c %.h
	gcc -c $(flags) $< -o $@

clean:
	-rm *.out
	-rm *.o
	-rm *.a
	-rm src/*.out
lint:
	clang-tidy src/*.c src/include/*.h

