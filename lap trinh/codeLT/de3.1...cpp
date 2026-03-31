#include <iostream>
using namespace std;

class HinhChuNhat {
private:
    float chieuDai; // Chieu dai cua hinh chu nhat
    float chieuRong; // Chieu rong cua hinh chu nhat

public:
    void nhap();        // Ham nhap kich thuoc hinh chu nhat
    void xuat() const;  // Ham xuat thong tin hinh chu nhat
    float dienTich() const; // Ham tinh dien tich hinh chu nhat
};

void HinhChuNhat::nhap() {
    cout << "Nhap chieu dai: ";
    cin >> chieuDai;
    cout << "Nhap chieu rong: ";
    cin >> chieuRong;
}

void HinhChuNhat::xuat() const {
    cout << "Hinh chu nhat - Chieu dai: " << chieuDai << ", Chieu rong: " << chieuRong << endl;
}

float HinhChuNhat::dienTich() const {
    return chieuDai * chieuRong;
}

int main() {
    int n;
    cout << "Nhap so luong hinh chu nhat: ";
    cin >> n;

    HinhChuNhat* dsHinhChuNhat = new HinhChuNhat[n];
    
    // Nhap thong tin cho n hinh chu nhat
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin cho hinh chu nhat thu " << i + 1 << ":\n";
        dsHinhChuNhat[i].nhap();
    }

    // Xuat thong tin va dien tich cua n hinh chu nhat
    cout << "\nDanh sach cac hinh chu nhat:\n";
    float tongDienTich = 0;
    for (int i = 0; i < n; i++) {
        dsHinhChuNhat[i].xuat();
        float dt = dsHinhChuNhat[i].dienTich();
        cout << "Dien tich: " << dt << endl;
        tongDienTich += dt; // Tinh tong dien tich
    }

    // Tinh va xuat dien tich trung binh
    float dienTichTrungBinh = tongDienTich / n;
    cout << "\nDien tich trung binh cua cac hinh chu nhat: " << dienTichTrungBinh << endl;

    // Tim dien tich nho nhat
    float dienTichNhoNhat = dsHinhChuNhat[0].dienTich();
    for (int i = 1; i < n; i++) {
        float dt = dsHinhChuNhat[i].dienTich();
        if (dt < dienTichNhoNhat) {
            dienTichNhoNhat = dt;
        }
    }

    // Xuat cac hinh chu nhat co dien tich nho nhat
    cout << "\nCac hinh chu nhat co dien tich nho nhat (" << dienTichNhoNhat << "):\n";
    for (int i = 0; i < n; i++) {
        if (dsHinhChuNhat[i].dienTich() == dienTichNhoNhat) {
            dsHinhChuNhat[i].xuat();
        }
    }

    delete[] dsHinhChuNhat; // Giai phong bo nho cap phat dong
    return 0;
}

