#include<iostream>
#include<math.h>
using namespace std;
class diem{
	float x,y;
public:
	void nhap();
	void xuat();
	float kc(diem d);	//khoang cach tu this den d
};
void diem::nhap(){
	cin>>x>>y;
}
void diem::xuat(){
	cout<<"("<<x<<","<<y<<")";
}
float diem::kc(diem d){
	return sqrt((x-d.x)*(x-d.x)+(y-d.y)*(y-d.y));
}
int main(){
	diem d1,d2,d3;
	float a,b,c;
	cout<<"\ nhap diem 1:";
	d1.nhap();
	cout<<"\ nhap diem 2:";
	d2.nhap();
	cout<<"\ nhap diem 3:";
	d3.nhap();		
	a=d1.kc(d2);
	b=d2.kc(d3);
	c=d3.kc(d1);
	cout<<"khoang cach giua d1 va d2: "<<a<<endl;
	cout<<"khoang cach giua d2 va d3: "<<b<<endl;
	cout<<"khoang cach giua d3 va d1: "<<c<<endl;
}
