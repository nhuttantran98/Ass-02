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

//hien thi ten tai khoan va vai tro cua tai khoan dang dang dang nhap
void LibScreen(vector<Account> dataAccount, int ID_Selected) {
	cout << "=========================================================================\n";
	cout << "\nCHAO MUNG BAN DEN VOI LIBPRO\n";
	cout << "\n=======================================================================\n";
	cout << "\nChao " << dataAccount[ID_Selected].getAccountName() << endl;
	cout << "\nBAN DANG DANG NHAP VOI VAI TRO THU THU\n";
}

//hien thi cac tinh nang thu thu co the su dung
void Lib_SelectScreen() {
	cout << "\n=============================================================================\n";
	cout << "|          QUAN LY SACH             |      QUAN LY PHIEU MUON               |";
	cout << "\n-----------------------------------------------------------------------------";
	cout << "\n| 1 .Them Mot Dau Sach Moi          |    9 .Muon Sach                       |";
	cout << "\n| 2 .Sua Thong Tin Sach             |    10.Tra Sach                        |";
	cout << "\n| 3 .Xoa Thong Tin Sach             |    11.Sua Thong Tin Phieu Muon        |";
	cout << "\n| 4 .Tim Kiem Thong Tin Sach        |    12.Xoa Thong Tin Phieu Muon        |";
	cout << "\n| 5 .Liet Ke Cac Sach Cung The Loai |    13.Tim Thong Tin Phieu Muon        |";
	cout << "\n| 6 .In Thong Tin Tat Ca Sach       |    14.In Dach Sach Phieu Muon         |";
	cout << "\n| 7 .Thong Ke Sach Da Cho Muon Het  |    15.Thong Ke Cac Phieu Muon Qua Han |";
	cout << "\n| 8 .Thoat Khoi Chuong Trinh        |                                       |";
	cout << "\n=============================================================================\n";
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
	cout << "\nTai khoan dang duoc chon: " << dataAccount[ID_Selected].getAccountName() << endl;
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

//hien thi ten tai khoan va vai tro cua tai khoan dang dang dang nhap
void ReaderScreen(vector<Account> dataAccount, int ID_Selected) {
	cout << "=========================================================================\n";
	cout << "\nCHAO MUNG BAN DEN VOI LIBPRO\n";
	cout << "\n=======================================================================\n";
	cout << "\nChao " << dataAccount[ID_Selected].getAccountName() << endl;
	cout << "\nBAN DANG DANG NHAP VOI VAI TRO DOC GIA\n";
}

//hien thi cac tinh nang co the thuc hien cua doc gia
void Reader_SelectScreen() {
	cout << "\n1.XEM VA CHINH SUA THONG TIN\n";
	cout << "\n2.MUON SACH\n";
	cout << "\n3.DOI MAT KHAU\n";
	cout << "\n4.DANG XUAT VA THOAT\n";
	cout << "\n=====================================================================\n";
}

//--------------------------------------------------

//THU THU + QUAN LY---------------------------------

void manyRoleScreen(vector<Account> dataAccount, int ID_Selected) {
	cout << "=========================================================================\n";
	cout << "\nCHAO MUNG BAN DEN VOI LIBPRO\n";
	cout << "\n=======================================================================\n";
	cout << "\nChao " << dataAccount[ID_Selected].getAccountName() << endl;
	cout << "\n=======================================================================\n";
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