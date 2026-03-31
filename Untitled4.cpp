#include <bits/stdc++.h>
using namespace std;

struct Node {
    string ten;
    bool laLa = false;
    int giaTri = 0;
    vector<Node*> con;
};

map<string, Node*> mp;
ofstream fout;

// in ra c? màn hình + file
void in(string s) {
    cout << s;
    fout << s;
}

// t?o node lá
Node* taoLa(int val) {
    Node* node = new Node();
    node->laLa = true;
    node->giaTri = val;
    node->ten = to_string(val);
    return node;
}

// d?c input
Node* docInput() {
    ifstream fin("input.txt");
    string line;
    Node* root = nullptr;

    while (getline(fin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string ten, loai;
        ss >> ten >> loai;

        Node* node;
        if (mp.count(ten)) node = mp[ten];
        else {
            node = new Node();
            node->ten = ten;
            mp[ten] = node;
        }

        if (root == nullptr) root = node;

        string x;
        while (ss >> x) {
            if (isdigit(x[0])) {
                node->con.push_back(taoLa(stoi(x)));
            } else {
                if (!mp.count(x)) {
                    Node* tmp = new Node();
                    tmp->ten = x;
                    mp[x] = tmp;
                }
                node->con.push_back(mp[x]);
            }
        }
    }
    return root;
}

// ====== TERMINAL-TEST + UTILITY ======
bool terminal(Node* node) {
    return node->laLa;
}

int utility(Node* node) {
    return node->giaTri;
}

// ====== MIN-VALUE ======
int MIN_VALUE(Node* node, int alpha, int beta);

int MAX_VALUE(Node* node, int alpha, int beta) {
    if (terminal(node)) {
        in("Leaf " + node->ten + " = " + to_string(utility(node)) + "\n");
        return utility(node);
    }

    in("MAX node " + node->ten + "\n");

    int v = INT_MIN;

    for (int i = 0; i < node->con.size(); i++) {
        Node* child = node->con[i];

        int val = MIN_VALUE(child, alpha, beta);
        v = max(v, val);

        if (v >= beta) {
            in(">>> CAT TIA tai MAX " + node->ten + ", bo: ");
            for (int j = i + 1; j < node->con.size(); j++) {
                in(node->con[j]->ten + " ");
            }
            in("\n");
            return v;
        }

        alpha = max(alpha, v);
    }

    in("Gia tri MAX " + node->ten + " = " + to_string(v) + "\n");
    return v;
}

// ====== MIN-VALUE ======
int MIN_VALUE(Node* node, int alpha, int beta) {
    if (terminal(node)) {
        in("Leaf " + node->ten + " = " + to_string(utility(node)) + "\n");
        return utility(node);
    }

    in("MIN node " + node->ten + "\n");

    int v = INT_MAX;

    for (int i = 0; i < node->con.size(); i++) {
        Node* child = node->con[i];

        int val = MAX_VALUE(child, alpha, beta);
        v = min(v, val);

        if (v <= alpha) {
            in(">>> CAT TIA tai MIN " + node->ten + ", bo: ");
            for (int j = i + 1; j < node->con.size(); j++) {
                in(node->con[j]->ten + " ");
            }
            in("\n");
            return v;
        }

        beta = min(beta, v);
    }

    in("Gia tri MIN " + node->ten + " = " + to_string(v) + "\n");
    return v;
}

// ====== ALPHA-BETA-SEARCH ======
int ALPHA_BETA_SEARCH(Node* root) {
    return MAX_VALUE(root, INT_MIN, INT_MAX);
}

// ====== MAIN ======
int main() {
    fout.open("output.txt");

    Node* root = docInput();

    int kq = ALPHA_BETA_SEARCH(root);

    in("====================\n");
    in("Ket qua cuoi cung (A) = " + to_string(kq) + "\n");

    fout.close();
    return 0;
}
