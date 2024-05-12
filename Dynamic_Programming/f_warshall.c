#include<stdio.h>
#include<stdlib.h>

//graph{k}[i][j]=min(graph{i-1}[i][j],graph{k-1}[i][k]+graph{k-1}[k][j])

int min(int x,int y){
	return x<y ? x:y;
}

void floydWarshall(int graph[10][10],int n){
	int i,j,k;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i==k || j==k){
					continue;
				}
				else{
					graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
				}
			}
		}
	}
}

void printResult(int graph[10][10],int n){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("Shortest path from %d to %d: %d\n",i,j,graph[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int n,graph[10][10],i,j;
	FILE *fp;
	fp = fopen("fw.txt","r");
	if(fp==NULL){
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
			printf("%d   ",graph[i][j]);
		}
		printf("\n");
	}
	floydWarshall(graph,n);
	printResult(graph,n);
	
	
	
	return 0;
}
