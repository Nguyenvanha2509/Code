#include<bits/stdc++.h>
using namespace std;

main(){
	int n;
	cin>>n;
	int a[n+5]={};
	while(a[0]==0){
		for(int i=0; i<=n; i++) cout<<a[i]<<" ";
		cout<<"\n";
		int j;
		for(j=n; a[j]==1;j--) a[j]=0;
		a[j]=1;
	}
}
