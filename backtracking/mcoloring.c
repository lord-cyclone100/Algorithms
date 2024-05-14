#include<stdio.h>
#include<stdlib.h>

void initialize(int x[],int n){
	int i;
	for(i=1;i<=n;i++){
		x[i]=0;
	}
}

void printResult(int x[],int n){
	int i;
	for(i=1;i<=n;i++){
		printf("%d ",x[i]);
	}
	printf("\n");
}

void nextValue(int graph[20][20],int x[],int n,int m,int k){
	do{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0){
			return;
		}
		int j;
		for(j=1;j<=n;j++){
			if(graph[k][j]==1 && x[j]==x[k]){
				break;
			}
		}
		if(j==n+1){
			return;
		}
	}
	while(1);
}

void mcoloring(int graph[20][20],int n,int k,int x[],int m){
	do{
		nextValue(graph,x,n,m,k);
		if(x[k]==0){
			return;
		}
		if(k==n){
			printResult(x,n);
		}
		else{
			mcoloring(graph,n,k+1,x,m);
		}
	}
	while(1);
}

int main(){
	int graph[20][20],n,i,j,x[100],m;
	FILE *fp;
	fp = fopen("color.txt","r");
	if(fp == NULL){
		printf("Error");
		exit(1);
	}
	fscanf(fp,"%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	fclose(fp);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter the no of colors:");
	scanf("%d",&m);
	initialize(x,n);
	mcoloring(graph,n,1,x,m);
	
	return 0;
}
