#include<stdio.h>

void swap(int *x,int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int a[],int low,int high){    //Lomuto partition
	int pivot,i,j;
	pivot = a[high];
	i = low-1;
	j=low;
	for(j=low;j<=high-1;j++){
		if(a[j]<=pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return (i+1);
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
