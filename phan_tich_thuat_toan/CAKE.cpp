#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k; 
	cin>>n>>k;
	vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    } 
	long long tong = 0;
    for (int i = 0; i < k; ++i) {
        tong += a[i];
    }

    long long MAXtong = tong;

    for (int i = k; i < n; ++i) {
        tong = tong - a[i - k] + a[i];
        if (tong > MAXtong) {
            MAXtong = tong;
        }
    }

    cout << MAXtong << endl;
    return 0;
}
