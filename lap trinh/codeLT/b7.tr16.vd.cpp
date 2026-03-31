#include<iostream>
using namespace std;
class shape{
protected:
	float cd,cr;
public:
 	void set_data(float a,float b){
		cd=a;cr=b;		
	}
};
class rectangle: public shape{
public:
	float area(){
		return(cd*cr);
	}	
};
class triangle:public shape{
public:
float area(){
	return(cd*cr/2);
	
}	
};
main(){
	rectangle rect;
	triangle tri;
	rect.set_data(5,3);
	tri.set_data(2,5);
	cout<< rect.area() <<endl;
	cout<< tri.area() <<endl;
}
