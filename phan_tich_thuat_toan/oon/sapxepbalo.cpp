#include <bits/stdc++.h>
using namespace std;
int C[100][1000]= {},n,a[100],b[100],q;
void TRACE(int n,int M) {
    while (n > 0 && M > 0) {
        if (a[n] <= M && C[n][M] == C[n - 1][M - a[n]] + b[n]) {
            cout << "Chon vat " << n << " kt: " << a[n] << " gt: " << b[n] << "\n";
            M -= a[n];
        }
        n--;
    }
}
main() {
	cin >> n;
	for(int i = 1; i<=n;i++) cin >> a[i] >> b[i];
	cin >> q;
	while(q--) {
	int M;
	cin >> M;
	fill(C[0]+1,C[0]+M+1,1e-9);
	for (int i = 1;i<=n;i++) {
		for (int j = 0;j<=M;j++) {
		if (a[i]>j) C[i][j] = C[i-1][j];
		else C[i][j] = max(C[i-1][j], b[i] + C[i-1][j - a[i]]);
		}
	}
	if (C[n][M]==1e-9) cout << -1 << endl;
 	else { cout << C[n][M] << "\n";TRACE(n,M);}
 	}
 	
}
 
