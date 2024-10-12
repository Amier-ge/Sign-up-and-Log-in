#include "myheader.h"

int login_or_sign_up() {

	int login_or_sign_up;

	while(1) {

		puts("WELCOME TO PORTAL!\n");
		puts("ич LOGIN\nиш SIGN UP");
		printf("бц ");
		scanf("%d", &login_or_sign_up);

		if( (login_or_sign_up != 1) && (login_or_sign_up != 2) ) printf("PICK ич or иш\n");
		else break;
	}

	system("cls");

	return login_or_sign_up;
}