#include<bits/stdc++.h>
using namespace std;
#define int long long
main(){
	int n;
	cin>>n;
	bool s[n+1];
	fill(s,s+n+1,true);
	for(int i=2;i<=n; i++)
	if(s[i]){
		cout<<i<<" ";
		for(int j=i*i; j<=n;j+=i) s[j]=false;
		
	}
	
	
} 
