/*chuong trinh nhap vao ban kinh hinh tron.Tinh dien tich*/
#include<stdio.h>
#include<conio.h>
#define PI 3.14
main()
{
	float fR;
	printf("Nhap vao ban kinh hinh tron:");
	scanf("%f",&fR);
	printf("Dien tich hinh tron la:%.2f.\n", 2*PI*fR);
	getch();
}
