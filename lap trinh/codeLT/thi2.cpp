#include <iostream>
#include <string>
using namespace std;

class MonHoc {
    string maMon;   
    string tenMon;  
    int tinChi;     
public:
    void nhap() {
        cout << "Nhap ma mon hoc: ";
        cin >> maMon;
        cout << "Nhap ten mon hoc: ";
        cin.ignore();  
        getline(cin, tenMon);
        cout << "Nhap so tin chi: ";
        cin >> tinChi;
    }

     void xuat() const {
        cout << "Ma mon: " << maMon << ", Ten mon: " << tenMon << ", Tin chi: " << tinChi << endl;
    }
	string getMaMon() const { return maMon; }
    string getTenMon() const { return tenMon; }
    int getTinChi() const { return tinChi; }
};

class DMP {
private:
    string maSV;       
    string tenSV;      
    MonHoc* dsMonHoc;   
    int soMonHoc;       
public:
    DMP(int soMon) {
        dsMonHoc = new MonHoc[soMon];
        soMonHoc = soMon;
    }
	 ~DMP() {
        delete[] dsMonHoc;
    }
    void nhap() {
        cout << "Nhap ma sinh vien: ";
        cin >> maSV;
        cout << "Nhap ten sinh vien: ";
        cin.ignore();
        getline(cin, tenSV);

        cout << "Nhap danh sach cac mon hoc sinh vien dang ky:" << endl;
        for (int i = 0; i < soMonHoc; i++) {
            cout << "Mon hoc thu " << i + 1 << ":" << endl;
            dsMonHoc[i].nhap();
        }
    }
	void xuat() const {
        cout << "Ma sinh vien: " << maSV << ", Ten sinh vien: " << tenSV << endl;
        cout << "Danh sach cac mon hoc da dang ky:" << endl;
        for (int i = 0; i < soMonHoc; i++) {
            cout << "- ";
            dsMonHoc[i].xuat();
        }
    }
};
int main() {
    int m, n;
    cout << "Nhap so luong mon hoc: ";
    cin >> m;
    MonHoc* dsMonHoc = new MonHoc[m];
    cout << "Nhap danh sach mon hoc:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "Mon hoc thu " << i + 1 << ":" << endl;
        dsMonHoc[i].nhap();
    }
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
      DMP* dsDMP = nullptr;
    for (int i = 0; i < n; i++) {
        int soMonHocSV;
        cout << "Nhap so mon hoc sinh vien thu " << i + 1 << " dang ky: ";
        cin >> soMonHocSV;
        
        dsDMP = new DMP(soMonHocSV); 
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        dsDMP[i].nhap();
    }
    cout << "Thong tin cac mon hoc:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "- ";
        dsMonHoc[i].xuat();
    }
    cout << "Thong tin dang ky hoc phan cua cac sinh vien:" << endl;
    for (int i = 0; i < n; i++) {
        dsDMP[i].xuat();
    }
    delete[] dsMonHoc;
    delete[] dsDMP;
    return 0;
}


