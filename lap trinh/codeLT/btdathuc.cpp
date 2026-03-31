#include <iostream>
#include <cmath>  // Thý vi?n ð? tính toán v?i s? th?c
using namespace std;

// Khai bao lop DaThuc
class DaThuc {
private:
    int bac;              // Bac cua da thuc
    double heSo[100];     // Mang he so cua da thuc (gioi han 100 he so)

public:
    // Ham tao khoi tao
    DaThuc(int b) {
        bac = b; // Gan bac da thuc
        for (int i = 0; i <= bac; i++) {
            heSo[i] = 0; // Khoi tao cac he so ban dau = 0
        }
    }

    // Phuong thuc nhap da thuc
    void nhapDaThuc() {
        cout << "Nhap he so cua da thuc (tu he so a0 den an):\n";
        for (int i = 0; i <= bac; i++) {
            cout << "a" << i << " = ";
            cin >> heSo[i]; // Nhap he so cua da thuc
        }
    }

    // Phuong thuc xuat da thuc
    void xuatDaThuc() {
        cout << "He so da thuc: ";
        for (int i = 0; i <= bac; i++) {
            cout << heSo[i];
            if (i != bac) cout << ", ";
        }
        cout << endl;
    }

    // Phuong thuc tinh gia tri da thuc tai diem x
    double tinhGiaTri(double x) {
        double ketQua = 0;
        for (int i = 0; i <= bac; i++) {
            ketQua += heSo[i] * pow(x, i); // Tinh tong gia tri da thuc tai x
        }
        return ketQua;
    }

    // Phuong thuc tinh dao ham da thuc tai diem x
    double tinhDaoHam(double x) {
        double ketQua = 0;
        for (int i = 1; i <= bac; i++) {
            ketQua += i * heSo[i] * pow(x, i - 1); // Tinh dao ham da thuc tai x
        }
        return ketQua;
    }
};

int main() {
    int bac;
    cout << "Nhap bac cua da thuc: ";
    cin >> bac; // Nhap bac cua da thuc

    // Tao doi tuong DaThuc voi bac nhap vao
    DaThuc daThuc(bac);

    // Nhap he so cua da thuc
    daThuc.nhapDaThuc();

    // Xuat he so da thuc
    daThuc.xuatDaThuc();

    // Nhap gia tri x
    double x;
    cout << "Nhap gia tri x: ";
    cin >> x;

    // Tinh va xuat gia tri da thuc tai x
    double ketQua = daThuc.tinhGiaTri(x);
    cout << "Gia tri da thuc tai x = " << x << " la: " << ketQua << endl;

    // Tinh va xuat dao ham da thuc tai x
    double daoHam = daThuc.tinhDaoHam(x);
    cout << "Gia tri dao ham da thuc tai x = " << x << " la: " << daoHam << endl;

    return 0;
}

