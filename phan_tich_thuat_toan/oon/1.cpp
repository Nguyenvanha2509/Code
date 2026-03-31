#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<pair<int, int>> Q;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    

    for (int i = 0; i < n; i++) {
    	cin >> a[i];
        Q.push({a[i], i});
        if (i >= k - 1) {
            while (Q.top().second <= i - k) Q.pop();
            cout << Q.top().first << " ";
        }
    }
}

