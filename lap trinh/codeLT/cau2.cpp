#include <iostream>
#include <string>
using namespace std;

class NhanVien {
private:
    string ma;
    string hoTen;
    int namSinh;
    string gioiTinh;
    double luong;

public:
    // Ham dung khong tham ss 
    NhanVien() : ma(""), hoTen(""), namSinh(0), gioiTinh(""), luong(0) {}

    // Ham dung có tham so 
    NhanVien(string ma, string hoTen, int namSinh, string gioiTinh, double luong)
        : ma(ma), hoTen(hoTen), namSinh(namSinh), gioiTinh(gioiTinh), luong(luong) {}

    // Toan tu nhap
    friend istream& operator>>(istream& is, NhanVien& nv) {
        cout << "Nhap ma nhan vien: ";
        is >> nv.ma;
        cout << "Nhap ho ten: ";
        is.ignore();
        getline(is, nv.hoTen);
        cout << "Nhap nam sinh: ";
        is >> nv.namSinh;
        cout << "Nhap gioi tinh: ";
        is.ignore();
        getline(is, nv.gioiTinh);
        cout << "Nhap luong: ";
        is >> nv.luong;
        return is;
    }

    // Toan tu xuat
    friend ostream& operator<<(ostream& os, const NhanVien& nv) {
        os << "Ma: " << nv.ma << ", Ho ten: " << nv.hoTen
           << ", Nam sinh: " << nv.namSinh << ", Gioi tinh: " << nv.gioiTinh
           << ", Luong: " << nv.luong;
        return os;
    }

    // Phuong thuc lay ma 
    string getMa() const {
        return ma;
    }

    // Phuong thuc lay luong
    double getLuong() const {
        return luong;
    }
};
struct Node {
    NhanVien data;
    Node* next;

    Node(const NhanVien& nv) : data(nv), next(nullptr) {}
};
class QuanLyNhanVien {
private:
    Node* head;
    Node* tail;

public:
    // Ham dung khoi tao danh sach rong
    QuanLyNhanVien() : head(nullptr), tail(nullptr) {}

    // Phuong thuc them nhan vien vao cuoi danh sach
    void themNhanVien(const NhanVien& nv) {
        Node* newNode = new Node(nv);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Phuong thuc xoa nhan vien theo ma 
    void xoaNhanVien(const string& ma) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->data.getMa() == ma) {
                if (previous == nullptr) {  // Xoa nut dau 
                    head = current->next;
                } else {  // Xóa nút giua hoac cuoi
                    previous->next = current->next;
                }
                if (current == tail) {  // Cap nhat lai tail neu xoa nut cuoi
                    tail = previous;
                }
                delete current;
                cout << "Da xoa nhan vien co ma: " << ma << endl;
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Khong tim thay nhan vien co ma: " << ma << endl;
    }

    // Phuong thuc in danh sach cac nhan vien co luong lon hon 2.000.000
    void inNhanVienLuongLonHon(double mucLuong) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.getLuong() > mucLuong) {
                cout << current->data << endl;
            }
            current = current->next;
        }
    }

    // Phuong thuc huy danh sách
    ~QuanLyNhanVien() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    QuanLyNhanVien qlnv;
    int n;

    // Nhap so luong nhan vien
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    // Nhap thong tin nhan vien
    for (int i = 0; i < n; ++i) {
        NhanVien nv;
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":\n";
        cin >> nv;
        qlnv.themNhanVien(nv);
    }

    // In danh sach nhan vien co luong lon hon 2.000.000
    cout << "\nDanh sach nhan vien co luong lon hon 2.000.000:\n";
    qlnv.inNhanVienLuongLonHon(2000000);

    // Xoa nhan vien theo ma 
    string maXoa;
    cout << "\nNhap ma nhan vien can xoa: ";
    cin >> maXoa;
    qlnv.xoaNhanVien(maXoa);

    // In lai danh sach sau khi xoa
    cout << "\nDanh sach nhan vien sau khi xoa:\n";
    qlnv.inNhanVienLuongLonHon(0);  // In toàn bo danh sách
    return 0;
}

