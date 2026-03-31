#include<stdio.h>
main(){
	int n;
	char a[32];
	int i=0;
	int du;
	
	printf("nhap so he 10:", n);
	scanf("%d",&n);
	
	if(n==0)
		printf("so he 16 la 0");
	while(n>0){
		du=n%16;
		if(du<10)
			a[i]=du+'0';
		else
			a[i]=du-10+'A';
			
		n=n/16;
		i++;
				
	}
	printf ("so he 16: ");
	for(int j=i-1;j>=0;j--){
		printf("%c",a[j]);
	}	
}
