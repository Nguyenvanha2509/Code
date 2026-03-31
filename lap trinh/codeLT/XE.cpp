#include <iostream>
#include <string>
using namespace std;

class Xe {
protected:
    string bienSo;    // Bien so xe
    float trongLuong; // Trong luong cua xe

public:
    // Ham nhap thong tin cho xe
    virtual void nhap() {
        cout << "Nhap bien so: ";
        cin >> bienSo;
        cout << "Nhap trong luong: ";
        cin >> trongLuong;
    }

    // Ham xuat thong tin cho xe
    virtual void xuat() const {
        cout << "Bien so: " << bienSo << endl;
        cout << "Trong luong: " << trongLuong << " kg" << endl;
    }

    // Ham tra ve trong luong
    float getTrongLuong() const {
        return trongLuong;
    }

    // Ham tra ve bien so
    string getBienSo() const {
        return bienSo;
    }
};

class XeBus : public Xe {
private:
    int soChoNgoi; // So cho ngoi cua xe buyt

public:
    // Ham nhap thong tin cho xe bus
    void nhap() override {
        Xe::nhap();
        cout << "Nhap so cho ngoi: ";
        cin >> soChoNgoi;
    }

    // Ham xuat thong tin cho xe bus
    void xuat() const override {
        Xe::xuat();
        cout << "So cho ngoi: " << soChoNgoi << endl;
    }
};

class XeTai : public Xe {
private:
    float taiTrong; // Tai trong cua xe tai (ton)

public:
    // Ham nhap thong tin cho xe tai
    void nhap() override {
        Xe::nhap();
        cout << "Nhap tai trong (ton): ";
        cin >> taiTrong;
    }

    // Ham xuat thong tin cho xe tai
    void xuat() const override {
        Xe::xuat();
        cout << "Tai trong: " << taiTrong << " ton" << endl;
    }

    // Ham tra ve tai trong cua xe tai
    float getTaiTrong() const {
        return taiTrong;
    }
};

int main() {
    int n, m;
    string bienSoCanTim;

    // Nhap so xe buyt va xe tai
    cout << "Nhap so xe buyt: ";
    cin >> n;
    XeBus *danhSachXeBus = new XeBus[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho xe buyt thu " << i + 1 << ":" << endl;
        danhSachXeBus[i].nhap();
    }

    cout << "Nhap so xe tai: ";
    cin >> m;
    XeTai *danhSachXeTai = new XeTai[m];
    for (int i = 0; i < m; i++) {
        cout << "Nhap thong tin cho xe tai thu " << i + 1 << ":" << endl;
        danhSachXeTai[i].nhap();
    }

    // Nhap bien so xe can tim
    cout << "\nNhap bien so xe can tim: ";
    cin >> bienSoCanTim;

    bool timThay = false;

    // Tim kiem trong danh sach xe buyt
    for (int i = 0; i < n; i++) {
        if (danhSachXeBus[i].getBienSo() == bienSoCanTim) {
            cout << "\nThong tin xe buyt co bien so " << bienSoCanTim << ":" << endl;
            danhSachXeBus[i].xuat();
            timThay = true;
            break;
        }
    }

    // Tim kiem trong danh sach xe tai
    for (int i = 0; i < m; i++) {
        if (danhSachXeTai[i].getBienSo() == bienSoCanTim) {
            cout << "\nThong tin xe tai co bien so " << bienSoCanTim << ":" << endl;
            danhSachXeTai[i].xuat();
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay xe co bien so \"" << bienSoCanTim << "\" trong danh sach." << endl;
    }

    delete[] danhSachXeBus; // Giai phong bo nho
    delete[] danhSachXeTai; // Giai phong bo nho
    return 0;
}

