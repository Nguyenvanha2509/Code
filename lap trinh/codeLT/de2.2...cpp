#include <iostream>
#include <string>
using namespace std;

class QLH {
    string maHang;     // Ma hang
    string tenHang;    // Ten hang
    string xuatXu;     // Xuat xu
    int loaiHang;      // Loai hang (1, 2, 3)
    int soLuong;       // So luong

public:
    void nhap();       // Ham nhap thong tin hang hoa
    void xuat() const; // Ham xuat thong tin hang hoa
    int getLoaiHang() const { return loaiHang; } // Lay loai hang
    int getSoLuong() const { return soLuong; }   // Lay so luong
    string getTenHang() const { return tenHang; } // Lay ten hang
};

void QLH::nhap() {
    cout << "Nhap ma hang: ";
    cin >> maHang;
    cout << "Nhap ten hang: ";
    cin.ignore();
    getline(cin, tenHang);
    cout << "Nhap xuat xu: ";
    getline(cin, xuatXu);
    cout << "Nhap loai hang (1, 2, 3): ";
    cin >> loaiHang;
    cout << "Nhap so luong: ";
    cin >> soLuong;
}

void QLH::xuat() const {
    cout << "Ma hang: " << maHang << endl;
    cout << "Ten hang: " << tenHang << endl;
    cout << "Xuat xu: " << xuatXu << endl;
    cout << "Loai hang: " << loaiHang << endl;
    cout << "So luong: " << soLuong << endl;
}

class DIENTU : public QLH {
private:
    int tgbh; // Thoi gian bao hanh (thang)

public:
    void nhap();       // Ham nhap thong tin dien tu
    void xuat() const; // Ham xuat thong tin dien tu
    int getTGBH() const { return tgbh; } // Lay thoi gian bao hanh
};

void DIENTU::nhap() {
    QLH::nhap();
    cout << "Nhap thoi gian bao hanh (thang): ";
    cin >> tgbh;
}

void DIENTU::xuat() const {
    QLH::xuat();
    cout << "Thoi gian bao hanh: " << tgbh << " thang" << endl;
}

int main() {
    int n;
    cout << "Nhap so luong mat hang dien tu: ";
    cin >> n;

    DIENTU *hangDienTu = new DIENTU[n];
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin cho mat hang dien tu thu " << i + 1 << ":\n";
        hangDienTu[i].nhap();
    }

    cout << "\nDanh sach mat hang dien tu:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nThong tin mat hang thu " << i + 1 << ":\n";
        hangDienTu[i].xuat();
    }

    // Thong ke tong so luong hang cua tung loai co thoi gian bao hanh >= 12 thang
    int tongLoai1 = 0, tongLoai2 = 0, tongLoai3 = 0;
    for (int i = 0; i < n; i++) {
        if (hangDienTu[i].getTGBH() >= 12) {
            if (hangDienTu[i].getLoaiHang() == 1) {
                tongLoai1 += hangDienTu[i].getSoLuong();
            } else if (hangDienTu[i].getLoaiHang() == 2) {
                tongLoai2 += hangDienTu[i].getSoLuong();
            } else if (hangDienTu[i].getLoaiHang() == 3) {
                tongLoai3 += hangDienTu[i].getSoLuong();
            }
        }
    }

    cout << "\nTong so luong hang dien tu co thoi gian bao hanh >= 12 thang:\n";
    cout << "Loai 1: " << tongLoai1 << endl;
    cout << "Loai 2: " << tongLoai2 << endl;
    cout << "Loai 3: " << tongLoai3 << endl;

    // Tim kiem mat hang theo ten cho truoc
    string tenTimKiem;
    cout << "\nNhap ten mat hang can tim: ";
    cin.ignore();
    getline(cin, tenTimKiem);
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (hangDienTu[i].getTenHang() == tenTimKiem) {
            cout << "\nMat hang tim thay:\n";
            hangDienTu[i].xuat();
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay mat hang co ten \"" << tenTimKiem << "\" trong danh sach.\n";
    }

    delete[] hangDienTu;
    return 0;
}


