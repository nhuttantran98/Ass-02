#ifndef reader
#define reader

#include"Main_Class.h"
#include"Librarian_Class.h"
#include"UM.h"
#include"Lib.h"

void BorrowBook(vector<BorrowedSheet> &a, vector<Book> &b, BorrowedSheet &c, User d, bool isGet) {
	char input[maxElements];
	int inputnumber, test = -1;
	int bookSelected = 0;
	bool check = false;//kiem tra het hang:false la chua het, true la da het
					   //kiem tra trung khop voi tai khoan thuoc thu vien, true la trung, false khong trung

	do {
		cout << "\nNhap ma so phieu muon: ";
		cin.ignore();
		fflush(stdin);
		cin.getline(input, maxElements);
		test = findSheetID(a, input);
		if (test != -1) {
			cout << "\nMa so phieu muon nay da ton tai. Vui long nhap lai...\n";
		}
	} while (test != -1);
	c.setSheetID(input);

	do {
		cout << "\nNhap ma so sach muon muon: ";
		fflush(stdin);
		cin.getline(input, maxElements);
		check = checkOutofStock(b, input);
		bookSelected = findBookID(b, input);
		if (check == true) {
			cout << "\nMa sach khong ton tai hoac dau sach nay da duoc muon het. Vui long nhap lai...\n";
		}
		else break;
	} while (check = true);
	c.setBookID(input);

	
	c.setRenter(d.getName());

	c.setStatus("OK");

	//lay thoi gian la thoi gian thuc cua he thong
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	Time today;
	today.setDay(newtime.tm_mday);
	today.setMonth(newtime.tm_mon + 1);
	today.setYear(newtime.tm_year + 1900);
	c.setBorrowedDate(today);

	cout << "\nNhap so luong sach: ";
	cin >> inputnumber;

	c.setBorrowedBookNum(inputnumber);
	b[bookSelected].setCurrent(b[bookSelected].getCurrent() - c.getBorrowedBookNum());
	c.setisReturn(isGet);//chua tra->false, da tra->true

	a.push_back(c);

	cout << "\nTHAO TAC HOAN TAT\n";
	system("pause");
}

#endif // !reader

