#ifndef lib
#define lib

#include"Librarian_Class.h"


//xac dinh doi tuong co ID trong mang Book trung voi tim kiem cua nguoi dung 
int findBookID(vector<Book> &a, char inputBookID[]) {
	int bookSelected = -1;
	int size = a.size();
	for (int i = 0; i < size; i++) {
		if (strcmp(a[i].getBookID(), inputBookID) == 0) {
			bookSelected = i;
			break;
		}
	}
	return bookSelected;
}

//dang ki thong tin dau sach moi
void addBooks(vector<Book> &a, Book &b) {
	char input[maxElements];
	int inputnumber;
	int check = -1;

	cin.ignore();
	do {
		cout << "\nMa so sach: "; 
		fflush(stdin);
		cin.getline(input, maxElements);
		check = findBookID(a, input);
		if (check != -1) {
			cout << "\nMa so sach nay da ton tai. Vui long kiem tra lai...\n\n";
			system("pause");
		}
	} while (check != -1);
	b.setBookID(input);

	cout << "\nTen sach: ";
	fflush(stdin);
	cin.getline(input, maxElements);
	b.setBookName(input);

	cout << "\nThe loai: ";
	fflush(stdin);
	cin.getline(input, maxElements);
	b.setCategory(input);

	cout << "\nNha xuat ban: ";
	fflush(stdin);
	cin.getline(input, maxElements);
	b.setPublisher(input);

	cout << "\nTong so luong sach: ";
	cin >> inputnumber;
	b.setTotal(inputnumber);
	b.setCurrent(inputnumber);
	b.setBorrowedTimes(0);

	a.push_back(b);
	cout << "\nTHAO TAC HOAN TAT\n\n";
	system("pause");
}

//xoa sach khoi he thong
void deleteBooks(vector<Book> &a) {
	char input[maxElements];

	cin.ignore();
	cout << "\nNhap ma so sach: ";
	cin.getline(input, maxElements);
	int bookSelected = findBookID(a, input);
	if (bookSelected == -1) cout << "\nMa so sach khong ton tai hoac da xoa. Vui long kiem tra lai...\n\n";
	else {
		if (a[bookSelected].getCurrent() < a[bookSelected].getTotal()) {
			cout << "\nQuyen sach dang duoc cho muon. Ban khong the xoa thong tin sach.\n\n";
		}
		else {
			a.erase(a.begin() + bookSelected);
			cout << "\nTHAO TAC HOAN TAT\n\n";
		}
	}
	system("pause");
}

//sua thong tin sach
void editBooks(vector<Book> &a) {
	char input[maxElements];
	int inputnumber;

	cin.ignore();
	cout << "\nNhap ma so sach: ";
	fflush(stdin);
	cin.getline(input, maxElements);
	int bookSelected = findBookID(a, input);
	if (bookSelected == -1) {
		cout << "\nMa so sach khong ton tai hoac da bi xoa. Vui long kiem tra lai...\n\n";
		system("pause");
	}
	else {
		int borrowTimes = a[bookSelected].getTotal() - a[bookSelected].getCurrent();
		cout << "\nNHAP VAO THONG TIN MOI\n";
		cout << "\nTen sach: ";
		fflush(stdin);
		cin.getline(input, maxElements);
		a[bookSelected].setBookName(input);

		cout << "\nThe loai ";
		fflush(stdin);
		cin.getline(input, maxElements);
		a[bookSelected].setCategory(input);

		cout << "\nNha xuat ban: ";
		fflush(stdin);
		cin.getline(input, maxElements);
		a[bookSelected].setPublisher(input);

		cout << "\nTong so luong sach: ";
		cin >> inputnumber;
		a[bookSelected].setTotal(inputnumber);
		a[bookSelected].setCurrent(inputnumber-borrowTimes);

		cout << "\nTHAO TAC HOAN TAT\n\n";
		system("pause");
	}
}

//hien thi toan bo thong tin cac dau sach hien co trong thu vien
void showListBooks(vector<Book> &a) {
	int size = a.size(); 
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << "Ma so sach	 : " << a[i].getBookID() << endl;
		cout << "Ten sach	 : " << a[i].getBookName() << endl;
		cout << "The loai	 : " << a[i].getCategory() << endl;
		cout << "Nha xuat ban     : "<< a[i].getPublisher() << endl;
		cout << "So luong ban dau : " << a[i].getTotal() << endl;
		cout << "So luong hien tai: " << a[i].getCurrent() << endl;
		cout << "********************************************************" << endl;
	}
	system("pause");
}

//hien thi thong tin dau sach duoc chon
void showBookSelected(vector<Book> &a) {
	char input[maxElements];

	cout << "\nNhap ma so sach: ";
	cin.ignore();
	cin.getline(input, maxElements);
	int bookSelected = findBookID(a, input);
	if (bookSelected == -1) cout << "\nMa so sach khong ton tai. Vui long kiem tra lai...\n\n";
	else {
		cout << endl;
		cout << "Ma so sach	 : " << a[bookSelected].getBookID() << endl;
		cout << "Ten sach	 : " << a[bookSelected].getBookName() << endl;
		cout << "The loai	 : " << a[bookSelected].getCategory() << endl;
		cout << "Nha xuat ban     : " << a[bookSelected].getPublisher() << endl;
		cout << "So luong ban dau : " << a[bookSelected].getTotal() << endl;
		cout << "So luong hien tai: " << a[bookSelected].getCurrent() << endl;
	}
	system("pause");
}

//hien thi thong tin cac dau sach thuoc mot the loai duoc chon
void showListCategory(vector<Book> &a) {
	char input[maxElements];
	int size = a.size();
	int noExist = 0;
	cout << "\nNhap the loai sach muon tim: ";
	cin.ignore();
	cin.getline(input, maxElements);
	for (int i = 0; i < size; i++) {
		if (strcmp(a[i].getCategory(), input) == 0) {
			cout << endl;
			cout << "Ma so sach	 : " << a[i].getBookID() << endl;
			cout << "Ten sach	 : " << a[i].getBookName() << endl;
			cout << "The loai	 : " << a[i].getCategory() << endl;
			cout << "Nha xuat ban     : " << a[i].getPublisher() << endl;
			cout << "So luong ban dau : " << a[i].getTotal() << endl;
			cout << "So luong hien tai: " << a[i].getCurrent() << endl;
			cout << "********************************************************" << endl;
			noExist++;
		}
	}
	if (noExist == 0) cout << "\nKhong tim thay the loai sach vua nhap. Vui long kiem tra lai...\n\n";
	system("pause");
}

//hien thi danh sach cac dau sach da duoc muon het
void showListOutofStock(vector<Book> &a) {
	int size = a.size();
	int noExist = 0;
	for (int i = 0; i < size; i++) {
		if (a[i].getCurrent() == 0) {
			cout << endl;
			cout << "Ma so sach	 : " << a[i].getBookID() << endl;
			cout << "Ten sach	 : " << a[i].getBookName() << endl;
			cout << "The loai	 : " << a[i].getCategory() << endl;
			cout << "Nha xuat ban     : " << a[i].getPublisher() << endl;
			cout << "So luong ban dau : " << a[i].getTotal() << endl;
			cout << "So luong hien tai: " << a[i].getCurrent() << endl;
			noExist++;
		}
	}
	if (noExist == 0) cout << "\nKhong co dau sach nao hien dang duoc cho muon het\n\n";
	system("pause");
}

//kiem tra dau sach da duoc muon het hay chua?
bool checkOutofStock(vector<Book> &a,char b[]) {
	bool outofStock = true;//true thi het sach, false la con sach
	int bookSelected = findBookID(a, b);
	if (bookSelected == -1) outofStock = true;// truong hop nay la khong co sach
	else {
		if (a[bookSelected].getCurrent() != 0) outofStock = false;//con sach
	}
	return outofStock;
}

//xac dinh doi tuong co ID trong mang Sheet trung voi tim kiem cua nguoi dung 
int findSheetID(vector<BorrowedSheet> &a, char inputSheetID[]) {
	int sheetSelected = -1;
	int size = a.size();
	for (int i = 0; i < size; i++) {
		if (strcmp(a[i].getSheetID(), inputSheetID) == 0) {
			sheetSelected = i;
			break;
		}
	}
	return sheetSelected;
}

//them mot phieu muon moi
void addSheet(vector<BorrowedSheet> &a, vector<Book> &b, BorrowedSheet &c, vector<User> &d,bool isGet) {
	char input[maxElements];
	int inputnumber,test=-1;
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
	
	do {
		check = false;
		cout << "\nNhap ten nguoi muon: ";
		fflush(stdin);
		cin.getline(input, maxElements);
		int numUser = d.size();
		for (int i = 0; i < numUser; i++) {
			if (strcmp(d[i].getName(), input) == 0) {
				c.setRenter(d[i].getName());
				check = true;
				break;
			}
		}
		if (check == false) {
			cout << "\nKhong tim thay ten nguoi dung vua nhap trong he thong. Vui long nhap lai...\n";
		}
	} while (check == false);


	c.setStatus("OK");
	
	//lay thoi gian la thoi gian thuc cua he thong
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	Time today;
	today.setDay(newtime.tm_mday);
	today.setMonth(newtime.tm_mon+1);
	today.setYear(newtime.tm_year+1900);
	c.setBorrowedDate(today);

	cout << "\nNhap so luong sach: ";
	cin >> inputnumber;

	c.setBorrowedBookNum(inputnumber);
	b[bookSelected].setCurrent(b[bookSelected].getCurrent()-c.getBorrowedBookNum());
	c.setisReturn(isGet);//chua tra->false, da tra->true

	a.push_back(c);

	cout << "\nTHAO TAC HOAN TAT\n";
	system("pause");
}

//xoa mot phieu muon
void deleteSheet(vector<BorrowedSheet> &a) {
	char input[maxElements];

	cout << "\nNhap ma so sach: ";
	cin.ignore();
	cin.getline(input, maxElements);
	int sheetSelected = findSheetID(a, input);
	if (sheetSelected == -1) cout << "\nMa so phieu khong ton tai hoac da xoa. Vui long kiem tra lai...\n\n";
	else {
		a.erase(a.begin() + sheetSelected);
		cout << "\nTHAO TAC HOAN TAT\n";
	}
	system("pause");
}

//chinh sua thong tin mot phieu muon // CAN BO SUNG
void editSheet(vector<BorrowedSheet> &a,vector<User> &b,bool readergetbook) {
	char input[maxElements];
	bool check = true;

	cout << "\nNhap ma so phieu muon: ";
	cin.ignore();
	cin.getline(input, maxElements);
	int sheetSelected = findSheetID(a, input);
	if (sheetSelected == -1) cout << "\nMa so phieu khong ton tai hoac da xoa. Vui long kiem tra lai...\n\n";
	else {
		cout << "=========================================================================\n";
		cout << "\nNHAP VAO THONG TIN MOI\n";
		//nhap ho ten
		do {
			check = false;
			cout << "\nNhap ten nguoi muon: ";
			fflush(stdin);
			cin.getline(input, maxElements);
			int numUser = b.size();
			for (int i = 0; i < numUser; i++) {
				if (strcmp(b[i].getName(), input) == 0) {
					a[sheetSelected].setRenter(b[i].getName());
					check = true;
					break;
				}
			}
			if (check == false) {
				cout << "\nKhong tim thay ten nguoi dung vua nhap trong he thong. Vui long nhap lai...\n";
			}
		} while (check == false);
		//nhap tinh trang
		cout << "\nTinh trang sach: ";
		fflush(stdin);
		cin.getline(input, maxElements);
		a[sheetSelected].setStatus(input);
		
		//chinh sua ngay muon thanh ngay hom nay neu doc gia lay sach
		if (readergetbook == true) {
			struct tm newtime;
			time_t now = time(0);
			localtime_s(&newtime, &now);
			Time today;
			today.setDay(newtime.tm_mday);
			today.setMonth(newtime.tm_mon + 1);
			today.setYear(newtime.tm_year + 1900);
			a[sheetSelected].setBorrowedDate(today);
		}
		
		//do khi doc gia tra sach phieu muon se duoc xoa nen dong lenh duoi duoc hieu la doc gia toi lay sach va isReturn->false
		a[sheetSelected].setisReturn(false);

	}

	cout << "\nTHAO TAC HOAN TAT\n";
	system("pause");
}

//hien thi toan bo thong tin cac phieu muon hien co trong thu vien
void showListSheets(vector<BorrowedSheet> &a) {
	int size = a.size();
	for (int i = 0; i < size; i++) {
		cout << "Ma phieu muon: " << a[i].getSheetID() << endl;
		cout << "Ho ten nguoi muon: " << a[i].getRenter() << endl;
		cout << "Ma so sach muon: " << a[i].getBookID() << endl;
		cout << "Ngay muon: "
			<< setw(2) << setfill('0') << a[i].getBorrowedDate().getDay() << "/"
			<< setw(2) << setfill('0') << a[i].getBorrowedDate().getMonth() << "/"
			<< setw(2) << a[i].getBorrowedDate().getYear() << endl;
		cout << "So luong: " << a[i].getBorrowedBookNum() << endl;
		cout << "Tra sach: ";
		if (a[i].getisReturn() == false) cout << "Chua tra" << endl << endl;
		else cout << "Da tra" << endl << endl;
		cout << "************************************************************************\n";
	}
	system("pause");
}

//hien thi thong tin phieu muon duoc chon
void showSheetSelected(vector<BorrowedSheet> &a) {
	char input[maxElements];

	cout << "\nNhap ma so phieu muon: ";
	cin.ignore();
	cin.getline(input, maxElements);
	int sheetSelected = findSheetID(a, input);
	if (sheetSelected == -1) cout << "\nMa so phieu khong ton tai hoac da bi xoa. Vui long kiem tra lai...\n\n";
	else {
		cout << "Ho ten nguoi muon: " << a[sheetSelected].getRenter() << endl<<endl;
		cout << "Ma so sach muon: " << a[sheetSelected].getBookID() << endl << endl;
		cout << "Ngay muon: "
			<< setw(2) << setfill('0') << a[sheetSelected].getBorrowedDate().getDay() << "/"
			<< setw(2) << setfill('0') << a[sheetSelected].getBorrowedDate().getMonth() << "/"
			<< setw(2) << a[sheetSelected].getBorrowedDate().getYear() << endl << endl;
		cout << "So luong: " << a[sheetSelected].getBorrowedBookNum() << endl << endl;
		cout << "Tra sach: ";
		if (a[sheetSelected].getisReturn() == false) cout << "Chua tra" << endl << endl;
		else cout << "Da tra" << endl << endl;
	}
	system("pause");
}

//hien thi dannh sach cac phieu muon qua han
void showListOutofDate(vector<BorrowedSheet> &a) {
	int size=a.size();
	int howlong = 0;
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	Time today;
	today.setDay(newtime.tm_mday);
	today.setMonth(newtime.tm_mon);
	today.setYear(newtime.tm_year);
	for (int i = 0; i < size; i++) {
		if (a[i].getBorrowedDate().getYear() == today.getYear()) {
			howlong = today.PositionofDay() - a[i].getBorrowedDate().PositionofDay();
		}
		else howlong = a[i].getBorrowedDate().NumberDayofYear() + today.PositionofDay() - a[i].getBorrowedDate().PositionofDay() + 1;
		if (howlong > 30 && a[i].getisReturn() == false) {
			cout << "Ho ten nguoi muon: " << a[i].getRenter() << endl << endl;
			cout << "Ma so sach muon: " << a[i].getBookID() << endl << endl;
			cout << "Ngay muon: "
				<< setw(2) << setfill('0') << a[i].getBorrowedDate().getDay() << "/"
				<< setw(2) << setfill('0') << a[i].getBorrowedDate().getMonth() << "/"
				<< setw(2) << a[i].getBorrowedDate().getYear() << endl << endl;
			cout << "So luong: " << a[i].getBorrowedBookNum() << endl << endl;
			cout << "Tra sach: ";
			if (a[i].getisReturn() == false) cout << "Chua tra" << endl << endl;
			else cout << "Da tra" << endl << endl;
		}
	}
}

//hien thi danh sach doc gia muon nhieu -> CHUA CONVERT DUOC

//void showListPositive(vector<BorrowedSheet> &a) {
//	vector<int> borrowedNum;
//	borrowedNum.resize(0);
//
//}

#endif // !lib

