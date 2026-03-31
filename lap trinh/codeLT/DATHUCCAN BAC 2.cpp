#include <iostream>
#include <cmath> // Ð? s? d?ng hàm sqrt() tính cãn b?c hai
using namespace std;

class Dathuc {
private:
    int n;          // B?c c?a ða th?c
    float* hs;      // M?ng ch?a các h? s? c?a ða th?c

public:
    // Hàm t?o không ð?i
    Dathuc() : n(0), hs(nullptr) {}

    // Hàm t?o có tham s? b?c n
    Dathuc(int b) : n(b) {
        hs = new float[n + 1];  // T?o m?ng ch?a h? s? c?a ða th?c (có n+1 ph?n t?)
    }

    // Hàm h?y ð? gi?i phóng b? nh?
    ~Dathuc() {
        delete[] hs;
    }

    // Phýõng th?c nh?p ða th?c
    void nhap() {
        cout << "Nhap b?c cua da thuc: ";
        cin >> n;
        hs = new float[n + 1];  // T?o m?ng ch?a h? s? c?a ða th?c
        cout << "Nhap cac he so cua da thuc:\n";
        for (int i = 0; i <= n; ++i) {
            cout << "He so cua x^" << i << ": ";
            cin >> hs[i];
        }
    }

    // Phýõng th?c toán t? << ð? xu?t ða th?c
    friend ostream& operator<<(ostream& out, const Dathuc& dt) {
        out << "Da thuc: ";
        for (int i = 0; i <= dt.n; ++i) {
            if (dt.hs[i] != 0) {
                if (i > 0 && dt.hs[i] > 0) {
                    out << "+";
                }
                out << dt.hs[i];
                if (i > 0) out << "x^" << i;
            }
        }
        out << endl;
        return out;
    }

    // Phýõng th?c tính giá tr? c?a ða th?c t?i giá tr? x
    float giaTri(float x) const {
        float result = 0;
        for (int i = 0; i <= n; ++i) {
            result += hs[i] * pow(x, i);  // C?ng giá tr? h? s? * x^i
        }
        return result;
    }
};

int main() {
    Dathuc dt;
    dt.nhap();  // Nh?p ða th?c
    cout << dt;  // In ða th?c

    // Nh?p d1 và d2
    float d1, d2;
    cout << "Nhap d1: ";
    cin >> d1;
    cout << "Nhap d2: ";
    cin >> d2;

    // Tính giá tr? bi?u th?c S = ?(P(d1) + P(d2))
    float P_d1 = dt.giaTri(d1);
    float P_d2 = dt.giaTri(d2);
    float S = sqrt(P_d1 + P_d2);  // Tính cãn b?c hai c?a t?ng giá tr? ða th?c t?i d1 và d2

    // In k?t qu?
    cout << "Gia tri P(d1) = " << P_d1 << endl;
    cout << "Gia tri P(d2) = " << P_d2 << endl;
    cout << "S = ?(P(d1) + P(d2)) = " << S << endl;

    return 0;
}

