#pragma warning( disable: 4996)
#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
struct Sach{
	char MaSach[8];
	char TenSach[100], TheLoai[100], NXB[100];
	int TongSL, SLHienTai, SoLanMuon;
};
struct DATE{
	int ngay;
	int thang;
	int nam;
};
struct PhieuMuon{
	char MaPhieu[8];
	DATE NgayMuon;
	char HoTen[50];
	int SoLuongSach;
};
struct CTPM{
	char MaSach[8];
	char MaPhieu[8];
	char TinhTrangSach[50];
	bool Tra;
};
typedef Sach ListSach[50];
typedef PhieuMuon ListPhieu[50];
typedef CTPM ListCTPM[200];
int  Tim_MSSach(ListSach a, int n, char c[8]);
int  Tim_MSPhieu(ListPhieu b, int m, char c[8]);
void InChiTietPhieu(ListPhieu b, int m, char ms[8]);
void InChiTietSach(ListSach a, int n, char ms[8]);
ListSach a;
ListPhieu b;
ListCTPM c;
int n = 0, m = 0, k = 0;//n la tong so sach , m la tong so phieu muon , k la tong so sach dc muon trong tung chi tiet phieu muon
//Kiem tra nam nhuan
int ktnamnhuan(int nam){
	if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) return 366;
	else return 365;
}
// Tinh so ngay cua 1 thang
int ktthang(int thang, int nam) {
	if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
		return 30;
	}
	if ((thang == 2) && (ktnamnhuan(nam) == 366)) return 29;
	else if (thang == 2 && ktnamnhuan(nam) == 365) return 28;
	else return 31;
}
//Tinh so ngay tu dau nam cho den ngay hien tai
int vitri(int ngay, int thang, int nam){
	int N = 0, i;
	for (i = 1; i<thang; ++i)
	{
		N = N + ktthang(i, nam);
	}
	return (N + ngay);
}
//Tinh so ngay giua 2 nam
int kcnam(int namtruoc, int namsau){
	int N = 0, i;
	i = namtruoc + 1;
	for (i; i<namsau; ++i)
	{
		N = N + ktnamnhuan(i);
	}
	return N;
}
//Them sach moi vao thu vien
void ThemSach(ListSach a, int &n){
	n++;
	cout << "\n                         THEM MOT DAU SACH MOI VAO THU VIEN \n";
	cout << "===============================================================================\n";
nhaplaimasach:  cout << "Nhap MS :";
	cin >> a[n].MaSach;
	if (Tim_MSSach(a, n - 1, a[n].MaSach) != 0){       // Kiem tra ma sach co bi trung khong
		cout << "Ma Sach Da Co , Vui Long Nhap Lai \n";
		goto nhaplaimasach;
	}
	cout << "Nhap Ten Sach ";
	cin.ignore();
	cin.getline(a[n].TenSach, 100);
	cout << "Nhap Ten The Loai ";
	cin.getline(a[n].TheLoai, 100);
	cout << "Nhap Ten Nha Xuat Ban ";
	cin.getline(a[n].NXB, 100);
	cout << "Nhap Tong So Luong Sach ";
	cin >> a[n].TongSL;
	a[n].SLHienTai = a[n].TongSL;
	cout << "\n THEM DAU SACH MOI THANH CONG ";
}
//Tim ma so sach
int Tim_MSSach(ListSach a, int n, char c[8]){
	int i;
	i = 1;
	while ((i <= n) && (strcmp(a[i].MaSach, c) != 0))
		i++;
	if (i>n) return 0;
	else return i;
}
//Xoa thong tin mot quyen sach
void XoaSach(ListSach a, int &n){
	char ms[8];
	int vitri;
	cout << "\n                         XOA THONG TIN SACH  \n";
	cout << "===============================================================================\n";
	cout << "Nhap Vao Ma So Cua Sach :";
	cin >> ms;
	vitri = Tim_MSSach(a, n, ms);
	if (vitri == 0)
		cout << "KO CO MA SO SACH NAY \n";
	else{
		if (a[vitri].SLHienTai<a[vitri].TongSL)
			cout << "\n Quyen Sach Dang Co nguoi muon , ban ko the xoa thong tin sach \n";
		else{
			for (int i = vitri; i <= n; i++)
				a[i] = a[i + 1];
			n--;
			cout << "Xoa Thanh Cong ";
		}
	}
}
//Sua thong tin sach
void SuaSach(ListSach a, int &n){
	char ms[8];
	int vitri, slmuon = 0;
	cout << "\n                         SUA THONG TIN SACH \n";
	cout << "===============================================================================\n";
	cout << "Nhap Vao Ma So Cua Sach :";
	cin >> ms;
	vitri = Tim_MSSach(a, n, ms);  //Kiem tra ma so sach co ton tai khong
	if (vitri == 0)
		cout << "KO CO MA SO SACH NAY ";
	else{
		InChiTietSach(a, n, ms);
		slmuon = a[vitri].TongSL - a[vitri].SLHienTai;
		cout << "\n NHAP VAO THONG TIN MOI CHO QUYEN SACH \n";
		cout << "Nhap Ten Sach ";
		cin.getline(a[vitri].TenSach, 100);
		cin.getline(a[vitri].TenSach, 100);
		cout << "Nhap Ten The Loai ";
		cin.getline(a[vitri].TheLoai,100);
		cout << "Nhap Ten Nha Xuat Ban ";
		cin.getline(a[vitri].NXB,100);
		cout << "Nhap Tong So Luong Sach ";
		cin >> a[vitri].TongSL;
		a[vitri].SLHienTai = a[vitri].TongSL - slmuon;
		cout << "\n SUA THONG TIN SACH THANH CONG \n";
	}
}
//Liet ke cac sach co trong thu vien
void InToanBoSach(ListSach a, int n){
	cout << "\n \n                 DANH SACH TAT CA SACH CO TRONG THU VIEN ";
	cout << "\n  ===============================================================================";
	cout << "\n  Ma Sach       Ten Sach                           The Loai         TSL      SL ";
	cout << "\n  -------------------------------------------------------------------------------";
	for (int i = 1; i <= n; i++)
		cout << "\n  " << a[i].MaSach << setw(8 - strlen(a[i].MaSach) + 1) << "  " << a[i].TenSach << setw(40 - strlen(a[i].TenSach) + 1) << "   " << a[i].TheLoai << setw(13 - strlen(a[i].TheLoai) + 1) << "  " << setw(5) << a[i].TongSL << "   " << setw(5) << a[i].SLHienTai ;
	cout << "\n  -------------------------------------------------------------------------------";
}
//Liet ke chi tiet 1 cuon sach
void InChiTietSach(ListSach a, int n, char ms[8]){
	int vitri;
	vitri = Tim_MSSach(a, n, ms);
	if (vitri == 0)
		cout << "Ko Tim Thay Ma So Sach Nhap Vao \n";
	else{
		cout << "\n    THONG TIN CHI TIET SACH \n" << endl;
		cout << "Ma So       : " << a[vitri].MaSach << endl;
		cout << "Ten Sach    : " << a[vitri].TenSach << endl;
		cout << "The Loai    : " << a[vitri].TheLoai << endl;
		cout << "NXB         : " << a[vitri].NXB << endl;
		cout << "Tong SL     : " << a[vitri].TongSL << endl;
		cout << "SL Hien Con : " << a[vitri].SLHienTai << endl;
	}
}
// Liet ke theo mot the loai sach
void TimSachTheLoai(ListSach a, int n){
	char tentheloai[50];
	int dem = 0;
	cout << "\n                         LIET KE CAC SACH THEO MOT THE LOAI \n";
	cout << "===============================================================================\n";
	cout << "Nhap Vao Ten The Loai Muon Tim :";
	cin.ignore();
	cin.getline(tentheloai, 50);
	cout << "\n  -----------------------------------------------------------------------------";
	cout << "\n  Ma Sach   Ten Sach                                                TSL    SL ";
	cout << "\n  -----------------------------------------------------------------------------";
	for (int i = 1; i <= n; i++){
		if (strcmp(a[i].TheLoai, tentheloai) == 0){
			cout << "\n  " << a[i].MaSach << setw(8 - strlen(a[i].MaSach) + 1) << " " << a[i].TenSach << setw(53 - strlen(a[i].TenSach) + 1) << " " << setw(5) << a[i].TongSL << " " << setw(5) << a[i].SLHienTai << " "; dem++;
		}
	}
	cout << "\n  -----------------------------------------------------------------------------";
	if (dem == 0)
		cout << "\n \n KO TIM THAY THE LOAI SACH MA BAN NHAP VAO \n";
}
//Thong ke sach nao da muon het trong thu vien
void ThongKeSachHet(ListSach a, int n){
	cout << "\n             CAC DAU SACH DA CHO MUON HET TRONG THU VIEN ";
	cout << "\n  =======================================================================";
	cout << "\n  Ma Sach                  Ten Sach                   The Loai     TSL ";
	cout << "\n  ----------------------------------------------------------------------";
	for (int i = 1; i <= n; i++)
		if (a[i].SLHienTai == 0)
			cout << "\n  " << a[i].MaSach << setw(8 - strlen(a[i].MaSach) + 1) << "" << a[i].TenSach
			<< setw(40 - strlen(a[i].TenSach) + 1) << "" << a[i].TheLoai << setw(13 - strlen(a[i].TheLoai) + 1)
			<< "" << setw(5) << a[i].TongSL << "";
	cout << "\n  ----------------------------------------------------------------------";
}

int KT_TTSach(char ms[8]){   //Ham nay de kiem tra tinh trang cua sach truoc khi cho muon
	int i;
	i = 1;
	while ((i <= n) && (strcmp(a[i].MaSach, ms) != 0))
		i++;
	if (i>n)
		return 0;
	if (a[i].SLHienTai == 0)
		return -1;
	return i;
}

void ThemCTPM(ListCTPM c, int &k, int SoLuongSach, char MSPhieu[8]){
	int x;
	for (int i = 1; i <= SoLuongSach; i++){
		k++;
	nhaplaisach:
		cout << "Nhap Vao Ma So Sach ";
		cin >> c[k].MaSach;
		x = KT_TTSach(c[k].MaSach);
		if (x == 0){
			cout << "Ma Sach Nay Ko co \n";
			goto nhaplaisach;
		}
		else if (x == -1){
			cout << "Cuon Sach nay da cho muon het \n";
			goto nhaplaisach;
		}
		else{
			strcpy(c[k].MaPhieu, MSPhieu);
			c[k].Tra = false;
			cout << "Nhap Vao Tinh Trang Cuon Sach \n";
			cin.getline(c[k].TinhTrangSach,50);
			cin.getline(c[k].TinhTrangSach, 50);
			a[x].SLHienTai--;
			a[x].SoLanMuon++;
		}
	}
}
void InCTPM(ListCTPM c, int k, char MSPhieu[8]){
	cout << "\n \n                CAC SACH TRONG PHIEU MUON ";
	cout << "\n    ===================================================================";
	cout << "\n    Ma Sach                Tinh Trang                        Tra   ";
	cout << "\n    -------------------------------------------------------------------";
	for (int i = 1; i <= k; i++)
		if (strcmp(c[i].MaPhieu, MSPhieu) == 0)
		{
			cout << "\n    " << c[i].MaSach << setw(8 - strlen(c[i].MaSach) + 1) << "" << c[i].TinhTrangSach << setw(47 - strlen(c[i].TinhTrangSach) + 1) << "" << setw(8);
			if (c[i].Tra == false)cout << "Chua Tra"; else  cout << "Da Tra";
			cout << "";
		}
	cout << "\n   ---------------------------------------------------------------------";
}
void XoaCTPM(ListCTPM c, int &k, char MSPhieu[8]){
	int vitrisach;
	int vitri, dem = 0;
	for (int i = 1; i <= k; i++)
		if (strcmp(c[i].MaPhieu, MSPhieu) == 0 && c[i].Tra == false){
			vitri = i;
			dem++;
			vitrisach = Tim_MSSach(a, n, c[i].MaSach);
			a[vitrisach].SLHienTai++;
		}
	vitri = vitri - dem + 1;
	for (int i = vitri; i <= k; i++)
		c[i] = c[i + dem];
	k = k - dem;
}
void MuonSach(){
	char msphieu[8];
	int slsach;
	int l;
	cout << "\n                         MUON THEM SACH \n";
	cout << "===============================================================================\n";
	cout << "\n \n \n Nhap Vao Ma So Phieu Can Muon Sach ";
	cin >> msphieu;
	l = Tim_MSPhieu(b, m, msphieu);
	if (l != 0){
		InChiTietPhieu(b, m, msphieu);
		cout << "\n Nhap Vao So Luong Sach Ban Can Muon ";
		cin >> slsach;
		ThemCTPM(c, k, slsach, b[l].MaPhieu);
		b[l].SoLuongSach = b[l].SoLuongSach + slsach;
		cout << "\n MUON SACH THANH CONG ";
	}
	else
		cout << "\n KO CO MA SO PHIEU NAY ";
}
void TraSach(){
	char msphieu[8], mssach[8];
	cout << "\n                         TRA SACH \n";
	cout << "===============================================================================\n";
	cout << "Nhap Vao Ma So Phieu ";
	cin >> msphieu;
	if (Tim_MSPhieu(b, m, msphieu) == 0)
		cout << "KO CO MA SO PHIEU NAY ";
	else{
		InChiTietPhieu(b, m, msphieu);
		int soluongsach = b[Tim_MSPhieu(b, n, msphieu)].SoLuongSach;
		int i, dem = 0, slsachtra;
		for (int j = 1; j <= k; j++){      //tinh so luong sach chua tra cua phieu muon
			if (c[j].Tra == false && strcmp(c[j].MaPhieu, msphieu) == 0)
				dem++;
		}
		do{
			cout << "\n Nhap Vao So Luong Sach Ma Ban Muon Tra \n";
			cin >> slsachtra;
			if (slsachtra>dem)
				cout << "So Luong Sach Ban Muon Tra Lon Hon So Luong Sach Ban Muon \n";
		} while (slsachtra>dem);
		for (int j = 1; j <= slsachtra; j++){
			cout << "\n Nhap Ma So Cuon Sach Ban Muon Tra ";
			cin >> mssach;
			if (Tim_MSSach(a, n, mssach) == 0)
				cout << "Ko Co Ma So Cuon Sach Nay";
			else{
				for (i = 0; i <= k; i++){
					if (strcmp(c[i].MaPhieu, msphieu) == 0 && strcmp(c[i].MaSach, mssach) == 0 && c[i].Tra == false){
						a[Tim_MSSach(a, n, mssach)].SLHienTai++;
						c[i].Tra = true;
						break;
					}
				}
				if (i>k)
					cout << "\n Tra Cuon Sach Nay Ko Thanh Cong , Vui Long Xem Lai Thong Tin Ban Da Nhap vao ";
				else
					cout << "\n Tra Cuon Sach Nay Thanh Cong ";
			}
		}
	}
}
//Tim ma so phieu muon
int Tim_MSPhieu(ListPhieu b, int m, char c[8]){
	int i;
	i = 1;
	while ((i <= m) && (strcmp(b[i].MaPhieu, c) != 0))
		i++;
	if (i>m) return 0;
	else return i;
}
//Them phieu muon moi
void ThemPhieu(ListPhieu b, int &m){
	m++;
	int mssach, ngay, thang, nam;
	cout << "\n                         THEM MOT PHIEU MUON MOI  \n";
	cout << "===============================================================================\n";
nhaplaimaphieu: cout << "Nhap Vao Ma Phieu :";
	cin >> b[m].MaPhieu;
	if (Tim_MSPhieu(b, m - 1, b[m].MaPhieu) != 0){
		cout << "Ma Phieu Da Co , Vui Long Nhap Lai \n";
		goto nhaplaimaphieu;
	}
	cout << "Nhap Vao Ho Ten ";
	cin.ignore();
	cin.getline(b[m].HoTen,50);
NhapNgay:
	cout << ("\n  NHAP NGAY THANG NAM MUON SACH \n");
	cout << ("\n         NGAY : ");
	cin >> ngay;
	cout << ("\n         THANG : ");
	cin >> thang;
	cout << ("\n         NAM : ");
	cin >> nam;
	if (ngay>0 && ngay<ktthang(thang, nam) && thang>0 && thang <= 12 && nam>0){
		b[m].NgayMuon.ngay = ngay;
		b[m].NgayMuon.thang = thang;
		b[m].NgayMuon.nam = nam;
	}
	else{
		system("cls");
		cout << ("\n BAN DA NHAP SAI NGAY THANG \n\n");
		cout << ("\n XIN MOI NHAP LAI \n\n");
		goto NhapNgay;
	};
	cout << "Nhap Vao So Luong Sach ";
	cin >> b[m].SoLuongSach;
	ThemCTPM(c, k, b[m].SoLuongSach, b[m].MaPhieu);

	cout << "\n THEM PHIEU MUON SACH THANH CONG \n";
}
//Sua thong tin phieu muon
void SuaPhieu(ListPhieu b, int m){
	int msphieu;
	char ms[8];
	int mssach, ngay, thang, nam;
	cout << "\n                         SUA THONG TIN PHIEU MUON SACH  \n";
	cout << "===============================================================================\n";
	cout << "\n Nhap Vao Ma Phieu Can Sua Thong Tin :";
	cin >> ms;
	msphieu = Tim_MSPhieu(b, m, ms);
	if (msphieu == 0)
		cout << "Ma Phieu Ko Co \n";
	else{
		cout << "Nhap Vao Ho Ten ";
		cin.getline(b[msphieu].HoTen,50);
		cin.getline(b[msphieu].HoTen, 50);
	NhapNgay:
		cout << ("\n  NHAP NGAY THANG NAM MUON SACH  \n");
		cout << ("\n         NGAY : ");
		cin >> ngay;
		cout << ("\n         THANG : ");
		cin >> thang;
		cout << ("\n         NAM : ");
		cin >> nam;
		if (ngay>0 && ngay<ktthang(thang, nam) && thang>0 && thang <= 12 && nam>0){
			b[msphieu].NgayMuon.ngay = ngay;
			b[msphieu].NgayMuon.thang = thang;
			b[msphieu].NgayMuon.nam = nam;
		}
		else{
			system("cls");
			cout << ("\n BAN DA NHAP SAI NGAY THANG \n\n");
			cout << ("\n XIN MOI NHAP LAI \n\n");
			goto NhapNgay;
		}
		XoaCTPM(c, k, b[msphieu].MaPhieu);
		cout << "Nhap Vao So Luong Sach ";
		cin >> b[msphieu].SoLuongSach;
		ThemCTPM(c, k, b[msphieu].SoLuongSach, b[msphieu].MaPhieu);
	}
}
//Xoa thong tin phieu muon
void XoaPhieu(ListPhieu b, int &m){
	int vitriphieu;
	char ms[8];
	int mssach;
	cout << "\n                         XOA THONG TIN PHIEU MUON SACH \n";
	cout << "===============================================================================\n";
	cout << "Nhap Vao Ma Phieu Can Xoa Thong Tin :";
	cin >> ms;
	vitriphieu = Tim_MSPhieu(b, m, ms);
	if (vitriphieu == 0)
		cout << "Khong Tim Thay Ma Phieu \n";
	else{
		XoaCTPM(c, k, b[vitriphieu].MaPhieu);
		for (int j = vitriphieu; j<m; j++)
			b[j] = b[j + 1];
		m--;
		cout << "XOA THONG TIN PHIEU THANH CONG \n";
	}
}
//Liet ke cac phieu muon
void InDanhSachPhieu(ListPhieu b, int m){
	cout << "\n                   DANH SACH CAC PHIEU MUON SACH ";
	cout << "\n     =======================================================";
	cout << "\n        MS       Ho Va Ten        Ngay Muon  So Luong ";
	cout << "\n      --------------------------------------------------";
	for (int i = 1; i <= m; i++)
		cout << "\n      " << b[i].MaPhieu << setw(8 - strlen(b[i].MaPhieu) + 1) << ""
		<< b[i].HoTen << setw(19 - strlen(b[i].HoTen) + 1) << ""
		<< setw(4) << b[i].NgayMuon.ngay << "" << setw(2) << b[i].NgayMuon.thang << ""
		<< b[i].NgayMuon.nam << "" << setw(10) << b[i].SoLuongSach << "";
	cout << "\n     ----------------------------------------------------";
}
//Liet ke cac phieu muon qua han
void InPhieuMuonQuaHan(ListPhieu b, int m){
	int ngay, thang, nam, SoNgay;
	char chuoingay[2], chuoithang[2], chuoinam[4];
	tm *today;
	time_t ltime;
	time(&ltime);
	today = localtime(&ltime);
	ngay = today->tm_mday;
	thang = today->tm_mon + 1;
	nam = today->tm_year + 1900;
	cout << "\n                     HOM NAY LA :" << ngay << "-" << thang << "-" << nam << endl;
	cout << "\n             DANH SACH CAC PHIEU MUON SACH QUA HAN    ";
	cout << "\n      =======================================================";
	cout << "\n        MS        Ho Va Ten        Ngay Muon  So Luong ";
	cout << "\n      ---------------------------------------------------";
	for (int i = 1; i <= m; i++){
		if (b[i].NgayMuon.nam == nam){
			SoNgay = vitri(ngay, thang, nam) - vitri(b[i].NgayMuon.ngay, b[i].NgayMuon.thang, b[i].NgayMuon.nam);
		}
		else if (b[i].NgayMuon.nam != nam){
			SoNgay = ktnamnhuan(b[i].NgayMuon.nam) - vitri(b[i].NgayMuon.ngay, b[i].NgayMuon.thang, b[i].NgayMuon.nam) + 1 + vitri(ngay, thang, nam);
		}
		int consach = 0;
		for (int j = 1; j <= k; j++){
			if (strcmp(c[j].MaPhieu, b[i].MaPhieu) == 0 && c[j].Tra == false){
				consach = 1;
				break;
			}
		}
		if (SoNgay >= 30 && consach == 1)
			cout << "\n      " << b[i].MaPhieu << setw(8 - strlen(b[i].MaPhieu) + 1) << ""
			<< b[i].HoTen << setw(19 - strlen(b[i].HoTen) + 1) << ""
			<< setw(4) << b[i].NgayMuon.ngay << "-" << setw(2) << b[i].NgayMuon.thang << "-"
			<< b[i].NgayMuon.nam << "" << setw(10) << b[i].SoLuongSach << "";
	}
	cout << "\n      ---------------------------------------------------------";

}
//In thong tin mot phieu muon
void InChiTietPhieu(ListPhieu b, int m, char ms[8]){
	int vitri;
	cout << "\n                         THONG TIN CHI TIET PHIEU MUON SACH \n";
	cout << "===============================================================================\n";
	vitri = Tim_MSPhieu(b, m, ms);
	if (vitri == 0)
		cout << "KO CO MA SO PHIEU NAY ";
	else{
		cout << "\n      --------------------------------------------------------";
		cout << "\n        MS        Ho Va Ten        Ngay Muon  So Luong  ";
		cout << "\n      ---------------------------------------------------";
		cout << "\n      " << b[vitri].MaPhieu << setw(8 - strlen(b[vitri].MaPhieu) + 1) << "" << b[vitri].HoTen << setw(19 - strlen(b[vitri].HoTen) + 1) << "" << setw(4) << b[vitri].NgayMuon.ngay << "" << setw(2) << b[vitri].NgayMuon.thang << ""
			<< b[vitri].NgayMuon.nam << "" << setw(11) << b[vitri].SoLuongSach << "";
		cout << "\n      ----------------------------------------------------";
		InCTPM(c, k, b[vitri].MaPhieu);
	}
}
void DocGiaMuonNhieu(){
	ListPhieu d;
	PhieuMuon tam;
	int min, h;
	for (int i = 1; i <= m; i++)
		d[i] = b[i];
	int post;
	for (int i = 2; i <= m; i++){
		tam = d[i];
		post = i - 1;
		while (post >= 1 && d[post].SoLuongSach>tam.SoLuongSach)
		{
			d[post + 1] = d[post]; post--;
		}
		d[post + 1] = tam;
	}
	cout << "\n            CAC DOC GIA MUON SACH NHIEU TRONG THU VIEN ";
	cout << "\n     =========================================================";
	cout << "\n        MS        Ho Va Ten        Ngay Muon  So Luong  ";
	cout << "\n      ---------------------------------------------------";
	if (m>10) h = 10;  else    h = m;//chi in ra 10 doc gia muon sach nhieu nhat
	for (int i = h; i >= 1; i--){
		cout << "\n      " << d[i].MaPhieu << setw(8 - strlen(d[i].MaPhieu) + 1) << "" << d[i].HoTen << setw(19 - strlen(d[i].HoTen) + 1) << "" << setw(4) << d[i].NgayMuon.ngay << "-" << setw(2) << d[i].NgayMuon.thang << "-"
			<< d[i].NgayMuon.nam << "" << setw(11) << d[i].SoLuongSach << "";
	}
	cout << "\n      ----------------------------------------------------------";
}
//Luu du lieu
void GhiDuLieu(ListSach a, ListPhieu b, ListCTPM c, int n, int m, int k){
	FILE *f;
	f = fopen("DATA.DAT", "wb");
	fwrite(&n, sizeof(int), 1, f);
	fwrite(&m, sizeof(int), 1, f);
	fwrite(&k, sizeof(int), 1, f);
	for (int i = 1; i <= n; i++)
		fwrite(&a[i], sizeof(Sach), 1, f);
	for (int j = 1; j <= m; j++)
		fwrite(&b[j], sizeof(PhieuMuon), 1, f);
	for (int x = 1; x <= k; x++)
		fwrite(&c[x], sizeof(CTPM), 1, f);
	fclose(f);
	cout << "\n GHI DU LIEU VAO FILE THANH CONG \n";
}
//Doc du lieu
void DocDuLieu(ListSach &a, ListPhieu &b, ListCTPM &c, int &n, int &m, int &k){
	FILE *f;
	Sach g;
	PhieuMuon d;
	CTPM e;
	f = fopen("DATA.DAT", "rb");
	if (f == NULL)
		cout << "\n                FILE DU LIEU KHONG TON TAI VUI LONG TAO MOI DANH SACH \n \n \n";
	else{
		fread(&n, sizeof(int), 1, f);
		fread(&m, sizeof(int), 1, f);
		fread(&k, sizeof(int), 1, f);
		for (int i = 1; i <= n; i++){
			fread(&g, sizeof(Sach), 1, f);
			a[i] = g;
		}
		for (int j = 1; j <= m; j++){
			fread(&d, sizeof(PhieuMuon), 1, f);
			b[j] = d;
		}
		for (int x = 1; x <= k; x++){
			fread(&e, sizeof(CTPM), 1, f);
			c[x] = e;
		}
		fclose(f);
	}
}
int Menu(){
	cout << "\n                          CHUONG TRINH QUAN LY THU VIEN        ";
	cout << "\n     =======================================================================";
	cout << "\n     |          QUAN LY SACH            |      QUAN LY PHIEU MUON          |";
	cout << "\n     -----------------------------------------------------------------------";
	cout << "\n      1 .Them Mot Dau Sach Moi             9.Them Phieu Moi                 ";
	cout << "\n      2 .Sua Thong Tin Sach                10.Sua Thong Tin Phieu Muon       ";
	cout << "\n      3 .Xoa Thong Tin Sach                11.Xoa Thong Tin Phieu Muon       ";
	cout << "\n      4 .Tim Kiem Thong Tin Sach           12.Tim Thong Tin Phieu Muon       ";
	cout << "\n      5 .Liet Ke Cac Sach Cung The Loai    13.Muon Sach                      ";
	cout << "\n      6 .In Thong Tin Tat Ca Sach          14.Tra Sach                       ";
	cout << "\n      7 .Thong Ke Sach Da Cho Muon Het     15.In Dach Sach Phieu Muon        ";
	cout << "\n      8 .Thoat Khoi Chuong Trinh           16.Thong Ke Cac Phieu Muon Qua Han";
	cout << "\n                                           17.Cac Doc Gia Muon Nhieu Sach    ";
	cout << "\n     ---------------------------------------------------------------------";
	cout << "\n                   Vui Long Chon Cac Phim Chuc Nang Tuong Ung   ";
	int chon;
	cin >> chon;
	system("cls");
	return chon;
}

void Thoat(){
	cout << "\n \n \n ==============================================================================";
	cout << "\n                       Nhan ENTER De Ra Menu Chinh \n ";
	getch();
	system("cls");
}
//////////////////////////////////////////////////////////////////////////////////////

int main(){
	DocDuLieu(a, b, c, n, m, k);
	int chon;
	char ms[8];
	while (1)
	{
		chon = Menu();
		switch (chon){
		case 1:ThemSach(a, n); Thoat(); break;
		case 2:SuaSach(a, n); Thoat(); break;
		case 3:XoaSach(a, n); Thoat(); break;
		case 4:
			cout << "Nhap Vao Ma So Sach Can Xem Thong Tin \n ";
			cin >> ms;
			InChiTietSach(a, n, ms); Thoat(); break;
		case 5:TimSachTheLoai(a, n); Thoat(); break;
		case 6:InToanBoSach(a, n); Thoat(); break;
		case 7:ThongKeSachHet(a, n); Thoat(); break;
		case 8:goto exit; break;
		case 9:ThemPhieu(b, m); Thoat(); break;
		case 10:SuaPhieu(b, m); Thoat(); break;
		case 11:XoaPhieu(b, m); Thoat(); break;
		case 12:
			cout << "Nhap Vao Ma So Cua Phieu Can Xem Thong Tin Chi Tiet :\n";
			cin >> ms;
			InChiTietPhieu(b, m, ms); Thoat(); break;
		case 13:MuonSach(); Thoat(); break;
		case 14:TraSach(); Thoat(); break;
		case 15:InDanhSachPhieu(b, m); Thoat(); break;
		case 16:InPhieuMuonQuaHan(b, m); Thoat(); break;
		case 17:DocGiaMuonNhieu(); Thoat(); break;
		default:goto exit; break;
		}
	}
exit:   cout << "\nBAN CO MUON LUU DU LIEU VAO FILE KHONG ? - Y/N \n";
	int ch = getch();
	if (toupper(ch) == 'Y')
		GhiDuLieu(a, b, c, n, m, k);
}