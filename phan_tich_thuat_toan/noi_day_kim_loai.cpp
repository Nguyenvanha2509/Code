#include<bits/stdc++.h>
using namespace std;

int main(){
	long n,x,res=0;
	priority_queue<long,vector<long>,greater<long>>Q;
	cin>>n;
	while(n--) {cin>>x; Q.push(x);	}
	while(Q.size() >1){
		x = Q.top(); Q.pop();
		x += Q.top(); Q.pop();
		res+=x;
		Q.push(x);
	}
	cout<<res;
}
