#include <iostream>
using namespace std;

class SP {
    float pt, pa;

public:
    // Hàm tao
    SP(float pt = 0, float pa = 0) : pt(pt), pa(pa) {}

    // Hàm nhap
    void nhap() {
        cout << "\nNhap phan thuc va phan ao: ";
        cin >> pt >> pa;
    }

    // Phep toan !: Tính tong binh phuong cua phan thuc và phan ao
    float operator!() {
        return pt * pt + pa * pa;
    }

    // Phep toan << de in du lieu ra man hinh
    friend ostream &operator<<(ostream &out, const SP &sp) {
        out << "z = " << sp.pt << (sp.pa >= 0 ? "+" : "") << sp.pa << "i";
        return out;
    }
};

int main() {
    SP s1, s2;
    cout << "Nhap so phuc 1:";
    s1.nhap();
    cout << "Nhap so phuc 2:";
    s2.nhap();

    // Tinh tong !s1 và !s2
    float s = !s1 + !s2;

    // In ket qua 
    cout << s1 << endl;
    cout << s2 << endl;
    cout << "Tong binh phuong (!s1 + !s2) = " << s << endl;

    return 0;
}

