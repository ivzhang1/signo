signo : signo.o
	gcc -o signo.o signo

signo.o:
	gcc -c signo.c

run:
	./signo
