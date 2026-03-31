#include <bits/stdc++.h>
 using namespace std;
 int main() {
    priority_queue<int, vector<int>, less<int>> L;     
    priority_queue<int, vector<int>, greater<int>> R;
    int n, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (i % 2){
            L.push(x);
        } else {
            R.push(x);
        }
        if (i > 1 && L.top() > R.top()) {
            int l_top = L.top();
            int r_top = R.top();
            L.pop();
            R.pop();
            L.push(r_top);
            R.push(l_top);
        }
        printf("%d ", L.top());
    }
 }
