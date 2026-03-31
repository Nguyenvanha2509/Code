#include <iostream>
#include <string>
using namespace std;

class Node {
private:
    string data;
    Node* next;

public:
    Node(const string& d, Node* n = nullptr) : data(d), next(n) {}

    string getData() const { return data; }
    Node* getNext() const { return next; }
    void setNext(Node* n) { next = n; }
};

class Stack {
private:
    Node* topNode;
    int n;

public:
    Stack() : topNode(nullptr), n(0) {}

    void push(const string& x) {
        Node* newNode = new Node(x, topNode);
        topNode = newNode;
        ++n;
    }

    void pop() {
        if (n == 0) {
            cout << "STACK EMPTY! Khong the pop.\n";
        } else {
            Node* temp = topNode;
            topNode = topNode->getNext();
            delete temp;
            --n;
            cout << "Pop thanh cong.\n";
        }
    }

    string top() {
        if (n == 0) {
            cout << "STACK EMPTY! Khong co phan tu o dinh.\n";
            return "";
        } else {
            return topNode->getData();
        }
    }

    int size() {
        return n;
    }

    void outputStack() {
        if (n == 0) {
            cout << "STACK EMPTY! Khong co phan tu de xuat.\n";
        } else {
            cout << "Cac phan tu trong stack (tu dinh xuong day):\n";
            Node* temp = topNode;
            while (temp != nullptr) {
                cout << temp->getData() << " ";
                temp = temp->getNext();
            }
            cout << endl;
        }
    }

    ~Stack() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->getNext();
            delete temp;
        }
    }
};

void inputStack(Stack& stack) {
    cout << "Nhap so luong phan tu ban dau cua stack: ";
    int initSize;
    cin >> initSize;
    while (initSize <= 0) {
        cout << "So luong phan tu phai lon hon 0. Vui long nhap lai: ";
        cin >> initSize;
    }
    cin.ignore();
    for (int i = 0; i < initSize; ++i) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        string x;
        getline(cin, x);
        stack.push(x);
    }
    cout << "Stack da duoc khoi tao voi " << initSize << " phan tu.\n";
}

void menu(Stack& stack) {
    int lc;
    do {
        cout << "-------------------------------\n";
        cout << "1. push\n";
        cout << "2. pop\n";
        cout << "3. top\n";
        cout << "4. size\n";
        cout << "5. xuat stack\n";
        cout << "0. Thoat\n";
        cout << "-------------------------------\n";
        cout << "Nhap lua chon: ";
        cin >> lc;
        if (lc == 1) {
            cin.ignore();
            string x;
            cout << "Nhap chuoi: ";
            getline(cin, x);
            stack.push(x);
        } else if (lc == 2) {
            stack.pop();
        } else if (lc == 3) {
            string t = stack.top();
            if (!t.empty()) {
                cout << "Phan tu o dinh: " << t << endl;
            }
        } else if (lc == 4) {
            cout << "So phan tu trong stack: " << stack.size() << endl;
        } else if (lc == 5) {
            stack.outputStack();
        } else if (lc != 0) {
            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
    } while (lc != 0);
}

int main() {
    Stack stack;
    inputStack(stack);
    menu(stack);
    return 0;
}

