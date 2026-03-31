#include <iostream>
#include <string>
using namespace std;

// Lop MatHang
class MatHang {
protected:
    string maHang;           // Ma hang
    string tenHang;          // Ten hang
    string hangSanXuat;      // Hang san xuat
    int thoiGianBaoHanh;     // Thoi gian bao hanh (thang)
    double donGia;           // Don gia

public:
    // Ham tao
    MatHang() : maHang(""), tenHang(""), hangSanXuat(""), thoiGianBaoHanh(0), donGia(0.0) {}

    // Ham nhap thong tin
    void nhap() {
        cout << "Nhap ma hang: ";
        cin >> maHang;
        cin.ignore();
        cout << "Nhap ten hang: ";
        getline(cin, tenHang);
        cout << "Nhap hang san xuat: ";
        getline(cin, hangSanXuat);
        cout << "Nhap thoi gian bao hanh (thang): ";
        cin >> thoiGianBaoHanh;
        cout << "Nhap don gia: ";
        cin >> donGia;
    }

    // Ham xuat thong tin
    void xuat() const {
        cout << "Ma hang: " << maHang << "\n";
        cout << "Ten hang: " << tenHang << "\n";
        cout << "Hang san xuat: " << hangSanXuat << "\n";
        cout << "Thoi gian bao hanh: " << thoiGianBaoHanh << " thang\n";
        cout << "Don gia: " << donGia << " VND\n";
    }

    double getDonGia() const {
        return donGia;
    }
};

// Lop DienThoai (ke thua tu MatHang)
class DienThoai : public MatHang {
private:
    string heDieuHanh; // He dieu hanh

public:
    // Ham nhap thong tin
    void nhap() {
        MatHang::nhap(); // Goi ham nhap cua lop cha
        cin.ignore();
        cout << "Nhap he dieu hanh: ";
        getline(cin, heDieuHanh);
    }

    // Ham xuat thong tin
    void xuat() const {
        MatHang::xuat(); // Goi ham xuat cua lop cha
        cout << "He dieu hanh: " << heDieuHanh << "\n";
    }
};

int main() {
    int n;

    cout << "Nhap so luong dien thoai: ";
    cin >> n;

    // Khai bao mang cac doi tuong DienThoai
    DienThoai danhSach[100]; // Gioi han toi da 100 dien thoai

    // Nhap thong tin cho tung dien thoai
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin cho dien thoai thu " << i + 1 << ":\n";
        danhSach[i].nhap();
    }

    // Xuat thong tin danh sach dien thoai
    cout << "\nDanh sach cac dien thoai:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nThong tin dien thoai thu " << i + 1 << ":\n";
        danhSach[i].xuat();
    }

    // Tim kiem dien thoai co gia trong doan [a, b]
    double a, b;
    do {
        cout << "\nNhap khoang gia a, b (a > 0, b > 0, a < b):\n";
        cout << "Nhap a: ";
        cin >> a;
        cout << "Nhap b: ";
        cin >> b;

        if (a <= 0 || b <= 0 || a >= b) {
            cout << "Gia tri khong hop le. Moi nhap lai.\n";
        }
    } while (a <= 0 || b <= 0 || a >= b);

    cout << "\nDanh sach dien thoai co gia trong khoang [" << a << ", " << b << "]:\n";
    bool timThay = false;
    for (int i = 0; i < n; ++i) {
        if (danhSach[i].getDonGia() >= a && danhSach[i].getDonGia() <= b) {
            danhSach[i].xuat();
            cout << "----------------------\n";
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong co dien thoai nao co gia trong khoang [" << a << ", " << b << "].\n";
    }

    // Tim cac dien thoai re nhat
    cout << "\nDanh sach cac dien thoai re nhat:\n";
    double giaReNhat = danhSach[0].getDonGia();
    for (int i = 1; i < n; ++i) {
        if (danhSach[i].getDonGia() < giaReNhat) {
            giaReNhat = danhSach[i].getDonGia();
        }
    }

    bool coReNhat = false;
    for (int i = 0; i < n; ++i) {
        if (danhSach[i].getDonGia() == giaReNhat) {
            danhSach[i].xuat();
            cout << "----------------------\n";
            coReNhat = true;
        }
    }

    if (!coReNhat) {
        cout << "Khong co dien thoai nao trong danh sach re nhat.\n";
    }

    return 0;
}

