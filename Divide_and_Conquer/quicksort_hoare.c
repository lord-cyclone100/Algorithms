#include<stdio.h>

void swap(int *x,int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int arr[],int low,int high){    //Hoare partition
	int pivot,i,j;
	pivot = arr[low];
	i = low;
	j=high+1;
	while(i<j){
		do{
			i++;
		}
		while(i<=high && arr[i]<pivot);
		do{
			j--;
		}
		while(arr[j]>pivot);
		if(i<j){
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[low],&arr[j]);
	return j;
}

void quicksort(int arr[],int start,int end){
	if(start<end){
		int p;
		p=partition(arr,start,end);
		quicksort(arr,start,p-1);
		quicksort(arr,p+1,end);
	}
}

int main(){
	int arr[100],n,i;
	printf("Enter length of array:");
	scanf("%d",&n);
	printf("Enter array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("\nOriginal unsorted array:");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
	quicksort(arr,0,n-1);
	
	printf("\nSorted array:");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}

	return 0;
}
