#include<stdio.h>

struct fraction{
	int id;
	double weight;
	double profit;
	double profitperweight;
};

struct fraction fk[100];
int n,W;

void sort(){
	int i,j,flag;
	for(i=0;i<n-1;i++){
		flag=0;
		for(j=0;j<n-i-1;j++){
			if(fk[j].profitperweight<fk[j+1].profitperweight){
				struct fraction temp=fk[j];
				fk[j]=fk[j+1];
				fk[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0){
			break;
		}
	}
}

void fractionKnapsack(){
	int i,maxprofit=0;
	for(i=0;i<n;i++){
		fk[i].profitperweight=fk[i].profit/fk[i].weight;
	}
	sort();
	int j;
	for(j=0;j<n;j++){
		if(W>0 && fk[j].weight<=W){
			maxprofit+=fk[j].profit;
			printf("Selected item id:%d--Fraction:1\n",fk[j].id);
			W-=fk[j].weight;
		}
		else{
			break;
		}
	}
	if(W>0){
		maxprofit+=(W/fk[j].weight)*fk[j].profit;
		printf("Selected item id:%d--Fraction:%lf\n",fk[j].id,W/fk[j].weight);
	}
	printf("Maxprofit = %d",maxprofit);
}

int main(){
	int i;
	printf("Enter no of items:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter Id Profit and Weight:");
		scanf("%d %lf %lf",&fk[i].id,&fk[i].profit,&fk[i].weight);
	}
	printf("Enter knapsack capacity:");
	scanf("%d",&W);
	
	fractionKnapsack();
	return 0;
}