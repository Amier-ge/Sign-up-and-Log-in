#include "myheader.h"

int login_page(char *id, char *password, int *index, USER *user_) {

	printf("<<LOGIN>>\n\n");
	printf("ID : ");
	scanf("%s", id);
	printf("PASSWORD : ");
	scanf("%s", password);

	return 0;
}

int check_ID(char *id, char *password, int *index, USER *user_) {

	int i;

	for(i = 0 ; strcmp(user_[i].id, "") != 0 ; i++) {

		if( strcmp(user_[i].id, id) == 0 ) {
		
			*index = i;
			return 0;
		}
	}

	system("cls");
	printf("Wrong ID!!\n\n");

	return 1;
}

int check_PASSWORD(char *id, char *password, int *index, USER *user_) {

	if( strcmp(user_[*index].password, password) == 0 ) return 0;

	else {

		system("cls");
		printf("Wrong PASSWORD!!\n\n");

		return  1;
	}
}

int login(char *id, char *password, int *index, USER *user_) {

	int i, check, count = 0;
	int (*login_func[3])(char *, char *, int *, USER *) = {login_page, check_ID, check_PASSWORD};
	
	do{

		for(i = 0 ; i < 3 ; i++) {

			check = login_func[i](id, password, index, user_);
		
			if(check) {

				count++;
				break;
			}
		}

		if(count >= 5) {
			
			if( limit_login(count) ) return 0;
		}

	} while(check);

	system("cls");
	printf("User : %s\nWELCOME!!\n\n", user_[*index].name);
}
