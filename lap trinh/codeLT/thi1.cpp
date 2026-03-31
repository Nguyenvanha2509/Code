#include <iostream>
#include <cmath>
using namespace std;

class Ds_nguyen {
private:
    int n;     
    int* x;

public:
     Ds_nguyen(int n) {
        this->n = n;
        x = new int[n];
    }
    ~Ds_nguyen() {
        delete[] x;
    }
    void nhapDay() {
        cout << "Nhap " << n << " phan tu cua day so nguyen: ";
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
    }
    void xuatDay() {
        cout << "Day so nguyen da nhap: ";
        for (int i = 0; i < n; i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }
    int lascp(int num) {
        if (num < 0) return 0;
        int sqrtNum = sqrt(num);
        return (sqrtNum * sqrtNum == num) ? 1 : 0;
    }
    int demscp() {
        int dem = 0;
        for (int i = 0; i < n; i++) {
            dem += lascp(x[i]);  
        }
        return dem;
    }
    float tbcduong() {
        int tong = 0;
        int dem = 0;
        for (int i = 0; i < n; i++) {
            if (x[i] > 0) {    
                tong += x[i];
                dem++;
            }
        }
        if (dem == 0) {
            return 0; 
        

        return (tong * 1.0f) / dem; 
    }
}
};

int main() {
    int n;
    cout << "Nhap so phan tu cua day: ";
    cin >> n;
	Ds_nguyen daySo(n);
    daySo.nhapDay();
    daySo.xuatDay();
    float tbcduong = daySo.tbcduong();
    if (tbcduong == 0) {
        cout << "Khong co phan tu duong nao trong day." << endl;
    } else {
        cout << "Trung binh cong cac phan tu duong: " << tbcduong << endl;
    }
    int scp = daySo.demscp();
    cout << "So phan tu la so chinh phuong: " << scp << endl;
    return 0;
}



