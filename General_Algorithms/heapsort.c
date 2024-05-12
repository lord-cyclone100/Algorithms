#include<stdio.h>

void adjustHeap(int arr[],int n,int i){
	int largest,left,right;
	left = 2*i;
	right = 2*i+1;
	if(left<=n && arr[left]>arr[i]){
		largest = left;
	}
	else{
		largest = i;
	}
	if(right<=n && arr[right]>arr[largest]){
		largest = right;
	}
	if(largest != i){
		arr[i]=arr[i]+arr[largest];
		arr[largest]=arr[i]-arr[largest];
		arr[i]=arr[i]-arr[largest];
		adjustHeap(arr,n,largest);
	}
}

void makeHeap(int arr[],int n){
	int i;
	for(i=n/2;i>=1;i--){
		adjustHeap(arr,n,i);
	}
}

void heapSort(int arr[],int n){
	makeHeap(arr,n);
	int i;
	for(i=n;i>1;i--){
		arr[1]=arr[1]+arr[i];
		arr[i]=arr[1]-arr[i];
		arr[1]=arr[1]-arr[i];
		adjustHeap(arr,i-1,1);
	}
}

int main(){
	int arr[100],i,n;
	printf("Enter length of array:");
	scanf("%d",&n);
	printf("Enter array elements:");
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Original array:");
	for(i=1;i<=n;i++){
		printf("%d ",arr[i]);
	}
	
	heapSort(arr,n);
	printf("\nSorted array:");
	for(i=1;i<=n;i++){
		printf("%d ",arr[i]);
	}
	
	return 0;
}
