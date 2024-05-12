#include<stdio.h>
#define MAX 30

int arr[MAX],i,n;

void adjustHeap(int arr[],int n,int i){
	int smallest,left,right;
	left = 2*i;
	right = 2*i+1;
	if(left<=n && arr[left]<arr[i]){
		smallest = left;
	}
	else{
		smallest = i;
	}
	if(right<=n && arr[right]<arr[smallest]){
		smallest = right;
	}
	if(smallest != i){
		arr[i]=arr[i]+arr[smallest];
		arr[smallest]=arr[i]-arr[smallest];
		arr[i]=arr[i]-arr[smallest];
		adjustHeap(arr,n,smallest);
	}
}

void buildMinHeap(int arr[], int n) {
	int i;
    for (i=n/2;i>=1;i--) {
        adjustHeap(arr, n, i);
    }
}

void printQueue(int arr[],int n){
	int i;
	for(i=1;i<=n;i++){
		printf("%d ",arr[i]);
	}
}

int getMin(int arr[]){
	return arr[1];
}

int extractMin(int arr[],int n){
	int min;
	if(n==0){
		return -1;
	}
	if(n==1){
		n --;
		return arr[1];
	}
	min = arr[1];
	arr[1]=arr[n];
	n--;
	adjustHeap(arr,n,1);
	return min;
}

void decreaseKey(int index,int nvalue){
	int i;
	if(index<1 || index > n){
		printf("Invalid index");
		return;
	}
	arr[index]=nvalue;
	for(i=index;i>=1;i--){
		adjustHeap(arr,n,i);
	}
}

void insertKey(int value){
	if(n==MAX){
		printf("Queue overflow");
		return;
	}
	n++;
	arr[n]=value;
	int i;
	for(i=n;i>=1;i--){
		adjustHeap(arr,n,i);
	}
}

void deleteKey(int index){
	if(index<1 || index>n){
		printf("Deletion not possible");
		return;
	}
	decreaseKey(index,-9999);
	int m;
	m = extractMin(arr,n);
	n--;
}

int main(){
	
	int i,choice,min,index,value;
	printf("Initialize queue\n");
	printf("Enter length of queue:");
	scanf("%d",&n);
	printf("Enter array elements:");
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Original array:");
	for(i=1;i<=n;i++){
		printf("%d ",arr[i]);
	}
	
	buildMinHeap(arr,n);
	printf("\nMin heap queue:");
	for(i=1;i<=n;i++){
		printf("%d ",arr[i]);
	}
	do{
		printf("\nMenu\n");
		printf("1) Get Minimum\n");
		printf("2) Extract Minimum\n");
		printf("3) Decrease Key\n");
		printf("4) Insert Key\n");
		printf("5) Delete Key\n");
		printf("6) Print Queue\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				min = getMin(arr);
				printf("Minimum element: %d",min);
				break;
			case 2:
				min = extractMin(arr,n);
				printf("Minimum element: %d",min);
				n--;
				break;
			case 3:
				printf("Enter index:");
				scanf("%d",&index);
				printf("Enter new value:");
				scanf("%d",&value);
				decreaseKey(index,value);
				break;
			case 4:
				printf("Enter value:");
				scanf("%d",&value);
				insertKey(value);
				break;
			case 5:
				printf("Enter index:");
				scanf("%d",&index);
				deleteKey(index);
				break;
			case 6:
				printQueue(arr,n);
				break;
			case 0:
				printf("Exiting...");
				break;
		}
	}
	while(choice !=0);
	
	
	
	
	
	return 0;
}



