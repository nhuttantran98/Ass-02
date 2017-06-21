#ifndef interface
#define interface

//MAN HINH CO BAN===================================

void MainScreen() {
		system("cls");
		cout << "=======================================================================\n";
		cout << "\nCHAO MUNG BAN DEN VOI LIBPRO!\n";
		cout << "\n=======================================================================\n";
		cout << "\n1. Dang nhap\n";
		cout << "\n2. Dang ki\n";
		cout << "\n3. Thoat\n";
		cout << "\n=======================================================================\n";
	}

void LoginScreen() {
	system("cls");
	cout << "=======================================================================\n";
	cout << "\nDANG NHAP HE THONG\n";
	cout << "\n=======================================================================\n";
}

void RegisterScreen() {
	system("cls");
	cout << "========================================================================\n";
	cout << "\nDANG KY TAI KHOAN\n";
	cout << "\n=======================================================================\n";
}

void ActivedFalse(Account a) {
	system("cls");
	cout << "=======================================================================\n";
	cout << "\nCHAO MUNG BAN DEN VOI LIBPRO!\n";
	cout << "\n=======================================================================\n";
	cout << "\nTai khoan " << a.getAccountName() << " chua duoc kich hoat.\n\n";
	cout << "\nVui long den gap nguoi Quan ly de kich hoat tai khoan.\n\n";
	cout << "\nXin cam on...\n\n";
}

//==================================================

//MAN HINH UNG VOI TUNG TINH NANG

//THU THU-------------------------------------------

void LibrarianScreen() {
	system("cls");
	cout << "=======================================================================\n";
	cout << "Ban dang dang nhap voi vai tro Thu Thu\n";
	cout << "=======================================================================\n";
}

//--------------------------------------------------

//QUAN LY-------------------------------------------

//hien thi ten tai khoan va vai tro cua tai khoan dang dang dang nhap
void UMScreen(vector<Account> dataAccount, int ID_Selected) {
	cout << "=========================================================================\n";
	cout << "\nCHAO MUNG BAN DEN VOI LIBPRO\n";
	cout << "\n=======================================================================\n";
	cout << "\nChao " << dataAccount[ID_Selected].getAccountName() << endl;
	cout << "\nBAN DANG DANG NHAP VOI VAI TRO QUAN LY NGUOI DUNG\n";
}

//hien thi tai khoan dang duoc chon
void UM_SelectedAcc(vector<Account> dataAccount, int ID_Selected) {
	cout << "\n=====================================================================\n";
	cout <<"\nTai khoan dang duoc chon: "<< dataAccount[ID_Selected].getAccountName() << endl;
	cout << "\n=====================================================================\n";
}

//hien thi cac tinh nang co the thuc hien cua quan ly
void UM_SelectScreen() {
	cout << "\n1.CHINH SUA THONG TIN TAI KHOAN\n";
	cout << "\n2.XOA TAI KHOAN\n";
	cout << "\n3.KICH HOAT TAI KHOAN\n";
	cout << "\n4.THIET DAT LAI MAT KHAU\n";
	cout << "\n5.THAY DOI VAI TRO\n";
	cout << "\n6.TRO VE\n";
	cout << "\n=====================================================================\n";
}

//chuc nang tim kiem
void UM_SearchScreen() {
	//hien thi chuc dang dang thuc hien
	cout << "\n=====================================================================\n";
	cout << "\nTIM KIEM TAI KHOAN\n";
	cout << "\n1.Tim theo ID\n";
	cout << "\n2.Tim theo ten dang nhap\n";
	cout << "\n3.Ket thuc phien lam viec ( Dang xuat va thoat )\n";
	cout << "\n===================================================================\n";
}

//thong bao thao tac hoan tat
void DoneScreen() {
	//Thong bao hoan tat va quay ve man hinh tim kiem
	cout << "=======================================================================\n";
	cout << "\nTHAO TAC HOAN TAT.\n";
	cout << "\n=======================================================================\n";
	system("pause");
}

//hien thi bang cac vai tro de nguoi quan ly lua chon khi thay doi vai tro
void RoleTable() {
	cout << "\n1.QUAN LY\n";
	cout << "\n2.THU THU\n";
	cout << "\n3.DOC GIA\n";
	cout << "\n4.QUAN LY + THU THU\n";
	cout << "\n5.QUAN LY + DOC GIA\n";
	cout << "\n6.THU THU + DOC GIA\n";
	cout << "\n7.QUAN LY + THU THU + DOC GIA\n";
	cout << "\n=======================================================================\n";
	cout << "\n8.TRO VE\n";
	cout << "\n=======================================================================\n";
}

//--------------------------------------------------

//DOC GIA-------------------------------------------

void ReaderScreen() {
	system("cls");
	cout << "=======================================================================\n";
	cout << "Ban dang dang nhap voi vai tro Doc Gia\n";
	cout << "=======================================================================\n";
}

//--------------------------------------------------

//THU THU + QUAN LY---------------------------------

void Lib_UMScreen() {
	system("cls");
	cout << "=======================================================================\n";
	cout << "Ban dang dang nhap voi vai tro Thu Thu va Quan li Nguoi dung\n";
	cout << "=======================================================================\n";
}

//--------------------------------------------------

//THU THU + DOC GIA---------------------------------

void Lib_ReadScreen() {
	system("cls");
	cout << "=======================================================================\n";
	cout << "Ban dang dang nhap voi vai tro Thu Thu va Doc Gia\n";
	cout << "=======================================================================\n";
}

//--------------------------------------------------

//QUAN LY + DOC GIA---------------------------------

void UM_ReadScreen() {
	system("cls");
	cout << "=======================================================================\n";
	cout << "Ban dang dang nhap voi vai tro Quan li Nguoi su dung va Doc Gia\n";
	cout << "=======================================================================\n";
}

//--------------------------------------------------

//CA BA---------------------------------------------

void AllScreen() {
	system("cls");
	cout << "=======================================================================\n";
	cout << "Ban duoc su dung tat ca tinh nang cua thu vien\n";
	cout << "=======================================================================\n";
}

//--------------------------------------------------

#endif // !interface