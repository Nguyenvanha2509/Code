#include<iostream>
#include<string>
using namespace std;
class cty{
	string ten;
	int ntl;
public:
	string lay_ten()	{ return ten; }
	int lay_ntl() {return ntl; }	
	void nhap();
};

class ctypm: public cty{
	int sltv;
public:
	int lay_ltv	() { return sltv;}
	void nhap();
};
class ctyvt: public cty{
	int soto;
public:
	int lay_oto() {return soto;}
	void nhap();	
};
void cty::nhap(){
	cin.ignore(1);
	cout<<"ten cong ty: ";
	getline(cin,ten);
	cout<<"nam thanh lap: ";
	cin>>ntl; 
	
}
void ctypm::nhap(){
	cty::nhap();
	cout<<"so lap trinh vien: ";
	cin>>sltv;
	
}
void ctyvt::nhap(){
	cty::nhap();
	cout<<"so oto:";
	cin>>soto;

}
int main()
{
	ctypm pm[50];
	ctyvt vt[50];
	int m,n,i;
	cout<<"\n nhap du lieu cac cong ty PM:\n";
	cout<<"so cong ty PM: ";
	cin>>m;
	for(i=1;i<=m;++i)
		pm[i].nhap();
	for(i=1;i<=m;++i)
		if(pm[i].lay_ntl()>2000 && pm[i].lay_ltv()>20)
			cout<<pm[i].lay_ten()<<","<<pm[i].lay_ntl()<<","<<pm[i].lay_ltv();	
	cout<<"\n nhap du lieu cac cong ty vt:\n";
	cout<<"so cong ty vt: ";
	cin>>n;
	for(i=1;i<=n;++i)
		vt[i].nhap();
	for(i=1;i<=n;++i)
		if(vt[i].lay_ntl()<2000 && vt[i].lay_oto()<=10)
			cout<<vt[i].lay_ten()<<","<<pm[i].lay_ntl()<<","<<vt[i].lay_oto()<<endl;
} 
