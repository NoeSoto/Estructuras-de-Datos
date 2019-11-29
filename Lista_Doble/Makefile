cola.o: listaDoble.c
	gcc listaDoble.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o listaDoble.o
	gcc main.o listaDoble.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o listaDoble.o
