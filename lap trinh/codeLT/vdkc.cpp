#include <iostream>
#include <cmath>
using namespace std;

class Diem {
private:
    float x, y; // Hoanh do va tung do cua diem

public:
    // 1. Ham tao khong doi
    Diem() : x(0), y(0) {}

    // 2. Ham tao co 2 doi so (hoanh do, tung do)
    Diem(float x, float y) : x(x), y(y) {}

    // 3. Ham tao sao chep (Copy Constructor)
    Diem(const Diem &d) : x(d.x), y(d.y) {}

    // 4. Ham tinh khoang cach giua hai diem
    float khoangCach(const Diem &d) const {
        return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
    }

    // 5. Toan tu == de xac dinh hai diem co trung nhau khong
    bool operator==(const Diem &d) const {
        return (x == d.x && y == d.y);
    }

    // 6. Toan tu * de "nhan" hai diem
    Diem operator*(const Diem &d) const {
        return Diem(x * d.x, y * d.y);
    }

    // 7. Dinh nghia toan tu >> de nhap mot diem
    friend istream& operator>>(istream &in, Diem &d) {
        cout << "Nhap hoanh do: ";
        in >> d.x;
        cout << "Nhap tung do: ";
        in >> d.y;
        return in;
    }

    // Dinh nghia toan tu << de xuat mot diem
    friend ostream& operator<<(ostream &out, const Diem &d) {
        out << "(" << d.x << ", " << d.y << ")";
        return out;
    }
};

int main() {
    // Su dung ham tao khong doi
    Diem d1;
    cout << "Diem 1 (mac dinh): " << d1 << endl;

    // Su dung ham tao voi 2 doi so
    Diem d2(3, 4);
    cout << "Diem 2: " << d2 << endl;

    // Su dung ham tao sao chep
    Diem d3 = d2;
    cout << "Diem 3 (sao chep tu Diem 2): " << d3 << endl;

    // Tinh khoang cach giua d1 va d2
    cout << "Khoang cach giua Diem 1 va Diem 2: " << d1.khoangCach(d2) << endl;

    // Kiem tra hai diem co trung nhau khong
    if (d2 == d3) {
        cout << "Diem 2 va Diem 3 trung nhau!" << endl;
    } else {
        cout << "Diem 2 va Diem 3 khong trung nhau!" << endl;
    }

    // Nhan hai diem voi toan tu *
    Diem d4 = d2 * d3;
    cout << "Diem 2 * Diem 3 = " << d4 << endl;

    // Nhap diem tu nguoi dung
    Diem d5;
    cout << "Nhap diem 5: " << endl;
    cin >> d5;
    cout << "Diem 5: " << d5 << endl;

    return 0;
}

