cola.o: cola.c
	gcc cola.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o cola.o
	gcc main.o cola.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o cola.o
