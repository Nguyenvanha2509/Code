#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	queue<pii> Q;
	map<pii, int> M;
	Q.push({0,0}); M[{0,0}]=0;
	while(Q.size()){
		int x=Q.front().first, y=Q.front().second, z=x+y;
		Q.pop();
		pii Next[]={{0,y}, {n,y}, {x,0}, {x,m}, {max(0,z-m), min (m,z)}, {min (z,n), max(0,z-n)}};
		for(auto t: Next)
		if(M.find(t)==M.end())
		{
			M[t]=M[{x,y}]+1;
			Q.push(t);
			if(t.first==k or t.second==k) {cout<<M[t]<<"\n"; return 0;}
		}
	}
	cout<<"Khong dong duoc nuoc";
}
