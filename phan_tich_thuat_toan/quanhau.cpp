#include<bits/stdc++.h>
using namespace std;
int x[1000],n,dem;
bool datduoc(int k,int t){
	for(int i=1;i<k;i++){
		if(x[i]==t)	return 0;
		if(k-i==abs(t-x[i]))	return 0;
		
	}
	return 1;
} 
void TRY(int k){
	if(k-1==n){
		dem++;
		for(int i=1;i<=n;i++)	cout<<complex<int>(1,x[i])<<(i==n?"\n":" ");
		
	}
	for(int t=1;t<=n;t++)
	if(datduoc(k,t)){
		x[k]=t;
		TRY(k+1);
		
	}
}
int main(){
	cin>>n;
	TRY(1);
	cout<<dem;
}
