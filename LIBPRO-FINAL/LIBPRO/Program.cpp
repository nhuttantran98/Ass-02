#include"Login_Register.h"
#include"Interface.h"
#include"UM.h"
#include"Librarian_Class.h"
#include"Lib.h"
#include"Reader.h"

int main() {

	int selectVar;//bien chon, nguoi dung nhap lua chon cua minh
	int ID_Login = 0;//xac dinh ID cua doi tuong thuc hien dang nhap
	int ID_Search = 0;//dung de tim kiem doi tuong theo ID
	char AccountName_Search[maxElements];//dung de tim kiem doi tuong theo ten tai khoan
	bool checkSearch;//kiem tra viec tim kiem
	int objSelected = 0;//xac dinh doi tuong duoc chon sau qua trinh tim kiem, gia tri bang id cua doi tuong trong vector dataAccount

	vector<Account> dataAccount;//mang luu thong tin Account doc len tu file
	dataAccount.resize(0);
	vector<User> dataUser;//mang luu thong tin User doc len tu file
	dataUser.resize(0);
	vector<RoleOfAccount> dataRoleOfAccount;//mang luu thong tin ve vai tro cua moi Account doc len tu file
	dataRoleOfAccount.resize(0);
	vector<Book> dataBook;//mang luu thong tin Book doc len tu file
	dataBook.resize(0);
	vector<BorrowedSheet> dataBorrowedSheet;
	dataBorrowedSheet.resize(0);

	Account x; User y; RoleOfAccount z; Book a; BorrowedSheet b;//cac doi tuong chinh cua toan chuong trinh

	//sinh bo so ngau nhien khi thuc hien dang ki
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dis(1000, 1999);

	//==========================================DOC THONG TIN TU FILE LEN RAM=============================================

	ifstream getDataAccount("account.dat", ios::in | ios::binary);
	while (getDataAccount.read(reinterpret_cast<char*>(&x), sizeof(Account))) {
		dataAccount.push_back(x);
	}
	getDataAccount.close();

	ifstream getDataUser("user.dat", ios::in | ios::binary);
	while (getDataUser.read(reinterpret_cast<char*>(&y), sizeof(User))) {
		dataUser.push_back(y);
	}
	getDataUser.close();

	ifstream getDataRoleOfAccount("role_of_account.dat", ios::in | ios::binary);
	while (getDataRoleOfAccount.read(reinterpret_cast<char*>(&z), sizeof(RoleOfAccount))) {
		dataRoleOfAccount.push_back(z);
	}
	getDataRoleOfAccount.close();

	ifstream getDataBook("listbook.dat", ios::in | ios::binary);
	while (getDataBook.read(reinterpret_cast<char*>(&a), sizeof(Book))) {
		dataBook.push_back(a);
	}
	getDataBook.close();

	ifstream getDataBorrowedSheet("listBorrowedSheet.dat", ios::in | ios::binary);
	while (getDataBorrowedSheet.read(reinterpret_cast<char*>(&b), sizeof(BorrowedSheet))) {
		dataBorrowedSheet.push_back(b);
	}
	getDataBorrowedSheet.close();

	//======================================================MAN HINH CHINH=======================================================

	//test listbook
	/*for (int i = 0; i < dataBook.size(); i++) {
		cout << dataBook[i].getBookID() << "\t"
			<< dataBook[i].getBookName() << "\t"
			<< dataBook[i].getCategory() << "\t"
			<< dataBook[i].getTotal() << "\t"
			<< dataBook[i].getCurrent() << endl;
	}
	system("pause");*/

	//test sheet
	/*for (int i = 0; i < dataBorrowedSheet.size(); i++) {
		cout << dataBorrowedSheet[i].getSheetID() << "\t"
			<< dataBorrowedSheet[i].getBookID() << "\t"
			<< dataBorrowedSheet[i].getBorrowedBookNum() << "\t"
			<< dataBorrowedSheet[i].getBorrowedDate().getDay() << "\t"
			<< dataBorrowedSheet[i].getBorrowedDate().getMonth() << "\t"
			<< dataBorrowedSheet[i].getBorrowedDate().getYear() << "\t" << endl;
	}
	system("pause");*/
	

	//test doc xuat
	/*int size = dataAccount.size();
	for (int i = 0; i < size; i++) {
		cout << dataAccount[i].getAccountID() << "\t"
			<< dataAccount[i].getAccountName() << "\t"
			<< dataAccount[i].getPassword() << "\t"
			<< dataAccount[i].getisActived() << "\t"
			<< dataUser[i].getName() << "\t"
			<< dataRoleOfAccount[i].get_RoleID() << endl;
	}
	system("pause");*/

Menu:

	//vong lap nay cho phep tro ve Man hinh chinh
	do {

		//kiem tra hop le
		do {
			system("cls");
			MainScreen();
			cout << "\nMoi ban chon: ";
			cin >> selectVar;
			if (selectVar < 1 || selectVar>3) {
				cout << "\nLua chon khong hop le. Xin kiem tra lai ...\n\n";
				system("pause");
			}
		} while (selectVar < 1 || selectVar>3);

		//lua chon tinh nang dang nhap(1) , dang ki(2), hoac thoat(3)
		switch (selectVar) {

			//================================================DANG NHAP===================================================

		case 1: {
			bool check1, check2;

			//nhap thong tin dang nhap va kiem tra hop le, neu khong bao loi va yeu cau nhap lai

			do {
				system("cls");
				LoginScreen();
				LoginFunction(x);
				check1 = true;
				check2 = true;
				check1 = checkAccountName(dataAccount, x);
				check2 = checkPassword(dataAccount, x, ID_Login);
				while (check1 == true || check2 == true) {
					//kiem tra xem co muon dang nhap lai hay khong (1.co 2.khong).neu nhap sai bat nhap lai
					do {
						system("cls");
						LoginScreen();
						cout << "\nTen dang nhap hoac mat khau khong dung. Vui long kiem tra lai.\n";
						cout << "\n1.Nhap lai\n";
						cout << "\n2.Tro ve\n";
						cout << "\n=======================================================================\n";
						cout << "\nMoi ban chon: ";
						cin >> selectVar;
						if (selectVar < 1 || selectVar>2) {
							cout << "\nLua chon khong hop le. Xin kiem tra lai...\n";
							system("pause");
						}
					} while (selectVar < 1 || selectVar>2);
					if (selectVar == 2) goto Menu;
					if (selectVar == 1) break;
				}
			} while (check1 == true || check2 == true);

			//neu tai khoan dang nhap chua kich hoat thi hien thong bao va tro ve menu chinh

			if (dataAccount[ID_Login].getisActived() == false) {
				ActivedFalse(dataAccount[ID_Login]);
				system("pause");
				break;
			}

			//neu tai khoan dang nhap da kich hoat thi kiem tra vai tro va dua den man hinh tuong ung
			else {
				selectVar = 3;
				break;
			}

		}

				//=================================================DANG KY====================================================

		case 2: {
			bool check1, check2;

			//nhap thong tin dang ki va kiem tra hop le, neu khong bao loi va yeu cau nhap lai
			do {
				system("cls");
				RegisterScreen();
				RegisterFunction(x, y);
				check1 = true;
				check2 = true;
				check1 = checkAccountName(dataAccount, x);
				check2 = checkIdentityCard(y);
				if (check1 == false) {
					cout << "\nTen dang nhap da co nguoi su dung. Vui long nhap lai...\n";
					system("pause");
				}
				if (check2 == false) {
					cout << "\nSo CMND vua nhap khong dung. Vui long nhap lai...\n";
					system("pause");
				}
			} while (check1 == false || check2 == false);

			//random cho nguoi dung mot ID ngau nhien
			x.setAccountID(dis(mt));

			//kiem tra ID co bi trung hay khong
			int size = dataAccount.size();
			for (int i = 0; i < size; i++) {
				if (dataAccount[i].getAccountID() == x.getAccountID()) x.setAccountID(dis(mt));
			}

			//thiet lap cac thong tin con thieu trong qua trinh dang ki
			x.setisActived(false);//mac dinh tai khoan moi dang ky chua duoc kich hoat
			y.setUserID(x.getAccountID());//gan UserID=AccountID
			z.set_AccountID(x.getAccountID());//gan _AccountID=AccountID
			z.set_RoleID(3);//mac dinh vai tro ban dau la doc gia

							//ghi thong tin xuong file
			setAccountData_register(x);
			setUserData_register(y);
			setRoleOfAccountData_register(z);

			//them phan tu vua duoc dang ki vao mang
			dataAccount.push_back(x);
			dataUser.push_back(y);
			dataRoleOfAccount.push_back(z);

			//hoan tat dang ki, xem lai thong tin
			system("cls");
			RegisterScreen();
			ReviewRegistraion(x, y);
			break;
		}

				//=================================================THOAT====================================================

		case 3: {
			cout << "\nBan thuc su muon thoat?\n";
			cout << "\n1.Co\n";
			cout << "\n2.Khong\n";
			cout << "\nLua chon: ";
			cin >> selectVar;
			if (selectVar == 1) {
				setAccountData(dataAccount);
				setUserData(dataUser);
				setRoleOfAccountData(dataRoleOfAccount);
				setBookData(dataBook);
				setBorrowedSheetData(dataBorrowedSheet);
				system("pause");
				return 0;
			}
			else break;
		}

		}

	} while (selectVar != 3);


	//===========================================MAN HINH LAM VIEC UNG VOI TUNG VAI TRO=========================================

	int currentRole = dataRoleOfAccount[ID_Login].get_RoleID();
	//dan toi man hinh cua tung vai tro

	switch (currentRole) {

			//===================== QUAN LY =====================
	case 1: {
		UserManager:
		//===============================================MAN HINH TIM KIEM TAI KHOAN============================================

		//===== khi thuc hien xong tinh nang duoc chon(case) tu dong dua nguoi dung tro ve MAN HINH LUA CHON TINH NANG ======

		do {

			//=====vong lap nay kiem tra lua chon phuong thuc tim kiem cua nguoi dung, neu khong hop le bao loi va yeu cau nhap lai=====
			do {
				system("cls");
				UMScreen(dataAccount, ID_Login);
				UM_SearchScreen();
				cout << "\nMoi ban chon: ";
				cin >> selectVar;
				if (selectVar < 1 || selectVar>3) {
					cout << "\nLua chon khong hop le. Xin kiem tra lai ...\n\n";
					system("pause");
				}
			} while (selectVar < 1 || selectVar>3);

			//tim theo ID
			if (selectVar == 1) {
				//kiem tra ton tai ID hay khong. Neu khong, bao loi va yeu cau nhap lai
				do {
					system("cls");
					UMScreen(dataAccount, ID_Login);
					cout << "\n=======================================================================\n";
					cout << "\nTIM KIEM THEO ID\n";
					cout << "\n=======================================================================\n";
					cout << "\nNhap ID: ";
					cin >> ID_Search;
					checkSearch = true;
					checkSearch = Search_ID(dataAccount, ID_Search, objSelected);
					if (checkSearch == false) {
						cout << "\nKhong ton tai ID nay. Vui long kiem tra lai\n";
						system("pause");
					}
				} while (checkSearch == false);
			}

			//tim theo ten tai khoan
			else if (selectVar == 2) {
				//kiem tra ton tai ten tai khoan hay khong. Neu khong, bao loi va yeu cau nhap lai
				do {
					system("cls");
					UMScreen(dataAccount, ID_Login);
					cout << "\n=======================================================================\n";
					cout << "\nTIM KIEM THEO TEN TAI KHOAN\n";
					cout << "\n=======================================================================\n";
					cout << "\nNhap ten tai khoan: ";
					cin.ignore();
					cin.getline(AccountName_Search, maxElements);
					checkSearch = true;
					checkSearch = Search_AccountName(dataAccount, AccountName_Search, objSelected);
					if (checkSearch == false) {
						cout << "\nKhong ton tai tai khoan nay. Vui long kiem tra lai\n";
						system("pause");
					}
				} while (checkSearch == false);
			}

			//dang xuat va thoat
			else {
				cout << "\nBan thuc su muon dang xuat va thoat?\n";
				cout << "\n1.Co\n";
				cout << "\n2.Khong\n";
				cout << "\nLua chon: ";
				cin >> selectVar;
				if (selectVar == 1) {
					setAccountData(dataAccount);
					setUserData(dataUser);
					setRoleOfAccountData(dataRoleOfAccount);
					setBookData(dataBook);
					setBorrowedSheetData(dataBorrowedSheet);
					system("pause");
					break;
				}
				else if (selectVar == 2) {
					continue;
				}
			}

			//=============================================MAN HINH LUA CHON TINH NANG THUC HIEN========================================

			//=========khi thuc hien xong tinh nang duoc chon (case) tu dong dua nguoi dung tro ve MAN HINH LUA CHON TINH NANG===========
			do {

				//hien thi cac tinh nang quan ly co the su dung va cho phep lua chon, vong lap nay kiem tra lua chon co hop le hay khong
				do {
					system("cls");
					UMScreen(dataAccount, ID_Login);
					UM_SelectedAcc(dataAccount, objSelected);
					UM_SelectScreen();
					cout << "Moi ban chon: ";
					cin >> selectVar;
					if (selectVar < 1 || selectVar>6) {
						cout << "\nLua chon khong hop le. Xin kiem tra lai ...\n\n";
						system("pause");
					}
				} while (selectVar < 1 || selectVar>6);

				//thuc hien tinh nang vua chon
				switch (selectVar) {

					//================================================CHINH SUA TAI KHOAN===============================================

				case 1: {
					//Lua chon thong tin can chinh sua (1->6) va tro ve (7). Neu nhap khong dung, yeu cau nhap lai
					do {
						system("cls");
						UMScreen(dataAccount, ID_Login);
						UM_SelectedAcc(dataAccount, objSelected);
						cout << "\nCHINH SUA THONG TIN TAI KHOAN\n";
						cout << "=======================================================================\n";
						ShowObj_user(dataUser[objSelected]);
						cout << "\nChon thong tin muon chinh sua: ";
						cin >> selectVar;
						if (selectVar < 1 || selectVar>7) {
							cout << "\nLua chon khong hop le. Vui long thu lai...\n\n";
							system("pause");
						}
					} while (selectVar < 1 || selectVar>7);

					//Chinh sua thong tin vua chon
					if (selectVar != 7) {
						//Hien thi thong tin can chinh sua
						Editing(selectVar);

						//Tien hanh chinh sua
						Setting(dataUser[objSelected], selectVar);

						//Thong bao hoan tat va quay ve man hinh tim kiem
						DoneScreen();

						//Tro ve man hinh chon chuc nang
						break;

					}

					//Tro ve man hinh lua chon chuc nang neu chon 7
					else break;

				}

						//====================================================XOA TAI KHOAN=================================================

				case 2: {

					//Xac nhan xoa tai khoan (1 hoac 2) .Neu nhap khong dung yeu cau nhap lai
					do {
						system("cls");
						UMScreen(dataAccount, ID_Login);
						UM_SelectedAcc(dataAccount, objSelected);
						cout << "\nXOA TAI KHOAN KHOI HE THONG\n";
						ShowObj_account(dataAccount[objSelected], dataRoleOfAccount[objSelected]);
						cout << "\nBAN CO CHAN CHAN MUON XOA TAI KHOAN NAY KHOI HE THONG?\n";
						cout << "\n1.Co\n";
						cout << "\n2.Khong\n";
						cout << "\nLua chon: \n";
						cin >> selectVar;
						if (selectVar < 1 || selectVar>2) {
							cout << "\nLua chon khong hop le. Xin kiem tra lai ...\n\n";
							system("pause");
						}
					} while (selectVar < 1 || selectVar>2);

					//Tien hanh xoa sau do tro ve man hinh chon tinh nang
					//(xoa khoi vector, viec ghi lai thong tin da xu ly se thuc hien khi dong chuong trinh )
					if (selectVar == 1) {
						Delete(dataAccount, dataUser, dataRoleOfAccount, objSelected);

						//Thong bao hoan tat va quay ve man hinh tim kiem
						DoneScreen();

						//sau khi xoa, tai khoan duoc chon bien mat do do se dua nguoi dung tro ve man hinh tim kiem de chon doi tuong khac
						selectVar = 6;

						break;
					}

					//Tro ve man hinh chon tinh nang
					else break;

				}

						//================================================KICH HOAT TAI KHOAN===============================================

				case 3: {

					//Xac nhan mo/khoa tai khoan (1 hoac 2) .Neu nhap khong dung yeu cau nhap lai
					do {
						system("cls");
						UMScreen(dataAccount, ID_Login);
						UM_SelectedAcc(dataAccount, objSelected);
						cout << "\nKICH HOAT TAI KHOAN\n";
						cout << "=======================================================================\n";
						if (dataAccount[objSelected].getisActived() == true) {
							cout << "\nTAI KHOAN HIEN DANG DUOC KICH HOAT. BAN MUON KHOA?\n";
						}
						else {
							cout << "\nTAI KHOAN HIEN DANG TAM KHOA. BAN MUON KICH HOAT?\n";
						}
						cout << "\n1.Co\n";
						cout << "\n2.Khong\n";
						cout << "\nLua chon: \n";
						cin >> selectVar;
						if (selectVar < 1 || selectVar>2) {
							cout << "\nLua chon khong hop le. Xin kiem tra lai ...\n\n";
							system("pause");
						}
					} while (selectVar < 1 || selectVar>2);

					//Khoa tai khoan dang kich hoat
					if (dataAccount[objSelected].getisActived() == true) {
						if (selectVar == 1) {
							dataAccount[objSelected].setisActived(false);

							//Thong bao hoan tat va quay ve man hinh tim kiem
							DoneScreen();

							break;
						}
						else break;
					}

					//Kich hoat tai khoan dang khoa
					else {
						if (selectVar == 1) {
							dataAccount[objSelected].setisActived(true);

							//Thong bao hoan tat va quay ve man hinh tim kiem
							DoneScreen();

							break;
						}
						else break;
					}

				}

						//===============================================THIET DAT LAI MAT KHAU=============================================

				case 4: {

					//Xac nhan thiet lap lai mat khau (1 hoac 2) .Neu nhap khong dung yeu cau nhap lai
					do {
						system("cls");
						UMScreen(dataAccount, ID_Login);
						UM_SelectedAcc(dataAccount, objSelected);
						cout << "\nTHIET LAP LAI MAT KHAU\n";
						cout << "=======================================================================\n";
						cout << "\nBAN CHAN CHAN MUON THIET LAP LAI MAT KHAU CHO TAI KHOAN NAY?\n";
						cout << "\n1.Co\n";
						cout << "\n2.Khong\n";
						cin >> selectVar;
						if (selectVar < 1 || selectVar>2) {
							cout << "\nLua chon khong hop le. Xin kiem tra lai ...\n\n";
							system("pause");
						}
					} while (selectVar < 1 || selectVar>2);

					//Tien hanh reset mat khau (mac dinh mat khau sau reset la "libpro"
					if (selectVar == 1) {
						dataAccount[objSelected].setPassword("libpro");

						//Thong bao hoan tat va quay ve man hinh tim kiem
						DoneScreen();

						break;
					}

					else break;

				}

						//==================================================THAY DOI VAI TRO================================================

				case 5: {

					//Chon vai tro moi (1->7) hoac tro ve (8) .Neu nhap khong dung yeu cau nhap lai
					do {
						system("cls");
						UMScreen(dataAccount, ID_Login);
						UM_SelectedAcc(dataAccount, objSelected);
						cout << "\nTHAY DOI VAI TRO CUA TAI KHOAN\n";
						cout << "=======================================================================\n";
						RoleTable();
						cout << "\nCHON VAI TRO MOI?\n";
						cin >> selectVar;
						if (selectVar < 1 || selectVar>8) {
							cout << "\nLua chon khong hop le. Xin kiem tra lai ...\n\n";
							system("pause");
						}
					} while (selectVar < 1 || selectVar>8);

					//Thuc hien thay doi vai tro
					if (selectVar != 8) {
						dataRoleOfAccount[objSelected].set_RoleID(selectVar);
						selectVar = 0;//gan lai selectVar de quay lai man hinh chon tinh nang
						DoneScreen();

						break;
					}

					//Tro ve
					else break;

				}

						//==============================================TRO VE MAN HINH TIM KIEM===========================================

				case 6: {
					break;
				}

				}

			} while (selectVar != 6);

		} while (selectVar != 3);

		break;
	}

			//===================== THU THU =====================
	case 2: {
		Librarian:
		do {
			//=====vong lap nay kiem tra lua chon tinh nang cua thu thu, neu khong hop le bao loi va yeu cau nhap lai=====
			do {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				Lib_SelectScreen();
				cout << "\nMoi ban chon thao tac muon thuc hien: ";
				cin >> selectVar;
				if (selectVar < 1 || selectVar>15) {
					cout << "\nLua chon khong hop le. Xin kiem tra lai ...\n\n";
					system("pause");
				}
			} while (selectVar < 1 || selectVar>15);

			switch (selectVar) {

				//THEM SACH MOI
			case 1: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nTHEM DAU SACH MOI\n";
				cout << "\n=======================================================================\n";
				addBooks(dataBook, a);
				break;
			}

					//SUA THONG TIN SACH
			case 2: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nSUA THONG TIN SACH\n";
				cout << "\n=======================================================================\n";
				editBooks(dataBook);
				break;
			}

					//XOA THONG TIN SACH
			case 3: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nXOA THONG TIN SACH\n";
				cout << "\n=======================================================================\n";
				deleteBooks(dataBook);
				break;
			}

					//TIM KIEM THONG TIN SACH
			case 4: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nTIM KIEM THONG TIN SACH\n";
				cout << "\n=======================================================================\n";
				showBookSelected(dataBook);
				cout << endl;
				break;
			}

					//LIET KE CAC SACH CUNG THE LOAI
			case 5: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nTIM KIEM THONG TIN SACH THEO THE LOAI\n";
				cout << "\n=======================================================================\n";
				showListCategory(dataBook);
				cout << endl;
				break;
			}

					//IN THONG TIN TAT CA SACH
			case 6: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nTHONG TIN TAT CA CAC DAU SACH HIEN CO TRONG THU VIEN\n";
				cout << "\n=======================================================================\n";
				showListBooks(dataBook);
				cout << endl;
				break;
			}

					//THONG KE SACH DA CHO MUON HET
			case 7: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nCAC DAU SACH DA DUOC MUON HET\n";
				cout << "\n=======================================================================\n";
				showListOutofStock(dataBook);
				cout << endl;
				break;
			}

					//DANG XUAT
			case 8: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nDANG XUAT VA THOAT\n";
				cout << "\n=======================================================================\n";
				cout << "\nBan thuc su muon dang xuat va thoat?\n";
				cout << "\n1.Co\n";
				cout << "\n2.Khong\n";
				cout << "\nLua chon: ";
				cin >> selectVar;
				if (selectVar == 1) {
					setAccountData(dataAccount);
					setUserData(dataUser);
					setRoleOfAccountData(dataRoleOfAccount);
					setBookData(dataBook);
					setBorrowedSheetData(dataBorrowedSheet);
					system("pause");
					selectVar = 8;
					break;
				}
				else if (selectVar == 2) {
					continue;
				}
			}

					//MUON SACH
			case 9: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nTHEM PHIEU MUON MOI\n";
				cout << "\n=======================================================================\n";
				addSheet(dataBorrowedSheet, dataBook, b, dataUser, false);
				cout << endl;
				break;
			}

					//TRA SACH
			case 10: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nXOA THONG TIN PHIEU MUON\n";
				cout << "\n=======================================================================\n";
				deleteSheet(dataBorrowedSheet);
				cout << endl;
				break;
			}

					 //SUA THONG TIN PHIEU MUON
			case 11: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nSUA THONG TIN PHIEU MUON\n";
				cout << "\n=======================================================================\n";
				bool select = true;
				int choice;
				cout << "\n1.Doc gia toi lay sach\n";
				cout << "\n2.Chinh sua phieu muon\n";
				cout << "\nLua chon: "; cin >> choice;
				if (choice == 1) {
					editSheet(dataBorrowedSheet, dataUser,true);
					cout << endl;
					break;
				}
				else if (choice == 2) {
					editSheet(dataBorrowedSheet, dataUser, false);
					cout << endl;
					break;
				}
				else break;
			}

					 //XOA THONG TIN PHIEU MUON
			case 12: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nXOA THONG TIN PHIEU MUON\n";
				cout << "\n=======================================================================\n";
				deleteSheet(dataBorrowedSheet);
				cout << endl;
				break;
			}

					 //TIM THONG TIN PHIEU MUON
			case 13: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nTIM THONG TIN PHIEU MUON\n";
				cout << "\n=======================================================================\n";
				showSheetSelected(dataBorrowedSheet);
				cout << endl;
				break;
			}

					 //IN DANH SACH PHIEU MUON
			case 14: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nDANH SACH TAT CA CAC PHIEU MUON HIEN CO\n";
				cout << "\n=======================================================================\n";
				showListSheets(dataBorrowedSheet);
				cout << endl;
				break;
			}

					 //THONG KE CAC PHIEU MUON QUA HAN
			case 15: {
				system("cls");
				LibScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nDANH SACH CAC PHIEU MUON QUA HAN\n";
				cout << "\n=======================================================================\n";
				showListSheets(dataBorrowedSheet);
				cout << endl;
				break;
			}

			}

		} while (selectVar != 8);

		break;
	}

			//===================== DOC GIA ======================
	case 3: {
		Reader:
		do {
			//=====vong lap nay kiem tra lua chon tinh nang cua thu thu, neu khong hop le bao loi va yeu cau nhap lai=====
			do {
				system("cls");
				ReaderScreen(dataAccount, ID_Login);
				cout << "=========================================================================\n";
				Reader_SelectScreen();
				cout << "\nMoi ban chon thao tac muon thuc hien: ";
				cin >> selectVar;
				if (selectVar < 1 || selectVar>4) {
					cout << "\nLua chon khong hop le. Xin kiem tra lai ...\n\n";
					system("pause");
				}
			} while (selectVar < 1 || selectVar>4);

			switch (selectVar) {

				//XEM VA SUA THONG TIN
			case 1: {
				do {
					system("cls");
					ReaderScreen(dataAccount, ID_Login);
					cout << "=======================================================================\n";
					cout << "\nXEM VA CHINH SUA THONG TIN TAI KHOAN\n";
					cout << "=======================================================================\n";
					ShowObj_user(dataUser[ID_Login]);
					cout << "\nChon thong tin muon chinh sua: ";
					cin >> selectVar;
					if (selectVar < 1 || selectVar>7) {
						cout << "\nLua chon khong hop le. Vui long thu lai...\n\n";
						system("pause");
					}
				} while (selectVar < 1 || selectVar>7);

				//Chinh sua thong tin vua chon
				if (selectVar != 7) {
					//Hien thi thong tin can chinh sua
					Editing(selectVar);

					//Tien hanh chinh sua
					Setting(dataUser[objSelected], selectVar);

					//Thong bao hoan tat va quay ve man hinh tim kiem
					DoneScreen();

					//Tro ve man hinh chon chuc nang
					break;

				}

				//Tro ve man hinh lua chon chuc nang neu chon 7
				else break;

			}

					//MUON SACH
			case 2: {
				system("cls");
				ReaderScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nMUON SACH\n";
				cout << "\n=======================================================================\n";
				BorrowBook(dataBorrowedSheet, dataBook, b, dataUser[ID_Login], true);
				//doc gia chi dang ki muon sach, khi toi thu vien lay sach, thu thu se dieu chinh thong so isReturn ve false
				break;
			}

					//DOI MAT KHAU
			case 3: {
				system("cls");
				ReaderScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nDOI MAT KHAU\n";
				cout << "\n=======================================================================\n";
				char newpass[maxElements];
				cout << "Nhap mat khau moi:";
				cin.ignore();
				cin.getline(newpass, maxElements);
				dataAccount[ID_Login].setPassword(newpass);

				//Thong bao hoan tat va quay ve man hinh dang nhap doc gia
				DoneScreen();
				break;
			}

					//DANG XUAT VA THOAT
			case 4: {
				system("cls");
				ReaderScreen(dataAccount, ID_Login);
				cout << "\n=======================================================================\n";
				cout << "\nDANG XUAT VA THOAT\n";
				cout << "\n=======================================================================\n";
				cout << "\nBan thuc su muon dang xuat va thoat?\n";
				cout << "\n1.Co\n";
				cout << "\n2.Khong\n";
				cout << "\nLua chon: ";
				cin >> selectVar;
				if (selectVar == 1) {
					setAccountData(dataAccount);
					setUserData(dataUser);
					setRoleOfAccountData(dataRoleOfAccount);
					setBookData(dataBook);
					setBorrowedSheetData(dataBorrowedSheet);
					system("pause");
					selectVar = 4;
					break;
				}
				else if (selectVar == 2) {
					continue;
				}
			}

			}

		} while (selectVar != 4);

		break;
	}

			//===================== QUAN LY + THU THU ======================
	case 4: {

		do {
			system("cls");
			manyRoleScreen(dataAccount, ID_Login);
			cout << "\nBAN CO 2 VAI TRO: QUAN LY VA THU THU\n";
			cout << "\n1.QUAN LY\n";
			cout << "\n2.THU THU\n";
			cout << "\n=======================================================================\n";
			cout << "\nMoi ban chon vai tro: ";
			cin >> selectVar;
			if (selectVar < 1 || selectVar>2) {
				cout << "\nLua chon khong hop le. Xin kiem tra lai ...\n\n";
				system("pause");
			}
		} while (selectVar < 1 || selectVar>2);

		if (selectVar == 1) goto UserManager;
		else goto Librarian;

		break;
	}

			//===================== QUAN LY + DOC GIA ======================
	case 5: {

		do {
			system("cls");
			manyRoleScreen(dataAccount, ID_Login);
			cout << "\nBAN CO 2 VAI TRO: QUAN LY VA DOC GIA\n";
			cout << "\n1.QUAN LY\n";
			cout << "\n2.DOC GIA\n";
			cout << "\n=======================================================================\n";
			cout << "\nMoi ban chon vai tro: ";
			cin >> selectVar;
			if (selectVar < 1 || selectVar>2) {
				cout << "\nLua chon khong hop le. Xin kiem tra lai ...\n\n";
				system("pause");
			}
		} while (selectVar < 1 || selectVar>2);

		if (selectVar == 1) goto UserManager;
		else goto Reader;

		break;
	}

			//===================== THU THU + DOC GIA ======================
	case 6: {

		do {
			system("cls");
			manyRoleScreen(dataAccount, ID_Login);
			cout << "\nBAN CO 2 VAI TRO: THU THU VA DOC GIA\n";
			cout << "\n1.THU THU\n";
			cout << "\n2.DOC GIA\n";
			cout << "\n=======================================================================\n";
			cout << "\nMoi ban chon vai tro: ";
			cin >> selectVar;
			if (selectVar < 1 || selectVar>2) {
				cout << "\nLua chon khong hop le. Xin kiem tra lai ...\n\n";
				system("pause");
			}
		} while (selectVar < 1 || selectVar>2);

		if (selectVar == 1) goto Librarian;
		else goto Reader;

		break;
	}

			//===================== All Role ======================
	case 7: {

		do {
			system("cls");
			manyRoleScreen(dataAccount, ID_Login);
			cout << "\nBAN CO 3 VAI TRO: THU THU VA DOC GIA\n";
			cout << "\n1.QUAN LY\n";
			cout << "\n2.THU THU\n";
			cout << "\n3.DOC GIA\n";
			cout << "\n=======================================================================\n";
			cout << "\nMoi ban chon vai tro: ";
			cin >> selectVar;
			if (selectVar < 1 || selectVar>3) {
				cout << "\nLua chon khong hop le. Xin kiem tra lai ...\n\n";
				system("pause");
			}
		} while (selectVar < 1 || selectVar>3);

		if (selectVar == 1) goto UserManager;
		else if (selectVar == 2) goto Librarian;
		else goto Reader;

		break;
	}

	} //dau ngoac nay cua switch case cac vai tro

	//======================================================DON DEP BO NHO======================================================
	dataAccount.clear();
	dataUser.clear();
	dataRoleOfAccount.clear();
	dataBook.clear();
	dataBorrowedSheet.clear();
	return 0;
}

//class test {
//private:
//	int year;
//public:
//	void setyear(int a) {
//		year = a;
//	}
//	int getYear() {
//		return year;
//	}
//	int isLeapYear() {
//		if ((getYear() % 4 == 0 && getYear() % 100 != 0) || (getYear() % 400 == 0)) return 366;
//		else return 365;
//	}
//};
//int main() {
//	test demo;
//	demo.setyear(206);
//	int kq = demo.isLeapYear();
//	cout << kq;
//	system("pause");
//	return 0;
//}