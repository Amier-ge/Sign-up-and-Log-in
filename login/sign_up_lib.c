#include "myheader.h"

int sign_up_page(char *id, char *password, char *name) {

	printf("INPUT YOUR NAME : ");
	scanf("%s", name);

	system("cls");
	puts("\t   INPUT YOUR ID/PASSWORD!");
	puts("<<< PASSWORD ONLY ENGLISH / NUMBER / ! / ? / * / _ >>>\n");
	printf("ID : ");
	scanf("%s", id);
	printf("PASSWORD : ");
	scanf("%s", password);

	return 1;
}

void again_ID(char *id, char *password, char *name) {

	printf("ID : ");
	scanf("%s", id);
}

void again_PASSWORD(char *id, char *password, char *name) {

	puts("<<< PASSWORD ONLY ENGLISH / NUMBER / ! / ? / * / _ >>>\n");
	printf("PASSWORD : ");
	scanf("%s", password);
}

int check_overlap(char *id, char *password, char *name, USER *user_) {

	int i;

	for(i = 0 ; strcmp(user_[i].name, "") != 0 ; i++) {

		if( strcmp(name, user_[i].name) == 0 ) {
			system("cls");
			printf("Already Exist!!\n");
			printf("Please input again.\n\n");
			return 1;
		}
	}

	return 0;
}

int check_ID_len(char *id, char *password, char *name) {

	int id_len;

	id_len = strlen(id);

	if(id_len > MAX_ID_LEN) { // longer than 13

		system("cls");
		puts("TOO LONG ID!\n\n");
		return 1;
	}
	
	else if(id_len < MIN_ID_LEN) { // shorter than 6

		system("cls");
		puts("TOO SHORT ID!\n\n");
		return 1;
	}

	else return 0;
}

int check_PASSWORD_len(char *id, char *password, char *name) {

	int password_len;

	password_len = strlen(password);

	if(password_len > MAX_PASSWORD_LEN) { //longer than 15

		system("cls");
		puts("TOO LONG PASSWORD!\n\n");
		return 1;
	}
	
	else if(password_len < MIN_PASSWORD_LEN) { //shorter than 8
		
		system("cls");
		puts("TOO SHORT PASSWORD!\n\n");
		return 1;
	}

	else return 0;
}

int check_PASSWORD_type(char *id, char *password, char *name) {

	int i = 0;


	for(i = 0 ; *(password + i) != '\0' ; i++) { // Alphabet check

		if( (*(password + i) >= 'a') && (*(password + i) <= 'z') ) break; // Uppercase letter check
		
		else if ( (*(password + i) >= 'A') && (*(password + i) <= 'Z') ) break;// Lowercase letter check
			
		if( *(password + (i + 1) ) == '\0' ) {

			system("cls");
			printf("Your password does not contain any English letters!\n\n");
			return 1;
		}
	}

	for(i = 0 ; *(password + i) != '\0' ; i++) { // Number check

		if( (*(password + i) >= '0') && (*(password + i) <= '9') ) break;

		if( *( password + (i + 1) ) == '\0' ) {

			system("cls");
			printf("Your password does not contain any Numbers!\n\n");
			return 1;
		}
	}

	for(i = 0 ; *(password + i) != '\0' ; i++) { // Character check (!, ?, *, _)

		if( (*(password + i) == '!') || (*(password + i) == '?') || (*(password + i) == '*') || (*(password + i) == '_') ) break;


		if( *(password + (i + 1) ) == '\0' ) {

			system("cls");
			printf("Your password does not contain Characters!\n\n");
			return 1;
		}
	}

	return 0;
}

int confirm(char *id, char *password, char *name) {
	
	int i;
	char word[80];
	char *check;

	system("cls");

	printf("NAME : %s\n\n", name);
	printf("ID : %s\n", id);
	printf("PASSWORD : %s\n\n", password);
	
	printf("Is this correct? (Yes or No) : ");
	scanf("%s", word);

	
	check = (char *)malloc( strlen(word) + 1 );

	if(check == NULL) {
		printf("Function 'confirm', malloc memory Error\n");
		return 2;
	}

	strcpy(check, word);
	for(i = 0 ; *(check + i) != '\0' ; i++) if( ( *(check + i) >= 'a' ) && ( *(check + i) <= 'z') ) *(check + i) -= 32;

	if( strcmp(check, "YES") == 0 ) {
		free(check);
		return 0;
	}

	else if( strcmp(check, "NO") == 0 ) {
		free(check);
		return 1;
	}
}

void sign_up(char *id, char *password, char *name, USER *user_) {

	int (*sign_up_func[4])(char *, char *, char *) = {sign_up_page, check_ID_len, check_PASSWORD_len, check_PASSWORD_type};
	int i, gostop = 0;

	do {

		if( gostop == 2 ) exit(0); // memory Error

		do {
			system("cls");
			sign_up_page(id, password, name);

		} while( check_overlap(id, password, name, user_) );

		for(i = 1 ; i < 4 ; i++){

			if( sign_up_func[i](id, password, name) ) {

				if(i == 1) again_ID(id, password, name);
				else again_PASSWORD(id, password, name);

				i = 1;
			}
		}

		gostop = confirm(id, password, name);

	} while( gostop );

	for(i = 0 ; strcmp(user_[i].name, "") != 0 ; i++);

	strcpy(user_[i].name, name);
	strcpy(user_[i].id, id);
	strcpy(user_[i].password, password);

	system("cls");
}