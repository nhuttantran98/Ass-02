#ifndef librarian_class
#define librarian_class

#include"Main_Class.h"

class Time {
private:
	int Day, Month, Year;
public:
	//setter and getter
	void setDay(int a);
	void setMonth(int a);
	void setYear(int a);
	int getDay();
	int getMonth();
	int getYear();
	//other function
	int NumberDayofYear();
	int NumberDayofMonth();
	int PositionofDay();//tinh so ngay tu dau nam cho toi ngay hien tai
	int NumberDayofNYear(Time nam1, Time nam2);
};

class Book{
protected:
	char BookID[maxElements];
private:
	char BookName[maxElements], Category[maxElements], Publisher[maxElements];
	int Total, Current, BorrowedTimes;
public:
	void setBookID(char a[]);//cu phap ID sach:<ten_the_loai><ma_so>
	void setBookName(char a[]);
	void setCategory(char a[]);
	void setPublisher(char a[]);
	void setTotal(int a);
	void setCurrent(int a);
	void setBorrowedTimes(int a);
	char* getBookID();
	char* getBookName();
	char* getCategory();
	char* getPublisher();
	int getTotal();
	int getCurrent();
	int getBorrowedTimes();
};

class BorrowedSheet:public Book{	
private:
	char SheetID[maxElements], Renter[maxElements], Status[maxElements];//tinh trang sach
	Time BorrowedDate;
	int BorrowedBookNum;
	bool isReturn;
public:
	void setSheetID(char a[]);
	void setRenter(char a[]);
	void setStatus(char a[]);
	void setBorrowedDate(Time a);
	void setBorrowedBookNum(int a);
	void setisReturn(bool a);
	char* getSheetID();
	char* getRenter();
	char* getStatus();
	Time getBorrowedDate();
	int getBorrowedBookNum();
	bool getisReturn();
};

#endif // !librarian_class

