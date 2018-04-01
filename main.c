
#include <locale.h>
#include <curses.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 65536

int main(int argc, char** argv){

	int width,height;

	int i,j;

	int input;

	int random;

	unsigned char running = 1;

	char buffer[MAX_BUFFER_SIZE];

	/* Curses initialisation */

	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();

	curs_set(0);

	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);

	/* Execution */

	getmaxyx(stdscr,height,width);

	while (running){
		for (i = 0; i < height; i++){
			for (j = 0; j < width; j++){
				random = rand() % 2;

				switch (random){
					case 0:
						buffer[j] = '\\';
						break;
					case 1:
						buffer[j] = '/';
						break;
					default:
						printf("WIZARDRY");

						endwin();
						return -1;
						break;
				}
			}
			buffer[j] = 0;
			mvprintw(i,0,"%s",buffer);
		}

		refresh();
		
		input = getch();
		running = input == 'q' ? 0 : 1;
	}

	endwin();

	return 0;

}
