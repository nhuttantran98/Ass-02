#ifndef user_manager
#define user_manager

#include"Main_Class.h"

//TIM KIEM--------------------------------------------------------------------------

//tim kiem theo ID
bool Search_ID(vector<Account> a, int ID_Search, int &objSelected) {
	bool var = false;
	int size = a.size();
	for (int i = 0; i < size; i++) {
		if (a[i].getAccountID() == ID_Search) {
			var = true;
			objSelected = i;
			break;
		}
	}
	return var;
}

//tim kiem theo ten tai khoan
bool Search_AccountName(vector<Account> a, char b[], int &objSelected) {
	bool var = true;
	int size = a.size();
	for (int i = 0; i < size; i++) {
		if (strcmp(a[i].getAccountName(), b) == 0) {
			var = true;
			objSelected = i;
			break;
		}
	}
	return var;
}

//-----------------------------------------------------------------------------------

//CHINH SUA-------------------------------------------------------------------------

//hien thi thong tin cua doi tuong duoc chon de chinh sua ( de nguoi quan ly can nhan co nen chinh sua hay khong )
void ShowObj_user(User &a) {
	cout << endl << "\nTHONG TIN LIEN LAC\n";
	cout << endl << "1.Ho va ten: " << a.getName() << endl;
	cout << endl << "2.So CMND: " << a.getIdentityCard() << endl;
	cout << endl << "3.Gioi tinh: " << a.getSex() << endl;
	cout << endl << "4.Ngay sinh: " << a.getBirthday() << endl;
	cout << endl << "5.Cong viec: " << a.getJob() << endl;
	cout << endl << "6.Email: " << a.getEmail() << endl;
	cout << "\n=======================================================================\n";
	cout << endl << "7.Tro ve" << endl;
}

//hien thi ten loai thong tin dang duoc chinh sua ( VI DU : cmnd )
void Editing(int &a) {
	switch (a) {	
	case 1: {
		cout << endl << "CHINH SUA HO VA TEN\n";
		break;
	}
	case 2: {
		cout << endl << "CHINH SUA SO CMND\n";
		break;
	}
	case 3: {
		cout << endl << "CHINH SUA GIOI TINH\n";
		break;
	}
	case 4: {
		cout << endl << "CHINH SUA NGAY SINH\n";
		break;
	}
	case 5: {
		cout << endl << "CHINH SUA CONG VIEC\n";
		break;
	}
	case 6: {
		cout << endl << "CHINH SUA EMAIL\n";
		break;
	}
	}
}

//thuc hien chinh sua
void Setting(User &a,int b) {
	char input[maxElements];
	cout << endl << "\nNhap thong tin moi: ";
	cin.ignore();
	cin.getline(input, maxElements);
	//neu chinh sua CMND thi kiem tra xem co dung cu phap hay khong
	while (b == 2) {
		if (strlen(input) == 9) break;
		else {
			cout << "\nThao tac that bai. So CMND phai bao gom 9 ki tu. Vui long nhap lai.\n";
			cout << endl << "\nNhap thong tin moi: ";
			cin.ignore();
			cin.getline(input, maxElements);
		}
	} 
	switch (b) {
	case 1: {
		a.setName(input);
		break;
	}
	case 2: {
		a.setIdentityCard(input);
		break;
	}
	case 3: {
		a.setSex(input);
		break;
	}
	case 4: {
		a.setBirthday(input);
		break;
	}
	case 5: {
		a.setJob(input);
		break;
	}
	case 6: {
		a.setEmail(input);
		break;
	}
	}
}

//-----------------------------------------------------------------------------------

//XOA TAI KHOAN----------------------------------------------------------------------

//hien thi ID, ten tai khoan va vai tro cua doi tuong ( de nguoi quan ly can nhan co nen xoa hay khong )
void ShowObj_account(Account a, RoleOfAccount b) {
	cout << endl << "ID tai khoan: " << a.getAccountID() << endl;
	cout << endl << "Ten tai khoan: " << a.getAccountName() << endl;
	cout << endl << "Vai tro: ";
	switch (b.get_RoleID()) {
	case 1: {
		cout << "Quan ly" << endl;
		break;
	}
	case 2: {
		cout << "Thu thu" << endl;
		break;
	}
	case 3: {
		cout << "Doc gia" << endl;
		break;
	}
	case 4: {
		cout << "Quan ly + Thu thu" << endl;
		break;
	}
	case 5: {
		cout << "Quan ly + Doc gia" << endl;
		break;
	}
	case 6: {
		cout << "Thu thu + Doc gia" << endl;
		break;
	}
	case 7: {
		cout << "Quan ly + Thu thu + Doc gia" << endl;
		break;
	}
	}
	cout << "\n=======================================================================\n";
}


//tien hanh xoa
void Delete(vector<Account> &a, vector<User> &b, vector<RoleOfAccount> &c, int ID_Selected) {
	a.erase(a.begin() + ID_Selected);
	b.erase(b.begin() + ID_Selected);
	c.erase(c.begin() + ID_Selected);
}


#endif // !user_manager