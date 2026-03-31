#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; 
	cin>>n;
	int res=0, h=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			h+=j;
		}
		if(h<=n){
			n-=h;
			res++;
			h=0;
		}
	}
	cout<<res;
}


