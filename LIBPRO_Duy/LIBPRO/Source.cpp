//#include<iostream>
//#include<string>
//#include<fstream>
//#include<cstdlib>
//#include<ctime>
//
//using namespace std;
//
//#define max_size 256
//
//class account {
//private:
//	string tentaikhoan,matkhau,maso;
//public:
//	void settaikhoan(string a) {
//		tentaikhoan = a;
//	}
//	void setmatkhau(string a) {
//		matkhau = a;
//	}
//	void setmaso(string a) {
//		maso = a;
//	}
//	string gettaikhoan() { return tentaikhoan; }
//	string getmatkhau() { return matkhau; }
//	string getmaso() { return maso; }
//};
//int main() {
//	/*account* arr = new account[3];
//	fstream datafile("demo.dat",ios::out|ios::binary|ios::app);
//	for (int i = 0; i < 3; i++) {
//		string a;
//		cout << "Nhap ten tai khoan arr[" << i << "]: ";
//		getline(cin,a);
//		arr[i].settaikhoan(a);
//		cout << "Nhap mat khau arr[" << i << "]: ";
//		getline(cin, a);
//		arr[i].setmatkhau(a);
//		cout << "Nhap ma so arr[" << i << "]: ";
//		getline(cin, a);
//		arr[i].setmaso(a);
//		datafile.write(reinterpret_cast<char*>(&arr[i]), sizeof(arr[i]));
//	}
//	datafile.close();*/
//	account* arr = new account[3];
//	fstream datafile("demo.dat", ios::in);
//	int i = 0;
//	while (datafile.good()) {
//		datafile.read(reinterpret_cast<char*>(&arr[i]), sizeof(arr[i]));
//		if (datafile.eof()) break;
//		cout << arr[i].getmaso() << "\t" << arr[i].gettaikhoan() << "\t" << arr[i].getmatkhau() << endl;
//		i++;
//	}
//	datafile.close();
//	system("pause");
//	return 0;
//}
