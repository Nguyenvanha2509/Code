#include <bits/stdc++.h>
using namespace std;

struct Node {
    string ten;
    bool laLa = false;
    int giaTri = 0;
    vector<Node*> con;
};

map<string, Node*> mp;
ofstream out;

// t?o node lá
Node* taoLa(int val) {
    Node* node = new Node();
    node->laLa = true;
    node->giaTri = val;
    node->ten = to_string(val);
    return node;
}

// d?c input t? file
Node* docInput() {
    ifstream in("input.txt");
    string line;
    Node* root = nullptr;

    while (getline(in, line)) {
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

// Alpha-Beta
int alphaBeta(Node* node, int alpha, int beta, bool laMax) {
    if (node->laLa) {
        out << "Node la " << node->ten << " = " << node->giaTri << endl;
        return node->giaTri;
    }

    out << "Xet node " << node->ten 
        << (laMax ? " (MAX)" : " (MIN)") << endl;

    if (laMax) {
        int best = INT_MIN;
        for (int i = 0; i < node->con.size(); i++) {
            Node* child = node->con[i];

            int val = alphaBeta(child, alpha, beta, false);
            best = max(best, val);
            alpha = max(alpha, best);

            if (beta <= alpha) {
                out << ">>> CAT TIA tai node " << node->ten 
                    << ", bo cac nhanh: ";
                for (int j = i + 1; j < node->con.size(); j++) {
                    out << node->con[j]->ten << " ";
                }
                out << endl;
                break;
            }
        }
        out << "Gia tri node " << node->ten << " = " << best << endl;
        return best;
    } 
    else {
        int best = INT_MAX;
        for (int i = 0; i < node->con.size(); i++) {
            Node* child = node->con[i];

            int val = alphaBeta(child, alpha, beta, true);
            best = min(best, val);
            beta = min(beta, best);

            if (beta <= alpha) {
                out << ">>> CAT TIA tai node " << node->ten 
                    << ", bo cac nhanh: ";
                for (int j = i + 1; j < node->con.size(); j++) {
                    out << node->con[j]->ten << " ";
                }
                out << endl;
                break;
            }
        }
        out << "Gia tri node " << node->ten << " = " << best << endl;
        return best;
    }
}

int main() {
    out.open("output.txt");

    Node* root = docInput();

    int kq = alphaBeta(root, INT_MIN, INT_MAX, true);

    out << "====================" << endl;
    out << "Ket qua cuoi cung (A) = " << kq << endl;

    out.close();
    return 0;
}
