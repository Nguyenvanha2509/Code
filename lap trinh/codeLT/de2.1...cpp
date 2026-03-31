#include <iostream>
#include <cmath>
using namespace std;

class DaThuc {
private:
    int bac;            // Bac cua da thuc
    float heso[100];    // Mang he so, toi da bac la 99

public:
    void nhap();                 // Ham nhap da thuc
    void xuat(); 
    float tinhGiaTri(float x);   // Tinh gia tri da thuc tai x
    float daoHam(float x);       // Tinh gia tri dao ham cua da thuc tai gia tri x
};

void DaThuc::nhap() {
    cout << "Nhap bac cua da thuc: ";
    cin >> bac;
    cout << "Nhap cac he so cua da thuc (tu bac cao den bac 0):\n";
    for (int i = bac; i >= 0; --i) {
        cout << "He so bac " << i << ": ";
        cin >> heso[i];
    }
}
void DaThuc::xuat() {
    cout << "Da thuc: ";
    for (int i = bac; i >= 0; --i) {
        if (heso[i] != 0) {  // Bo qua cac he so bang 0
            if (i != bac && heso[i] > 0) 
                cout << " + "; // Dau cong neu he so duong (không phai he so ðau)
            else if (heso[i] < 0) 
                cout << " - "; // Dau tru neu he so âm
            cout << fabs(heso[i]); // Gia tri tuyet doi cua he so 

            if (i > 0) 
                cout << "x";
            if (i > 1) 
                cout << "^" << i; // M?a cua x
        }
    }
    cout << endl;
}

float DaThuc::tinhGiaTri(float x) {
    float result = 0;
    for (int i = bac; i >= 0; --i) {
        result += heso[i] * pow(x, i);
    }
    return result;
}

float DaThuc::daoHam(float x) {
    float result = 0;
    for (int i = bac; i > 0; --i) {
        result += i * heso[i] * pow(x, i - 1); // Tinh dao ham
    }
    return result;
}

int main() {
    DaThuc dt;
    dt.nhap();
    
    cout<<"\n";
	dt.xuat(); 

    float x;
    cout << "\nNhap gia tri x de tinh da thuc va dao ham tai x: ";
    cin >> x;

    cout << "Gia tri da thuc tai x = " << x << " la: " << dt.tinhGiaTri(x) << endl;
    cout << "Gia tri dao ham cua da thuc tai x = " << x << " la: " << dt.daoHam(x) << endl;

    return 0;
}


