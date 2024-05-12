#include<stdio.h>

void maxmin_without_DAC(int a[],int n){
	int max,min,i;
	max = a[0];
	min = a[0];
	for(i=1;i<n-1;i++){
		if(a[i] > max){
			max = a[i];
		}
		if(a[i] < min){
			min = a[i];
		}
	}
	printf("Maximum element:%d",max);
	printf("\nMinimum element:%d",min);
}

int main(){
	
	int arr[100],n,i;
	printf("Enter the length of array:");
	scanf("%d",&n);
	printf("Enter array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	maxmin_without_DAC(arr,n);
	return 0;
}
