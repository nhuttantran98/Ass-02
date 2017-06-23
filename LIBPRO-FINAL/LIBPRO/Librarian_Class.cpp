#include "Librarian_Class.h"



//nhap va tra ve cac thanh vien Private cua class Time
void Time::setDay(int a) {
	Day = a;
}

void Time::setMonth(int a) {
	Month = a;
}

void Time::setYear(int a) {
	Year = a;
}

int Time::getDay() {
	return Day;
}

int Time::getMonth() {
	return Month;
}

int Time::getYear() {
	return Year;
}

int Time::NumberDayofYear() {
	if ((getYear() % 4 == 0 && getYear() % 100 != 0) || (getYear() % 400 == 0)) return 366;
	else return 365;
}

int Time::NumberDayofMonth() {
	int day;
	if (getMonth() == 4 || getMonth() == 6 || getMonth() == 9 || getMonth() == 11) {
		day = 30;
	}
	if (getMonth() == 2) {
		if (NumberDayofYear() == 366) day = 29;
		if (NumberDayofYear() == 365) day = 28;
	}
	else day = 31;
	return day;
}

int Time::PositionofDay() {
	int N = 0;
	for (int i = 1; i < getMonth(); ++i) N = N + NumberDayofMonth();
	return (N + getDay());
}

int Time::NumberDayofNYear(Time nam1, Time nam2) {
	int N = 0, i = nam1.getYear() + 1;
	for (i; i < nam2.getYear(); ++i) N = N + nam2.NumberDayofYear();
	return N;
}


//nhap va tra ve cac thanh vien Private cua class Book
void Book::setBookID(char a[]) {
	strcpy_s(this->BookID, a);
}

void Book::setBookName(char a[]) {
	strcpy_s(this->BookName, a);
}

void Book::setCategory(char a[]) {
	strcpy_s(this->Category, a);
}

void Book::setPublisher(char a[]) {
	strcpy_s(this->Publisher, a);
}

void Book::setTotal(int a) {
	Total = a;
}

void Book::setCurrent(int a) {
	Current = a;
}

void Book::setBorrowedTimes(int a) {
	BorrowedTimes = a;
}

char* Book::getBookID() {
	return this->BookID;
}

char* Book::getBookName() {
	return this->BookName;
}

char* Book::getCategory() {
	return this->Category;
}

char* Book::getPublisher() {
	return this->Publisher;
}

int Book::getTotal() {
	return Total;
}

int Book::getCurrent() {
	return Current;
}

int Book::getBorrowedTimes() {
	return BorrowedTimes;
}

//nhap va tra ve cac thanh vien Private cua class BorrowSheet
void BorrowedSheet::setSheetID(char a[]) {
	strcpy_s(this->SheetID, a);
}
			 
void BorrowedSheet::setRenter(char a[]) {
	strcpy_s(this->Renter, a);
}
			 
void BorrowedSheet::setStatus(char a[]) {
	strcpy_s(this->Status, a);
}

void BorrowedSheet::setBorrowedDate(Time a) {
	BorrowedDate.setDay(a.getDay());
	BorrowedDate.setMonth(a.getMonth());
	BorrowedDate.setYear(a.getYear());
}

void BorrowedSheet::setBorrowedBookNum(int a) {
	BorrowedBookNum = a;
}

void BorrowedSheet::setisReturn(bool a) {
	isReturn = a;
}

char* BorrowedSheet::getSheetID() {
	return this->SheetID;
}

char* BorrowedSheet::getRenter() {
	return this->Renter;
}

char * BorrowedSheet::getStatus() {
	return this->Status;
}

Time BorrowedSheet::getBorrowedDate() {
	return BorrowedDate;
}

int BorrowedSheet::getBorrowedBookNum() {
	return BorrowedBookNum;
}

bool BorrowedSheet::getisReturn() {
	return isReturn;
}