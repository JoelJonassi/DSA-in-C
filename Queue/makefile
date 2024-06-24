all: queue.o main.o
	gcc -o all main.o queue.o
	rm -f *.o
main.o: main.c queue.h
	gcc -c main.c
queue.o: queue.c queue.h
	gcc -c queue.c
clean:
	rm -f *.o  *.c.swo *.c.swp *.h.swp all
