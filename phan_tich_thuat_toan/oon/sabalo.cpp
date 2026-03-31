#include <bits/stdc++.h>
 using namespace std;
 const int MAX_M = 30005;
 int C[MAX_M];
 int a[105], b[105], n, q;
 vector<int> queries;
 int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    cin >> q;
    queries.resize(q);
    int maxM = 0;
    for(int i = 0; i < q; i++) {
        cin >> queries[i];
        maxM = max(maxM, queries[i]);
    }
    fill(C, C + maxM + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = maxM; j >= a[i]; j--) {
            C[ j] = max(C[j], C[j - a[i]] + b[i]);
        }
    }
    for (int i = 0; i < q; i++) {
        cout << C[queries[i]] << "\n";
    }
    return 0;
}
