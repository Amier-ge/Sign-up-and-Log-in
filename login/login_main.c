#include "myheader.h"

int main() {
	
	char id[ID_LEN] = {0};
	char password[PASSWORD_LEN] = {0};
	char name[NAME_LEN] = {0};
	USER user_name[USER_MAX] = {0};
	int index = 0;
	
	user(user_name);

	if( login_or_sign_up() == 2 ) sign_up(id, password, name, user_name);	// Sign up

	login(id, password, &index, user_name);

	return 0;
}