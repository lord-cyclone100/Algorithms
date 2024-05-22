#include<stdio.h>
#include<stdlib.h>

int n,graph[10][10],D[10][10],p[10][10];

void readGraph(){
	int i,j;
	FILE* fp;
	fp=fopen("floyd.txt","r");
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
}

void printGraph(){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d   ",graph[i][j]);
		}
		printf("\n");
	}
}

void initialize(){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			D[i][j]=graph[i][j];
			if(graph[i][j]==0 || graph[i][j]==999){
				p[i][j]=-1;
			}
			else{
				p[i][j]=i;
			}
		}
	}
}

void floydWarshall(){
	int i,j,k;
	initialize();
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(D[i][j]>D[i][k]+D[k][j]){
					D[i][j]=D[i][k]+D[k][j];
					p[i][j]=p[k][j];
				}
			}
		}
	}
}

void printDMatrix(){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",D[i][j]);
		}
		printf("\n");
	}
}

void printPMatrix(){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
}

void shortestPath(int i,int j){
	if(i==j){
		printf("%d  ",i);
	}
	else if(p[i][j]==-1){
		printf("no path");
	}
	else{
		shortestPath(i,p[i][j]);
		printf("%d  ",j);
	}
}

void printShortestPath(){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("Shortest Path from %d to %d:%d\n",i,j,D[i][j]);
			shortestPath(i,j);
			printf("\n");
		}
		printf("\n");
	}
}

int main(){
	int i,j;
	readGraph();
	printGraph();
	floydWarshall();
	printf("\nDistance Matrix:\n");
	printDMatrix();
	printf("\nParent Matrix:\n");
	printPMatrix();
	printf("\n");
	printShortestPath();
	return 0;
}