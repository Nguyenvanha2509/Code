#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e6 + 5;

void sieve(vector<bool>& a, vector<int>& prefix_a) {
    a[0] = a[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (a[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                a[j] = false;
            }
        }
    }

    prefix_a[0] = 0;
    for (int i = 1; i <= MAX; i++) {
        prefix_a[i] = prefix_a[i - 1] + (a[i] ? 1 : 0);
    }
}

int main() {
    vector<bool> a(MAX, true);      
    vector<int> prefix_a(MAX, 0);   
    sieve(a, prefix_a);

    int T;
    cin >> T;
    while (T--) {
        int L, R;
        cin >> L >> R;
        cout << prefix_a[R] - prefix_a[L - 1] << endl;
    }
    return 0;
}
