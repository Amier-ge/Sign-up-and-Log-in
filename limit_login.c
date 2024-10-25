#include "myheader.h"

void gotoxy(int column, int row) {

	static HANDLE	h = NULL;
	COORD			c = {column, row};

	if(!h) {
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	SetConsoleCursorPosition(h, c);
}

int limit_login(int count) {

	int i = 0, k = 0;
	double limit_time = 0.0;
	time_t start_time, current_time;

	start_time = time(NULL);

	if(count == 5) {

		system("cls");
		gotoxy(COLUMN - 6, ROW - 1);

		printf("<<%d minute Limit>>", count);

		while(limit_time < LIMIT_LOGIN * 60.0) {

			current_time = time(NULL);
			limit_time = difftime(current_time, start_time);

			gotoxy(COLUMN + i, ROW);
			if(k == 0) printf("¡Ú");
			else if(k == 1) printf("¡Ù");
			else if(k == 2) printf("  ");

			Sleep(700);
			i += 2;

			if(i > 4) {
				i = 0;
				k++;
				if(k == 3) k = 0;
			}
		}
		system("cls");
	}

	else if(count == 10) {
	
		system("cls");
		gotoxy(COLUMN - 6, ROW - 1);

		printf("<<%d minute Limit>>", count);

		while(limit_time < LIMIT_LOGIN * 2 * 60.0) {

			current_time = time(NULL);
			limit_time = difftime(current_time, start_time);

			gotoxy(COLUMN + i, ROW);
			if(k == 0) printf("¡Ú");
			else if(k == 1) printf("¡Ù");
			else if(k == 2) printf("  ");

			Sleep(700);
			i += 2;

			if(i > 4) {
				i = 0;
				k++;
				if(k == 3) k = 0;
			}
		}
		system("cls");
	}

	else if(count >= 15) {

		system("cls");
		puts("Try again Tomorrow");
		return 1;
	}

	return 0;
}