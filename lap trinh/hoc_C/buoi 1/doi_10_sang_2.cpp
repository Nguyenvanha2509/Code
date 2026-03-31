#include<stdio.h>
main(){
	int n;
	int a[32];
	int i=0;
	printf("nhap so nguyen he 10:");
	scanf("%d",&n);
	if(n==0)
	{
		printf("so nhi phan: 0\n");
		
	}
	while(n>0){
		a[i]=n%2;
		n=n/2;
		i++;
	}
	printf("so nhi phan:");
	for(int j=i-1;j>=0; j--)
	{
		printf("%d",a[j]);
	}	
}
