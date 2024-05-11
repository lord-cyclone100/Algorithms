#include<stdio.h>

struct items{
	double price[100];
	double weight[100];
	int itemNumber[100];
};

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(double arr[],double arr2[],double arr3[],int arr4[],int n){
	int i,j,flag;
	double temp;
	for (i = 0;i<n-1;i++){
		flag = 0;
		for (j = 0;j<n-i-1;j++){
			if (arr[j] < arr[j+1]){
				swap(&arr[j],&arr[j+1]);
				swap(&arr2[j],&arr2[j+1]);
				swap(&arr3[j],&arr3[j+1]);
				swap2(&arr4[j],&arr4[j+1]);
				flag = 1;
			}
		}
		if (flag == 0){
			break;
		}
	}	
}

void knapsack(struct items it,int n,double W){
	int i;
	double profit,cap,a[100];
	profit=0;
	cap = W;

	double priceperweight[100];
	for(i=0;i<n;i++){
		priceperweight[i]=it.price[i]/it.weight[i];
		
	}
	sort(priceperweight,it.price,it.weight,it.itemNumber,n);
	double fraction[100]={0};

	printf("Items selected and their fractions:\n");
	for(i=0;i<n;i++){
		if(cap<it.weight[i]){
			fraction[i]=cap/it.weight[i];
			profit += fraction[i]*it.price[i]; 
			printf("item no %d fraction selected: %0.2lf\n",it.itemNumber[i],fraction[i]);
			break;			
		}
		else{
			fraction[i]=1;
			profit += it.price[i];
			cap -= it.weight[i];
			printf("item no %d fraction selected: %0.2lf\n",it.itemNumber[i],fraction[i]);
		}
	}

	printf("\nTotal profit:%0.2lf",profit);
}

int main(){
	struct items it;
	int n,i;
	double W;
	printf("Enter total no of items:");
	scanf("%d",&n);
	printf("Enter prices of each item:");
	for(i=0;i<n;i++){
		scanf("%lf",&it.price[i]);
		it.itemNumber[i]=i+1;
	}
	printf("Enter corresponding weights:");
	for(i=0;i<n;i++){
		scanf("%lf",&it.weight[i]);
	}
	printf("Enter capacity of knapsack:");
	scanf("%lf",&W);
	knapsack(it,n,W);
	
	return 0;
}

