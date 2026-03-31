#include<iostream> 
using namespace std; 
class Nguoi { 
	string ht; 
	int tuoi; 
public: 
	void nhap(); 
	int laytuoi() { 
		return tuoi; 
	} 
	string layht() { 
		return ht; 
	} 
}; 
void Nguoi::nhap() { 
	cin.ignore(1); 
	cout<<"Ho ten: "; 
	getline(cin, ht); 
	cout<<"Tuoi: "; 
	cin>>tuoi; 
}
class Cauthu: public Nguoi { 
	int bt, ptd;  
public: 
	void nhap(); 
	float tinhtien() { 
		float t=0; 
		if(ptd>300)  
		t += 10; 
		t += 5*bt;   
		return t; 
		} 
}; 
void Cauthu::nhap() { 
	Nguoi::nhap(); 
	cout<<"So ban thang: "; 
	cin>>bt; 
	cout<<"So phut dau: "; 
	cin>>ptd; 
}
int main()  
{ 
	Cauthu ct[100]; 
	int n, i; 
	cout<<"So cau thu: "; 
	cin>>n; 
	// Nhap danh sach cau thu 
	for(i=1; i<=n; ++i) 
	ct[i].nhap(); 
	cout<<endl<<"Danh sach cau thu:"<<endl; 
	for(i=1; i<=n; ++i)   
	cout<<ct[i].layht()<<"  "<<ct[i].laytuoi()<<endl; 
	// Tim cau thu nhieu tuoi nhat 
	int max= 0; 
	for(i=1; i<=n; ++i)   
		if(ct[i].laytuoi()>max) 
			max= ct[i].laytuoi(); 
	cout<<endl<<"Cau thu nhieu tuoi nhat:"<<endl;     
	for(i=1; i<=n; ++i)     
		if(ct[i].laytuoi()==max) 
			cout<<ct[i].layht()<<"  "<<ct[i].laytuoi()<<endl;  
	// In danh sach cau thu va tien thuong 
	cout<<endl<<"Danh sach cau thu cung tien thuong:"<<endl; 
	for(i=1; i<=n; ++i){ 
		cout<<"ho ten: "<<ct[i].layht()<<"  "<<"tuoi: "<<ct[i].laytuoi()<<"   "<<"tien thuong:"<< ct[i].tinhtien()<<endl; 
	} 
} 
