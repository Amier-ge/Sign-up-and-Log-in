#ifndef _MY_HEADER_H
#define _MY_HEADER_H

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

#define NAME_LEN			100
#define ID_LEN				80
#define PASSWORD_LEN			80
#define USER_MAX			80

#define MIN_ID_LEN			5
#define MAX_ID_LEN			13
#define MIN_PASSWORD_LEN		8
#define MAX_PASSWORD_LEN		15
#define MIN_PASSWORD_TYPE		3
#define WRONG_LOGIN			5
#define RESTRICT_TIME			5

typedef struct _USER {

	char name[80];
	char id[80];
	char password[80];
} USER;

void user(USER *);
int login_or_sign_up();

// Login code
int login_page(char *, char *, int, USER *);
int check_ID(char *, char *, int, USER );
int check_PASSWORD(char *, char *, int, USER *);
void login(char *, char *, int *, USER *);

// Sign up code
void again_ID(char *, char *, char *);
void again_PASSWORD(char *, char *, char *);
int sign_up_page(char *, char *, char *);
int check_overlap(char *, char *, char *, USER *);
int check_ID_len(char *, char *, char *);
int check_PASSWORD_len(char *, char *, char *);
int check_PASSWORD_type(char *, char *, char *);
int confirm(char *, char *, char *);
void sign_up(char *, char *, char *, USER *);

#endif
