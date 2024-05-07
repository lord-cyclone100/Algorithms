#include<stdio.h>

void merge(int arr[],int low,int mid,int high){
	int b[100],i,j,k;
	i = low;
	j = mid+1;
	k = low;
	while(i<=mid && j<=high){
		if(arr[i]<=arr[j]){
			b[k++]=arr[i++];
		}
		else{
			b[k++]=arr[j++];
		}
	}
	while(i<=mid){
		b[k++]=arr[i++];
	}
	while(j<=high){
		b[k++]=arr[j++];
	}
	for(i=low;i<=high;i++){
		arr[i]=b[i];
	}
}

void mergesort(int arr[],int low,int high){
	int mid;
	if(low<high){
		mid = (low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
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
	
	mergesort(arr,0,n-1);
	
	printf("\nSorted array:");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
	return 0;
}
