#include<bits/stdc++.h>
using namespace std;

int main(){
	int n ;
	cin>>n;
	vector<int >a(n);
	long t=0;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			t+=a[i]*a[j];
		}
	}
	cout<<t;  
}
