#include <stdio.h>

//C[i,j]=min(C[i,k]+C[k+1,j]+p[i-1]*p[k]*p[j]    i<=k<j
int table[100][100],s[100][100];

int minElement(int a[],int size){
	int small = 0,i;
	for(i=1;i<size;i++){
		if(a[i]<a[small]){
			small = i;
		}
	}
	return small+1;
}

void matrixChain(int p[],int n){
	int i,j,k,l;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i>=j){
				table[i][j]=0;
				s[i][j]=0;
			}
		}
	}
	for(l=1;l<n;l++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(j-i==l){
					int arr[l],m=0,k_values[l],q=0;
					for(k=i;k<j;k++){
						arr[m++]=table[i][k]+table[k+1][j]+p[i-1]*p[k]*p[j];
						k_values[q++]=k;
						table[i][j]=arr[(minElement(arr,sizeof(arr)/sizeof(int)))-1];
						s[i][j]=k_values[(minElement(arr,sizeof(arr)/sizeof(int)))-1];
					}
				}
			}
		}
	}
}

void printCostMtx(int n){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",table[i][j]);
		}
		printf("\n");
	}
}

void printKMtx(int n){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",s[i][j]);
		}
		printf("\n");
	}
}

void printParenthesise(int s[100][100],int i,int j){
	if(i==j){
		printf("A%d",i);
	}
	else{
		printf("(");
		printParenthesise(s,i,s[i][j]);
		printParenthesise(s,s[i][j]+1,j);
		printf(")");
	}
	
}

int main() {
    int p[100],i,n;
    printf("Enter the number of matrices:");
    scanf("%d",&n);
    printf("Enter the order array:");
    for(i=0;i<=n;i++){
    	scanf("%d",&p[i]);
	}
	matrixChain(p,n);
	printCostMtx(n);
	printf("\n");
	printKMtx(n);
	printf("\n");
	printParenthesise(s,1,n);
    return 0;
}

