
all: useless_labyrinth

useless_labyrinth: main.c
	gcc -Wall -ansi -pedantic -o $@ $< -lcurses

clean:
	rm -f useless_labyrinth
