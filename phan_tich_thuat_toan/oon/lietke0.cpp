//Tichpx Liet ke nhung so di duoc trong bai moi con duong ve 0 
#include<bits/stdc++.h> 
using namespace std; 
int main(){ 
	int n; 
	stack<int> S; 
	set<int> Out; 
	cin>>n; 
	S.push(n); 
	Out.insert(n); 
	while(S.size()>0){ 
		int u=S.top(); 
		S.pop(); 
		for(int a=1; a*a<=u;a++)
		if(u%a==0){ 
			int v=(a-1)*(u/a+1); 
			if (Out.find(v)==Out.end()) {S.push(v); Out.insert(v);} 
		} 
	} 
	for (int x: Out) cout<<x<<" "; 
}
