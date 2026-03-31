#include<iostream>
#include<math.h>
using namespace std;
class diem{
	float x,y;
public:
	void nhap();
	void xuat();
	float kc();
	float kc(const diem &d);
	friend float kc(diem d1, diem d2);	
};
void diem::nhap(){
	cout<<"\nNhap toa do cua diem: ";
	cin>>x>>y;
}
void diem::xuat(){
	cout<<"("<<x<<","<<y<<")";
}
float diem::kc() {
    return sqrt(x * x + y * y); 
}
float diem::kc(const diem &d){
	return sqrt((x-d.x)*(x-d.x)+(y-d.y)*(y-d.y));
}
float kc(diem d1, diem d2){
	return sqrt((d1.x-d2.x)*(d1.x-d2.x)+(d1.y-d2.y)*(d1.y-d2.y));
}
int main(){
	diem d1,d2,d3;
	d1.nhap();
	d1.xuat();
	d2.nhap();
	d2.xuat();
	d3.nhap();
	d3.xuat(); 
	cout<<"\nkc tu d1 den O ="<<d1.kc();
	cout<<"\nkc tu d1 den d2 ="<<d1.kc(d2);
	cout<<"\nkc tu d1 den d3 ="<<d1.kc(d3);
	cout<<"\nkc tu d2 den 0 ="<<d2.kc();
	
}

