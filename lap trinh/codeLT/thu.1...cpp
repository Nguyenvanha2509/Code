#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class diem {
    float x, y; // Hoanh do va tung do

public:
    void nhap();           // Ham nhap toa do
    void xuat();           // Ham xuat toa do
    float kc(diem d);      // Khoang cach tu diem hien tai den diem d
    float kcGoc();         // Khoang cach tu diem hien tai den goc toa do
};

void diem::nhap() {
    cin >> x >> y;
}

void diem::xuat() {
    cout << "(" << x << "," << y << ")";
}

float diem::kc(diem d) {
    return sqrt((x - d.x) * (x - d.x) + (y - d.y) * (y - d.y));
}

float diem::kcGoc() {
    return sqrt(x * x + y * y);
}

int main() {
    diem d1, d2, d3;
    float a, b, c;

    // Nhap toa do cho 3 diem
    cout << "\nNhap diem 1: ";
    d1.nhap();
    d1.xuat(); 
    cout << "\nNhap diem 2: ";
    d2.nhap();
    d2.xuat(); 
    cout << "\nNhap diem 3: ";
    d3.nhap();
    d3.xuat(); 

    // Tinh khoang cach giua cac diem
    a = d1.kc(d2);
    b = d2.kc(d3);
    c = d3.kc(d1);

    cout << "Khoang cach giua d1 va d2: " << a << endl;
    cout << "Khoang cach giua d2 va d3: " << b << endl;
    cout << "Khoang cach giua d3 va d1: " << c << endl;

    // Tinh tong khoang cach tu cac diem den goc toa do
    float tongKhoangCach = d1.kcGoc() + d2.kcGoc() + d3.kcGoc();
    cout << "\nTong khoang cach tu cac diem den goc toa do = " << tongKhoangCach << endl;

    // Tim diem gan goc toa do nhat
    diem diemGanGoc = d1;
    float minKhoangCach = d1.kcGoc();

    if (d2.kcGoc() < minKhoangCach) {
        minKhoangCach = d2.kcGoc();
        diemGanGoc = d2;
    }
    if (d3.kcGoc() < minKhoangCach) {
        minKhoangCach = d3.kcGoc();
        diemGanGoc = d3;
    }

    cout << "\nDiem gan goc toa do nhat: ";
    diemGanGoc.xuat();
    cout << " voi khoang cach = " << minKhoangCach << endl;

    return 0;
}

