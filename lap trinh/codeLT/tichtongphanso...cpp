#include<iostream>
using namespace std;
class PS{
	int ts,ms;
public:
	void nhap();
	void xuat() {cout<<endl<<ts<<"/"<<ms;}
	PS nhan(PS p);
	PS cong(PS p); 
};
void PS::nhap(){
	cout<<"nhap ts,ms:";
	cin>>ts>>ms;
	
}
PS PS::nhan(PS p){
	PS t;
	t.ts=this->ts*p.ts;
	t.ms=this->ms*p.ms;
	return t;
}
PS PS::cong(PS p){
	PS t;
	t.ts=this->ts*p.ms;
	t.ms=this->ms*p.ms;
	return t; 
} 
int main(){
	PS p1,p2,p3,p4;
	p1.nhap();
	p2.nhap();
	p3=p1.nhan(p2);
	cout<<"\ntich 2 phan so: ";
	p3.xuat();
	p4=p1.cong(p2);
	cout<<"\n tong 2 phan so: ";
	p4.xuat();
}
