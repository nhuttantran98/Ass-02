#include"Main_Class.h"
//nhap vao va tra ve gia tri cua cac thanh vien Private cua class Account

void Account::setAccountName(char a[]) {
	strcpy_s(this->AccountName, a);
}
char* Account::getAccountName() {
	return this->AccountName;
}
void Account::setPassword(char a[]) {
	strcpy_s(this->Password, a);
}
char* Account::getPassword() {
	return this->Password;
}
void Account::setisActived(bool a) {
	isActived = a;
}
bool Account::getisActived() {
	return isActived;
}
void Account::setAccountID(int a) {
	AccountID = a;
}
int Account::getAccountID() {
	return AccountID;
}
//nhap vao va tra ve gia tri cua cac thanh vien Private cua class User

void User::setUserID(int a) {
	UserID = a;
}
void User::setName(char a[]) {
	strcpy_s(this->Name, a);
}
void User::setIdentityCard(char a[]) {
	strcpy_s(this->IdentityCard, a);
}
void User::setSex(char a[]) {
	strcpy_s(this->Sex, a);
}
void User::setBirthday(char a[]) {
	strcpy_s(this->Birthday, a);
}
void User::setJob(char a[]) {
	strcpy_s(this->Job, a);
}
void User::setEmail(char a[]) {
	strcpy_s(this->Email, a);
}
int User::getUserID() {
	return UserID;
}
char* User::getName() {
	return this->Name;
}
char* User::getIdentityCard() {
	return this->IdentityCard;
}
char* User::getSex() {
	return this->Sex;
}
char* User::getBirthday() {
	return this->Birthday;
}
char* User::getJob() {
	return this->Job;
}
char* User::getEmail() {
	return this->Email;
}

//nhap vao va tra ve gia tri cua cac thanh vien Private cua class Role
void Role::setRoleID(int a) {
	RoleID = a;
}
int Role::getRoleID() {
	return RoleID;
}
void Role::setRoleDescription(char a[]) {
	strcpy_s(this->RoleDescription, a);
}
char* Role::getRoleDescription() {
	return this->RoleDescription;
}
//nhap vao va tra ve gia tri cua cac thanh vien Private cua class RoleVsAccount
void RoleOfAccount::set_AccountID(int a) {
	_AccountID = a;
}
int RoleOfAccount::get_AccountID() {
	return _AccountID;
}
void RoleOfAccount::set_RoleID(int a) {
	_RoleID = a;
}
int RoleOfAccount::get_RoleID() {
	return _RoleID;
}

