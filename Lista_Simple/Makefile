cola.o: listaSimple.c
	gcc listaSimple.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o listaSimple.o
	gcc main.o listaSimple.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o listaSimple.o
