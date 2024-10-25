#include "myheader.h"

void user(USER *user_name) {

	//Add freely
	USER David = {"David", "david123", "ps12345!!"};
	USER Helen = {"Helen", "helen123", "helen123!"};
	USER Christopher = {"Christopher", "chris123", "helloworld123!"};

	user_name[0] = David;
	user_name[1] = Helen;
	user_name[2] = Christopher;
}