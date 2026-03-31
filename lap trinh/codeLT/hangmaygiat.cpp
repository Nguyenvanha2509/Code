#include <iostream>
#include <string>
using namespace std;

// Khai bao lop Hang
class Hang {
private:
    string maHang;   // Ma hang
    string tenHang;  // Ten hang
    int soLuong;     // So luong
    double donGia;   // Don gia

public:
    // Ham tao kh?i t?o
    Hang() {
        maHang = "";
        tenHang = "";
        soLuong = 0;
        donGia = 0.0;
    }

    // Phuong thuc nhap thong tin hang
    void nhapHang() {
        cout << "Nhap ma hang: ";
        cin >> maHang;
        cout << "Nhap ten hang: ";
        cin.ignore(); // Xoa bo nho tam cua cin de nhap chuoi
        getline(cin, tenHang);
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap don gia: ";
        cin >> donGia;
    }

    // Phuong thuc xuat thong tin hang
    void xuatHang() {
        cout << "Ma hang: " << maHang << endl;
        cout << "Ten hang: " << tenHang << endl;
        cout << "So luong: " << soLuong << endl;
        cout << "Don gia: " << donGia << endl;
    }

    // Getter cho maHang, tenHang va donGia
    string getMaHang() {
        return maHang;
    }

    string getTenHang() {
        return tenHang;
    }

    double getDonGia() {
        return donGia;
    }
};

// Khai bao lop MayGiat ke thua tu Hang
class MayGiat : public Hang {
private:
    double soCan;  // So can (kg) cua may giat

public:
    // Ham tao kh?i t?o
    MayGiat() {
        soCan = 0.0;
    }

    // Phuong thuc nhap thong tin may giat
    void nhapMayGiat() {
        nhapHang();  // Goi phuong thuc nhap cua lop cha
        cout << "Nhap so can (kg) cua may giat: ";
        cin >> soCan;
    }

    // Phuong thuc xuat thong tin may giat
    void xuatMayGiat() {
        xuatHang();  // Goi phuong thuc xuat cua lop cha
        cout << "So can cua may giat: " << soCan << " kg" << endl;
    }

    // Getter cho soCan
    double getSoCan() {
        return soCan;
    }
};

int main() {
    int n;
    cout << "Nhap so luong may giat: ";
    cin >> n;  // Nhap so luong may giat

    MayGiat* dsMayGiat = new MayGiat[n];  // Cap phat bo nho cho n doi tuong MayGiat

    // Nhap thong tin cho n doi tuong may giat
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho may giat thu " << i + 1 << ":\n";
        dsMayGiat[i].nhapMayGiat();
    }

    // T?m ki?m thông tin máy gi?t theo m? hàng ho?c tên hàng
    string searchMaHang, searchTenHang;
    cout << "\nNhap ma hang hoac ten hang de tim kiem: ";
    cin.ignore();
    getline(cin, searchTenHang);  // Nh?p tên hàng

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (dsMayGiat[i].getMaHang() == searchTenHang || dsMayGiat[i].getTenHang() == searchTenHang) {
            dsMayGiat[i].xuatMayGiat();  // In thông tin c?a máy gi?t t?m ðý?c
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay may giat voi ma hang hoac ten hang: " << searchTenHang << endl;
    }

    // In danh sách máy gi?t có tr?ng lý?ng t? 9 kg tr? lên và giá ð?t nh?t
    double maxPrice = -1;
    cout << "\nDanh sach may giat tu 9kg tro len va co gia dat nhat:\n";
    for (int i = 0; i < n; i++) {
        if (dsMayGiat[i].getSoCan() >= 9) {
            if (dsMayGiat[i].getDonGia() > maxPrice) {
                maxPrice = dsMayGiat[i].getDonGia();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dsMayGiat[i].getSoCan() >= 9 && dsMayGiat[i].getDonGia() == maxPrice) {
            dsMayGiat[i].xuatMayGiat();  // In máy gi?t có giá ð?t nh?t
        }
    }

    delete[] dsMayGiat;  // Gi?i phóng b? nh?

    return 0;
}

