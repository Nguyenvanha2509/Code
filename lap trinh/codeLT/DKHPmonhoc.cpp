#include <iostream>
#include <string>
using namespace std;

class MonHoc {
private:
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
    int getTinChi() const { return tinChi; }
};

class DKHP {
private:
    string maSV;
    string tenSV;
    MonHoc* dsMonHoc;
    int soMonHoc;

public:
    DKHP(int soMon) : soMonHoc(soMon) {
        dsMonHoc = new MonHoc[soMon];
    }

    ~DKHP() {
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
            dsMonHoc[i].xuat();
        }
    }

    int tinhTongTinChi() const {
        int tongTinChi = 0;
        for (int i = 0; i < soMonHoc; i++) {
            tongTinChi += dsMonHoc[i].getTinChi();
        }
        return tongTinChi;
    }

    bool kiemTraDangKyMonHoc(const string& maMonHoc) const {
        for (int i = 0; i < soMonHoc; i++) {
            if (dsMonHoc[i].getMaMon() == maMonHoc) {
                return true;
            }
        }
        return false;
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

    DKHP* dsDKHP = new DKHP[n];
    for (int i = 0; i < n; i++) {
        int soMonHocSV;
        cout << "Nhap so mon hoc sinh vien thu " << i + 1 << " dang ky: ";
        cin >> soMonHocSV;

        dsDKHP[i] = DKHP(soMonHocSV);
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        dsDKHP[i].nhap();
    }

    cout << "\nThong tin cac sinh vien va tong tin chi da dang ky:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien " << dsDKHP[i].getMaSV() << " da dang ky " << dsDKHP[i].tinhTongTinChi() << " tin chi." << endl;
    }

    string maMon;
    cout << "\nNhap ma mon hoc can thong ke: ";
    cin >> maMon;

    int soSinhVienDangKy = 0;
    for (int i = 0; i < n; i++) {
        if (dsDKHP[i].kiemTraDangKyMonHoc(maMon)) {
            soSinhVienDangKy++;
        }
    }

    cout << "So sinh vien da dang ky mon hoc " << maMon << ": " << soSinhVienDangKy << endl;

    delete[] dsMonHoc;
    delete[] dsDKHP;

    return 0;
}


