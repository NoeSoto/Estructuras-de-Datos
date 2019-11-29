listaCircular.o: listaCircular.c
	gcc listaCircular.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o listaCircular.o
	gcc main.o listaCircular.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o listaCircular.o
