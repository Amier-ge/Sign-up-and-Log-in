#include "myheader.h"

int login_or_sign_up() {

	int login_or_sign_up;

	while(1) {

		puts("WELCOME TO PORTAL!\n");
		puts("�� LOGIN\n�� SIGN UP");
		printf("�� ");
		scanf("%d", &login_or_sign_up);

		if( (login_or_sign_up != 1) && (login_or_sign_up != 2) ) printf("PICK �� or ��\n");
		else break;
	}

	system("cls");

	return login_or_sign_up;
}