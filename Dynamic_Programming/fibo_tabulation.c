#include<stdio.h>

int fiboTabulation(n){
	int lookup[n],i;
	lookup[0]=0;
	lookup[1]=1;
	for(i=2;i<=n;i++){
		lookup[i]=lookup[i-1]+lookup[i-2];
	}
	return lookup[n];
}

int main(){
	int n;
	printf("enter the value of n:");
	scanf("%d",&n);
	printf("%d",fiboTabulation(n));
	return 0;
}
