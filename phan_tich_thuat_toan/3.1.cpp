#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double>Diem;
#define x first
#define y second
double kc(Diem A, Diem B){
		A.x-= B.x;
		A.y-= B.y;
		return sqrt(A.x*A.x+A.y*A.y);
}


int main(){
	 A,B,C,M;
	 cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
	 M=((A.x+B.x+C.x)/3,(A.y+B.y+C.y)/3);
	 double d=10,res=kc(M,A)+kc(M,B)+kc(M,C);
	 while(d,d>1e-5){
	 	Diem Next[]= {{M.x-d,M.y},{M.x+d,M.y}}
	 }
} 
