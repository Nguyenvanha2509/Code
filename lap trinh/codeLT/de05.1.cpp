#include<iostream>
using namespace std;
class dt{
	int n;
	float *a;
public:
	dt(){ }
	dt(int n1);
	~dt() { delete[] a;}
	void nhap();
	void xuat();
	dt cong(dt p);		
};






int main(){
	
}


