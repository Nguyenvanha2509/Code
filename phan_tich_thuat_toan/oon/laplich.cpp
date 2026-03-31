#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> event;

#define start first
#define end second
bool cmp(event u,event v) {
	return u.end< v.end;
}
int main() {
	int n, res= 0, t= -1e9;
	cin>> n;
	event A[n];
	for (auto&a: A) cin>> a.start>> a.end;
	sort(A ,A + n ,cmp);
	for (auto a:A) if (a.start>t) {
		res++;
		t= a.end;
	}
	cout<< res;
}
