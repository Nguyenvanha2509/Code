#include<iostream>
#include<math.h>
using namespace std;
class dt{
	int n;
	float *a;
public:
	dt() {	}	
	dt(int n1);
	~dt() {delete a;}
	dt(const dt& d);
	dt& operator=(const dt& d);
	friend void operator>>(istream& io,dt& d);
	friend void operator<<(ostream& os,dt& d);
	float gtri(float x);

};
dt::dt(int n1){
	n=n1;
	a=new float[n+1];
	cout<<"\n nhap cac he so cua da thuc bac "<<n<<":";
	for(int i=0;i<=n;i++)
		cin>>a[i];
}
dt::dt(const dt& d){
	n=d.n;
	a=new float[n+1];
	for(int i=0;i<=n;i++)
	a[i]=d.a[i];
}
dt&dt::operator=(const dt& d){
	n=d.n;
	a=new float[n+1];
	for(int i=0;i<=n;i++)
	a[i]=d.a[i];
	return (*this);
}
void operator>>(istream& is,dt&d){
	cout<<"\n bac cua da thuc thu 2: ";
	is>>d.n;
	d.a=new float[d.n+1];
	cout<<"\n cac he so cua da thuc: ";
	for(int i=0;i<=d.n;i++)
		is>>d.a[i];
}
void operator<<(ostream& os,dt& d){
	cout<<endl;
	for(int i=0;i<=d.n;i++)
		os<<d.a[i]<<" ";
}
float dt::gtri(float x){
	
	float gt=0;
	for(int i=0;i<=n;i++){
		gt += a[i] * pow(x,i);
	}
	return gt;
}


int main(){
	dt x(3),y,z;
	cout<<"cac he so cua da thuc tren:\n";
	cout<<x;
	cin>>y;
	cout<<y;
	z=x;
	cout<<z;
}
