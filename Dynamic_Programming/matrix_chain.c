#include <stdio.h>
#define INT_MAX 2147483647;

int p[100],cost[10][10],kvalue[10][10],n;

void initialize(){
    int i,j;
    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            if(i>=j){
                cost[i][j]=0;
                kvalue[i][j]=0;
            }
        }
    }
}

void matrixChain(){
    int i,j,k,l;
    initialize();
    for(l=2;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j=i+l-1;
            cost[i][j]=INT_MAX;
            for(k=i;k<=j;k++){
                if(cost[i][j]>cost[i][k]+cost[k+1][j]+(p[i-1]*p[k]*p[j])){
                    cost[i][j]=cost[i][k]+cost[k+1][j]+(p[i-1]*p[k]*p[j]);
                    kvalue[i][j]=k;
                }
            }
        }
    }
}

void printCostMtx(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d   ",cost[i][j]);
        }
        printf("\n");
    }
}

void printkvalues(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d   ",kvalue[i][j]);
        }
        printf("\n");
    }
}

void optimalParenthesise(int s[10][10],int i,int j){
    if (i==j){
        printf("A%d",i);
    }
    else{
        printf("(");
        optimalParenthesise(s,i,s[i][j]);
        optimalParenthesise(s,s[i][j]+1,j);
        printf(")");
    }
}

int main() {
    int i;
    printf("Enter no of matrices:");
    scanf("%d",&n);
    printf("Enter matrix orders:");
    for(i=0;i<=n;i++){
        scanf("%d",&p[i]);
    }
    matrixChain();
    printCostMtx();
	printkvalues();
    optimalParenthesise(kvalue,1,n);
    return 0;
}