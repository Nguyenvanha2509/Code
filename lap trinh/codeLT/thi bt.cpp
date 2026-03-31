#include <iostream>
using namespace std;

class SP {
private:
    float phanThuc; 
    float phanAo; 

public:
    // Ham tao de khoi tao so phuc
    SP(float thuc = 0, float ao = 0) : phanThuc(thuc), phanAo(ao) {}

    // Ham nhap so phuc
    void nhap() {
        cout << "\nNhap phan thuc: ";
        cin >> phanThuc;
        cout << "Nhap phan ao: ";
        cin >> phanAo;
    }

    // Ham xuat so phuc
    void xuat() const {
        if (phanAo >= 0)
            cout << phanThuc << " + " << phanAo << "i"; // Xuat so phuc dang a + bi
        else
            cout << phanThuc << " - " << -phanAo << "i"; // Xuat so phuc dang a - bi
    }

    // Phep toan ! de tinh tong binh phuong cua phan thuc va phan ao
    float operator!() const {
        return phanThuc * phanThuc + phanAo * phanAo; // Tinh binh phuong cua phan thuc va phan ao
    }
};

int main() {
    SP s1, s2;

    // Nhap hai so phuc
    cout << "\nNhap so phuc s1:" << endl;
    s1.nhap();
    cout << "\nNhap so phuc s2:" << endl;
    s2.nhap(); 

    // Xuat hai so phuc
    cout << "\nSo phuc s1: ";
    s1.xuat();
    cout << endl;

    cout << "\nSo phuc s2: ";
    s2.xuat(); 
    cout << endl;

    float sum = !s1 + !s2; // Tinh tong !s1 + !s2

    cout << "Tong binh phuong cua phan thuc va phan ao cua s1 va s2: " << sum << endl;

    return 0;
}

