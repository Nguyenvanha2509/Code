#include <iostream>
#include <cmath>
using namespace std;

class Toado {
protected:
    float x, y; // Hoanh do va tung do

public:
    void nhap();          // Ham nhap toa do
    void xuat();          // Ham xuat toa do
    float kcGoc();        // Khoang cach tu diem hien tai den goc toa do
};

void Toado::nhap() {
    cout << "Nhap hoanh do va tung do: ";
    cin >> x >> y;
}

void Toado::xuat() {
    cout << "(" << x << "," << y << ")";
}

float Toado::kcGoc() {
    return sqrt(x * x + y * y);
}

class DiemMau : public Toado {
    int mau; // 1: Do, 2: Vang, 3: Xanh

public:
    void nhap();          // Ham nhap toa do va mau sac
    void xuat();          // Ham xuat toa do va mau sac
    int getMau();         // Lay ma mau
};

void DiemMau::nhap() {
    Toado::nhap(); // Goi ham nhap cua lop co so Toado
    do {
        cout << "Nhap ma mau (1: Do, 2: Vang, 3: Xanh): ";
        cin >> mau;
    } while (mau < 1 || mau > 3); // Kiem tra ma mau hop le
}

void DiemMau::xuat() {
    Toado::xuat();
    cout << " - Mau: ";
    switch (mau) {
        case 1: cout << "Do"; break;
        case 2: cout << "Vang"; break;
        case 3: cout << "Xanh"; break;
    }
    cout << endl;
}

int DiemMau::getMau() {
    return mau;
}

int main() {
    int n;
    cout << "Nhap so luong diem: ";
    cin >> n;

    DiemMau dsDiem[100]; // Mang chua n diem mau, toi da 100 diem

    // Nhap thong tin cho n diem mau
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin diem thu " << i + 1 << ":\n";
        dsDiem[i].nhap();
    }

    // Xuat thong tin cac diem mau
    cout << "\nDanh sach cac diem vua nhap:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Diem thu " << i + 1 << ": ";
        dsDiem[i].xuat();
    }

    // Thong ke so diem theo mau
    int countDo = 0, countVang = 0, countXanh = 0;
    for (int i = 0; i < n; ++i) {
        switch (dsDiem[i].getMau()) {
            case 1: countDo++; break;
            case 2: countVang++; break;
            case 3: countXanh++; break;
        }
    }

    // Hien thi ket qua thong ke
    cout << "\nThong ke so diem theo mau:\n";
    cout << "So diem mau Do: " << countDo << endl;
    cout << "So diem mau Vang: " << countVang << endl;
    cout << "So diem mau Xanh: " << countXanh << endl;

    // Tim cac diem co khoang cach lon nhat den goc toa do
    float maxKc = 0;
    for (int i = 0; i < n; ++i) {
        float kc = dsDiem[i].kcGoc();
        if (kc > maxKc) {
            maxKc = kc;
        }
    }

    // In ra cac diem co khoang cach lon nhat den goc toa do
    cout << "\nCac diem co khoang cach lon nhat den goc toa do (" << maxKc << "):\n";
    for (int i = 0; i < n; ++i) {
        if (dsDiem[i].kcGoc() == maxKc) {
            dsDiem[i].xuat();
        }
    }

    return 0;
}


