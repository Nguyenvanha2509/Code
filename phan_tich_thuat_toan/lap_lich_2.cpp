#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> sk;
#define bd first
#define kt second
bool ss(sk u,sk v)	{return u.kt<v.kt;}

void sol(){
	int n, res=0,t=-1e9,z=-1e9;
	cin>>n;
	sk A[n];
	for(auto &a:A)	cin>>a.bd>>a.kt;
	sort(A,A+n, ss);
	for(auto a:A)	if(a.bd>t){
		if(t<z)	{swap(t,z);}
		if(a.bd>t) {res++; t=a.kt;	}
		else if(a.bd>z)	{res++; z=a.kt;	}
	}
	cout<<res;
}

int main(){
	int tt;
	cin>>tt;
	while(tt--){
		sol();
		
	}
}

