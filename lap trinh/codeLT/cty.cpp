#include <iostream>
#include <string>
using namespace std;

// Lop co so cty
class cty {
    string ten;
    int ntl;
public:
    string lay_ten() { return ten; }
    int lay_ntl() { return ntl; }
    void nhap();
};
// Lop dan xuat ctypm (cong ty phan mem)
class ctypm : public cty {
    int sltv;
public:
    int lay_ltv() { return sltv; }
    void nhap();
};

// Lop dan xuat ctyvt (cong ty van tai)
class ctyvt : public cty {
    int oto;
public:
    int lay_oto() { return oto; }
    void nhap();
};
// Dinh nghia phuong thuc nhap cua lop cty
void cty::nhap() {
    cin.ignore();  // Bo ky tu '\n' du thua
    cout << "Ten cong ty: ";
    getline(cin, ten);
    cout << "Nam thanh lap: ";
    cin >> ntl;
}
// Dinh nghia phuong thuc nhap cua lop ctypm (cong ty phan mem)
void ctypm::nhap() {
    cty::nhap();
    cout << "So lap trinh vien: ";
    cin >> sltv;
}
// Dinh nghia phuong thuc nhap cua lop ctyvt (cong ty van tai)
void ctyvt::nhap() {
    cty::nhap();
    cout << "So o to: ";
    cin >> oto;
}

int main() {
    ctypm pm[50];
    ctyvt vt[50];
    int m, n, i;

    // Nhap danh sach cac cong ty phan mem
    cout << "\nNhap du lieu cac cong ty phan mem:\n";
    cout << "So cong ty PM: ";
    cin >> m;
    for (i = 0; i < m; ++i) {
        cout << "\nNhap thong tin cong ty PM thu " << i + 1 << ":\n";
        pm[i].nhap();
    }

    // In cac cong ty phan mem thanh lap sau nam 2000 va co tren 20 lap trinh vien
    cout << "\nCac cong ty PM thanh lap sau nam 2000 va co tren 20 lap trinh vien:\n";
    for (i = 0; i < m; ++i) {
        if (pm[i].lay_ntl() > 2000 && pm[i].lay_ltv() > 20) {
            cout << pm[i].lay_ten() << ", " << pm[i].lay_ntl() << ", " << pm[i].lay_ltv() << endl;
        }
    }
	// Nhap danh sach cac cong ty van tai
    cout << "\nNhap du lieu cac cong ty van tai:\n";
    cout << "So cong ty VT: ";
    cin >> n;
    for (i = 0; i < n; ++i) {
        cout << "\nNhap thong tin cong ty VT thu " << i + 1 << ":\n";
        vt[i].nhap();
    }

    // In cac cong ty van tai thanh lap truoc nam 2000 va co khong qua 10 o to
	cout << "\nCac cong ty VT thanh lap truoc nam 2000 va co khong qua 10 o to:\n";
    for (i = 0; i < n; ++i) {
        if (vt[i].lay_ntl() < 2000 && vt[i].lay_oto() <= 10) {
            cout << vt[i].lay_ten() << ", " << vt[i].lay_ntl() << ", " << vt[i].lay_oto() << endl;
        }
    }

    return 0;
}

