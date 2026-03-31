#include <iostream>
#include <string>
using namespace std;

// Lop MatHang
class MatHang {
private:
    string maHang;    // Ma hang
    double donGia;    // Don gia

public:
    // Ham tao mac dinh
    MatHang() : maHang(""), donGia(0.0) {}

    // Ham nhap thong tin mat hang
    void nhap() {
        cout << "Nhap ma hang: ";
        cin >> maHang;
        cout << "Nhap don gia: ";
        cin >> donGia;
    }

    // Ham xuat thong tin mat hang
    void xuat() const {
        cout << "Ma hang: " << maHang << ", Don gia: " << donGia << " VND\n";
    }

    // Ham lay ma hang
    string getMaHang() const {
        return maHang;
    }

    // Ham lay don gia
    double getDonGia() const {
        return donGia;
    }
};

// Lop HoaDon
class HoaDon {
private:
    string maHang;    // Ma hang
    int soLuong;      // So luong
    string ngayBan;   // Ngay ban

public:
    // Ham tao mac dinh
    HoaDon() : maHang(""), soLuong(0), ngayBan("") {}

    // Ham nhap thong tin hoa don
    void nhap() {
        cout << "Nhap ma hang: ";
        cin >> maHang;
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap ngay ban (dd/mm/yyyy): ";
        cin >> ngayBan;
    }

    // Ham xuat thong tin hoa don
    void xuat() const {
        cout << "Ma hang: " << maHang << ", So luong: " << soLuong << ", Ngay ban: " << ngayBan << "\n";
    }

    // Ham tinh tong tien cua hoa don
    double tinhTien(const MatHang matHang) const {
        if (matHang.getMaHang() == maHang) {
            return matHang.getDonGia() * soLuong;
        }
        return 0.0;
    }

    // Ham kiem tra so luong lon hon 10
    bool soLuongLonHon10() const {
        return soLuong > 10;
    }

    // Ham lay ma hang
    string getMaHang() const {
        return maHang;
    }

    // Ham lay ngay ban
    string getNgayBan() const {
        return ngayBan;
    }
};

// Ham tinh so tien ban duoc trong mot ngay cho truoc
double tinhTienTrongNgay(HoaDon hoaDon[], int n, MatHang matHang[], int m, string ngay) {
    double tongTien = 0;
    for (int i = 0; i < n; ++i) {
        if (hoaDon[i].getNgayBan() == ngay) {
            for (int j = 0; j < m; ++j) {
                if (hoaDon[i].getMaHang() == matHang[j].getMaHang()) {
                    tongTien += hoaDon[i].tinhTien(matHang[j]);
                    break;
                }
            }
        }
    }
    return tongTien;
}

// Ham main
int main() {
    int m, n;

    // Nhap so luong mat hang
    cout << "Nhap so luong mat hang: ";
    cin >> m;

    MatHang danhSachMatHang[m];  // Mang danh sach m mat hang

    // Nhap thong tin cho cac mat hang
    for (int i = 0; i < m; ++i) {
        cout << "\nNhap thong tin cho mat hang thu " << i + 1 << ":\n";
        danhSachMatHang[i].nhap();
    }

    // Xuat thong tin cac mat hang
    cout << "\nDanh sach mat hang:\n";
    for (int i = 0; i < m; ++i) {
        danhSachMatHang[i].xuat();
    }

    // Nhap so luong hoa don
    cout << "\nNhap so luong hoa don: ";
    cin >> n;

    HoaDon danhSachHoaDon[n];  // Mang danh sach n hoa don

    // Nhap thong tin cho cac hoa don
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin cho hoa don thu " << i + 1 << ":\n";
        danhSachHoaDon[i].nhap();
    }

    // Xuat thong tin cac hoa don va tinh tien
    cout << "\nDanh sach hoa don:\n";
    double tongTien = 0;
    int demSoLuongLonHon10 = 0;  // Bien dem so hoa don co so luong > 10

    for (int i = 0; i < n; ++i) {
        danhSachHoaDon[i].xuat();
        double tienHoaDon = 0;
        for (int j = 0; j < m; ++j) {
            if (danhSachHoaDon[i].getMaHang() == danhSachMatHang[j].getMaHang()) {
                tienHoaDon = danhSachHoaDon[i].tinhTien(danhSachMatHang[j]);
                break;
            }
        }
        cout << "Tong tien hoa don: " << tienHoaDon << " VND\n";
        tongTien += tienHoaDon;

        // Kiem tra neu so luong > 10
        if (danhSachHoaDon[i].soLuongLonHon10()) {
            demSoLuongLonHon10++;
        }
    }

    cout << "\nTong tien cua tat ca hoa don: " << tongTien << " VND\n";
    cout << "So hoa don co so luong > 10: " << demSoLuongLonHon10 << endl;

    // Tinh so tien ban duoc trong mot ngay cho truoc
    string ngay;
    cout << "\nNhap ngay muon tinh tien (dd/mm/yyyy): ";
    cin >> ngay;

    double tongTienTrongNgay = tinhTienTrongNgay(danhSachHoaDon, n, danhSachMatHang, m, ngay);
    cout << "Tong tien ban duoc trong ngay " << ngay << " la: " << tongTienTrongNgay << " VND\n";

    return 0;
}

