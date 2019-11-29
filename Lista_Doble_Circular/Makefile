cola.o: listaDobcir.c
	gcc listaDobcir.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o listaDobcir.o
	gcc main.o listaDobcir.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o listaDobcir.o
