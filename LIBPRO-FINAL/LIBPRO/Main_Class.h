#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<cstring>
#include<random>
#include<ctype.h>

using namespace std;

#define numRole 7
#define maxElements 100

class Account {
private:
	char Password[maxElements];
	int AccountID;
	char AccountName[maxElements];//thong tin nay khong duoc trung nhau
	bool isActived;
public:
	void setAccountID(int a);
	void setAccountName(char a[]);
	void setPassword(char a[]);
	void setisActived(bool a);
	int getAccountID();
	char* getAccountName();
	char* getPassword();
	bool getisActived();
};

class User {
private:
	int UserID;
	char Name[maxElements];
	char IdentityCard[maxElements];//CMND can co 9 chu so
	char Sex[maxElements];
	char Birthday[maxElements];
	char Job[maxElements];
	char Email[maxElements];
public:
	void setUserID(int a);
	void setName(char a[]);
	void setIdentityCard(char a[]);
	void setSex(char a[]);
	void setBirthday(char a[]);
	void setJob(char a[]);
	void setEmail(char a[]);
	int getUserID();
	char* getName();
	char* getIdentityCard();
	char* getSex();
	char* getBirthday();
	char* getJob();
	char* getEmail();
};

class Role {
private:
	int RoleID;
	char RoleDescription[maxElements];
public:
	void setRoleID(int a);
	void setRoleDescription(char a[]);
	int getRoleID();
	char* getRoleDescription();
};

class RoleOfAccount{
private:
	int _AccountID;
	int _RoleID;
public:
	void set_AccountID(int a);
	int get_AccountID();
	void set_RoleID(int a);
	int get_RoleID();
};