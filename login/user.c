#include "myheader.h"

void user(USER *user_name) {

	//Add freely
	USER David = {"David", "daiocd", "ps12345!!"};
	USER Helen = {"Helen", "jinvdef", "lgehelen105!"};
	USER Christopher = {"Christopher", "daypretty", "helloworld123!"};

	user_name[0] = David;
	user_name[1] = Helen;
	user_name[2] = Christopher;
}