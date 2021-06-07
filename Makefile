double-pendulum : main.o init.o utils.o methods.o
	gcc -o double-pendulum main.o init.o utils.o  methods.o

main.o : src/main.c
	gcc -c src/main.c

init.o : src/init.c
	gcc -c src/init.c

utils.o: src/utils.c
	gcc -c src/utils.c

methods.o : src/methods.c
	gcc -c src/methods.c

clean :
	rm double-pendulum main.o init.o utils.o methods.o
