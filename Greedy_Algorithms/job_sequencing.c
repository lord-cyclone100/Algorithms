#include<stdio.h>

struct items{
	int profit[100];
	int deadline[100];
	int jobNumber[100];
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[],int arr2[],int arr3[],int n){
	int i,j,flag;
	int temp;
	for (i = 0;i<n-1;i++){
		flag = 0;
		for (j = 0;j<n-i-1;j++){
			if (arr[j] < arr[j+1]){
				swap(&arr[j],&arr[j+1]);
				swap(&arr2[j],&arr2[j+1]);
				swap(&arr3[j],&arr3[j+1]);
				flag = 1;
			}
		}
		if (flag == 0){
			break;
		}
	}	
}

int maximum(int arr[],int n){
	int max=arr[0],i;
	for(i=1;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}

void jobSequence(struct items it,int n){
	sort(it.profit,it.deadline,it.jobNumber,n);
	int gc[100]={0},m,i,j,profit=0;
	m = maximum(it.deadline,n);
	printf("Selected jobs:\n");
	for(i=0;i<n;i++){
		for(j=m;j>0;j--){
			if(it.deadline[i]>=j && gc[j]==0){
				profit += it.profit[i];
				gc[j]=1;
				printf("job no %d\n",it.jobNumber[i]);
				break;
			}
		}
	}
	printf("\nMaximum profit: %d",profit);
}

int main(){
	struct items it;
	int n,i;
	printf("Enter the total no of jobs:");
	scanf("%d",&n);
	printf("Enter the profits:");
	for(i=0;i<n;i++){
		scanf("%d",&it.profit[i]);
		it.jobNumber[i]=i+1;
	}
	printf("Enter the deadlines:");
	for(i=0;i<n;i++){
		scanf("%d",&it.deadline[i]);
	}
	jobSequence(it,n);
	return 0;
}
