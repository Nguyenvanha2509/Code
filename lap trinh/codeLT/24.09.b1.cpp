#include<iostream>
using namespace std;
class diem{
	float x,y;
public:
	diem();
	diem(float a,float b);
	
};
diem::diem(){
	x=0;
	y=0;
}
diem::diem(float a,float b){
	this->x=a;
	this->y=b;
}
