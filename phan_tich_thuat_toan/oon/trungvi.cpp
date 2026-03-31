#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    for (int i = 0; i < n; ++i) {
        cin >> x;

        if (maxHeap.empty() || x <= maxHeap.top()) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        cout << maxHeap.top() << " ";
    }

    return 0;
}

