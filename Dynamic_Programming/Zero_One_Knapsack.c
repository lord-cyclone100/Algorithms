#include<stdio.h>

//table[i][j]=max(table[i-1][j],table[i-1][j-weight[i]]+profit[i])

int profit[100],weight[100],table[100][100],n;

int maxItem(int x,int y){
	return x>y ?x:y;
}

void zeroOneKnapsack(int W){
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=W;j++){
			if(i==0 || j==0){
				table[i][j]=0;
			}
		}
	}
	for(i=1;i<=n;i++){
        for(j=1;j<=W;j++){
            if(weight[i] <= j){
                table[i][j]=maxItem(table[i-1][j],(table[i-1][j-weight[i]]+profit[i]));
            }
			else{
                table[i][j] = table[i-1][j];
            }
        }
    }
	for(i=0;i<=n;i++){
		for(j=0;j<=W;j++){
			printf("%d ",table[i][j]);
		}
		printf("\n");
	}
	printf("Maximum profit:%d\n",table[n][W]);
}

void printItems(int W){
	int i,maxpro = table[n][W],wt = W;
	printf("Selected items:");
	for(i=n;i>=1;i--){
		if(maxpro == table[i-1][wt]){
			continue;
		}
		else{
			printf("%d ",i);
			wt -= weight[i];
			maxpro -= profit[i];
			if(maxpro == 0){
				break;
			}
		}
	}
}

int main(){
	int W,i;
	printf("Enter the no of items:");
	scanf("%d",&n);
	printf("Enter the profits:");
	for(i=1;i<=n;i++){
		scanf("%d",&profit[i]);
	}

	printf("Enter the weights:");
	for(i=1;i<=n;i++){
		scanf("%d",&weight[i]);
	}

	printf("Enter knapsack capacity:");
	scanf("%d",&W);
	zeroOneKnapsack(W);
	printItems(W);
	return 0;
}
