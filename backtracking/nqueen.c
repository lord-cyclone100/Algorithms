#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int x[100];

void printSolution(int n){
	int i,j,board[n+1][n+1];
	for(i=1;i<n+1;i++){
		for(j=1;j<n+1;j++){
			board[i][j]=0;
		}
	}
	for(i=1;i<=n;i++){
		board[i][x[i]]=1;
	}
	for(i=1;i<n+1;i++){
		for(j=1;j<n+1;j++){
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}

//bool place(int k,int i){
//	int j;
//	for(j=1;j<=k-1;j++){
//		if(x[j]==i || abs(j-k)==abs(x[j]-i)){
//			return false;
//		}
//	}
//	return true;
//}



//void nQueen(int k,int n){
//	int i;
//	for(i=1;i<=n;i++){
//		if(place(k,i)){
//			x[k]=i;
//			if(k==n){
//				printSolution(n);
//				printf("\n");
//			}
//			else{
//				nQueen(k+1,n);
//			}
//		}
//	}
//}


bool place(int k,int i,int* x){
	int j;
	for(j=1;j<=k-1;j++){
		if(x[j]==i || abs(j-k)==abs(x[j]-i)){
			return false;
		}
	}
	return true;
}

void nQueen(int k,int n){
	int i,j;
	int* x;
	x = (int *)malloc(n*sizeof(int));
	for(i=1;i<=n;i++){
		if(place(k,i,x)){
			x[k]=i;
			if(k==n){
				for(j=0;j<=n;j++){
					printf("%d ",x[j]);
				}
				printf("\n");
			}
			else{
				nQueen(k+1,n);
			}
		}
	}
}

int main(){
	int n;
	printf("Enter the number of queens:");
	scanf("%d",&n);
	
	nQueen(1,n);
	
	return 0;
}
