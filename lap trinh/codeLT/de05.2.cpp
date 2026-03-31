#include <iostream>
#include <string>
using namespace std;

class hang {
protected:
    string maHang;     
    string tenHang;  
    string dongia;     
    int soLuong;      

public:
    void nhap();      
    void xuat() const; 
    int getSoLuong() const { return soLuong; }   
    string getTenHang() const { return tenHang; } 
};

void hang::nhap() {
    cout << "Nhap ma hang: ";
    cin >> maHang;
    cout << "Nhap ten hang: ";
    cin.ignore();
    getline(cin, tenHang);
    cout << "Nhap dongia: ";
    getline(cin, dongia);
    cout << "Nhap so luong: ";
    cin >> soLuong;
}

void hang::xuat() const {
    cout << "Ma hang: " << maHang << endl;
    cout << "Ten hang: " << tenHang << endl;
    cout << "Don gia : " << dongia << endl;
    cout << "So luong: " << soLuong << endl;
}

class maytinh : public hang {
private:
    string hedieuhanh;//win,mac
    float trongluong;
	string gia;
public:
    void nhap();      
    void xuat() const; 
};

void maytinh::nhap() {
    maytinh::nhap();
    cout << "he dieu hanh: ";
    cin >> ;
}

void DIENTU::xuat() const {
    QLH::xuat();
    cout << "Thoi gian bao hanh: " << tgbh << " thang" << endl;
}

int main() {
    int n;
    cout << "Nhap so luong mat hang dien tu: ";
    cin >> n;

    DIENTU *hangDienTu = new DIENTU[n];
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin cho mat hang dien tu thu " << i + 1 << ":\n";
        hangDienTu[i].nhap();
    }

    cout << "\nDanh sach mat hang dien tu:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nThong tin mat hang thu " << i + 1 << ":\n";
        hangDienTu[i].xuat();
    }

    // Thong ke tong so luong hang cua tung loai co thoi gian bao hanh >= 12 thang
    int tongLoai1 = 0, tongLoai2 = 0, tongLoai3 = 0;
    for (int i = 0; i < n; i++) {
        if (hangDienTu[i].getTGBH() >= 12) {
            if (hangDienTu[i].getLoaiHang() == 1) {
                tongLoai1 += hangDienTu[i].getSoLuong();
            } else if (hangDienTu[i].getLoaiHang() == 2) {
                tongLoai2 += hangDienTu[i].getSoLuong();
            } else if (hangDienTu[i].getLoaiHang() == 3) {
                tongLoai3 += hangDienTu[i].getSoLuong();
            }
        }
    }

    cout << "\nTong so luong hang dien tu co thoi gian bao hanh >= 12 thang:\n";
    cout << "Loai 1: " << tongLoai1 << endl;
    cout << "Loai 2: " << tongLoai2 << endl;
    cout << "Loai 3: " << tongLoai3 << endl;

    // Tim kiem mat hang theo ten cho truoc
    string tenTimKiem;
    cout << "\nNhap ten mat hang can tim: ";
    cin.ignore();
    getline(cin, tenTimKiem);
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (hangDienTu[i].getTenHang() == tenTimKiem) {
            cout << "\nMat hang tim thay:\n";
            hangDienTu[i].xuat();
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay mat hang co ten \"" << tenTimKiem << "\" trong danh sach.\n";
    }

    delete[] hangDienTu;
    return 0;
}

