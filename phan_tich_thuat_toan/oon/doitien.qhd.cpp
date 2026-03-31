#include <bits/stdc++.h>
using namespace std;
const int MAX_M = 40005; 
int C[MAX_M]= {}, n, q;

main()
{
	cin>>n>>q;
	fill(C + 1, C + MAX_M, 1e9);
	C[0]= 0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		for(int j=a;j<=MAX_M;j++)
		C[j]=min(C[j], 1+C[j-a]);
	}
	while(q--){
	int M;
	cin>>M;
	if(C[M] == 1e9) C[M] = -1;
	    cout << C[M] << "\n";
	}
}
