#ifndef login_register
#define login_register

#include"Main_Class.h"

//BANG DANG KY---------------------------------------------------------------

void RegisterFunction(Account &a, User &b) {
	char input[maxElements];

	//thong tin account
	cout << "\nThong tin tai khoan\n";
	cout << "\nTen dang nhap: "; cin.ignore();
	fflush(stdin);
	cin.getline(input, maxElements);
	a.setAccountName(input);

	cout << "\nMat khau: ";
	fflush(stdin);
	cin.getline(input, maxElements);
	a.setPassword(input);

	//thong tin user
	cout << "\nThong tin ca nhan\n";
	cout << "\nHo va ten: ";
	fflush(stdin);
	cin.getline(input, maxElements);
	b.setName(input);

	cout << "\nSo chung minh nhan dan (9 chu so): ";
	fflush(stdin);
	cin.getline(input, maxElements);
	b.setIdentityCard(input);

	cout << "\nGioi tinh (nam hoac nu): ";
	fflush(stdin);
	cin.getline(input, maxElements);
	b.setSex(input);

	cout << "\nNgay thang nam sinh (dd/mm/yy): ";
	fflush(stdin);
	cin.getline(input, maxElements);
	b.setBirthday(input);

	cout << "\nCong viec hien tai : ";
	fflush(stdin);
	cin.getline(input, maxElements);
	b.setJob(input);

	cout << "\nDia chi Email: ";
	fflush(stdin);
	cin.getline(input, maxElements);
	b.setEmail(input);
}

bool checkAccountName(vector<Account> a, Account &b) {
	int size = a.size();
	bool var = true;
	for (int i = 0; i < size; i++) {
		if (strcmp(a[i].getAccountName(), b.getAccountName()) == 0) {
			var = false;
			break;
		}
	}
	return var;
}

bool checkIdentityCard(User &a) {
	bool var = true;
	if (strlen(a.getIdentityCard()) != 9) var = false;
	return var;
}

void ReviewRegistraion(Account a, User b) {
	cout << "\nBAN DA DANG KI THANH CONG. MOI XEM LAI THONG TIN.\n";
	cout << "\n=======================================================================\n";
	cout << "\nTHONG TIN TAI KHOAN\n";
	cout << "\nID tai khoan" << ": " << a.getAccountID() << endl;
	cout << "\nTen dang nhap" << ": " << a.getAccountName() << endl;
	cout << "\nMat khau: " << ": ";
	int size = strlen(a.getPassword());
	for (int i = 0; i < size; i++) {
		cout << "*";
	}
	cout << endl;
	cout << "\n=======================================================================\n";
	cout << "\nTHONG TIN LIEN LAC\n";
	cout << "\nHo va ten" << ": " << b.getName() << endl;
	cout << "\nSo CMND" << ": " << b.getIdentityCard() << endl;
	cout << "\nGioi tinh" << ": " << b.getSex() << endl;
	cout << "\nNgay sinh" << ": " << b.getBirthday() << endl;
	cout << "\nCong viec hien tai" << ": " << b.getJob() << endl;
	cout << "\nEmail lien lac" << ": " << b.getEmail() << endl;
	cout << "\n=======================================================================\n";
	cout << "\nHien tai tai khoan cua ban van chua duoc kich hoat. Vui long lien he Quan ly de kich hoat tai khoan.\n";
	cout << "\nXin cam on.\n\n";
	system("pause");
}

//ghi thong tin dang ki xuong file
//ghi khi dang ki
void setAccountData_register(Account a) {
	fstream datafile("account.dat", ios::out | ios::binary | ios::app);
	datafile.write(reinterpret_cast<char*>(&a), sizeof(Account));
	datafile.close();
}

void setUserData_register(User a) {
	fstream datafile("user.dat", ios::out | ios::binary | ios::app);
	datafile.write(reinterpret_cast<char*>(&a), sizeof(User));
	datafile.close();
}

void setRoleOfAccountData_register(RoleOfAccount a) {
	fstream datafile("role_of_account.dat", ios::out | ios::binary | ios::app);
	datafile.write(reinterpret_cast<char*>(&a), sizeof(RoleOfAccount));
	datafile.close();
}

//ghi khi thoat
void setAccountData(vector<Account> a) {
	int size = a.size();
	fstream datafile("account.dat", ios::out | ios::binary );
	for (int i = 0; i < size; i++) {
		datafile.write(reinterpret_cast<char*>(&a[i]), sizeof(Account));
	}
	datafile.close();
}

void setUserData(vector<User> a) {
	int size = a.size();
	fstream datafile("user.dat", ios::out | ios::binary );
	for (int i = 0; i < size; i++) {
		datafile.write(reinterpret_cast<char*>(&a[i]), sizeof(User));
	}
	datafile.close();
}

void setRoleOfAccountData(vector<RoleOfAccount> a) {
	int size = a.size();
	fstream datafile("role_of_account.dat", ios::out | ios::binary );
	for (int i = 0; i < size; i++) {
		datafile.write(reinterpret_cast<char*>(&a[i]), sizeof(RoleOfAccount));
	}
	datafile.close();
}

//---------------------------------------------------------------------------


//BANG DANH NHAP-------------------------------------------------------------

void LoginFunction(Account &a) {
	char input[maxElements];

	cin.ignore();
	cout << "\nTen dang nhap: ";
	fflush(stdin);
	cin.getline(input, maxElements);
	a.setAccountName(input);

	cout << "\nMat khau: ";
	fflush(stdin);
	cin.getline(input, maxElements);
	a.setPassword(input);
}

//ham kiem tra ten dang nhap su dung chung voi BANG DANG Ky checkAccountName

bool checkPassword(vector<Account> a, Account &b, int &ID) {
	int size = a.size();
	bool var = true;
	for (int i = 0; i < size; i++) {
		if (strcmp(a[i].getPassword(), b.getPassword()) == 0) {
			var = false;
			ID = i;
			break;
		}
	}
	return var;
}

//---------------------------------------------------------------------------
#endif // !login_register