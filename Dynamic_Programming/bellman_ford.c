#include<stdio.h>
#include<stdlib.h>

int n,graph[10][10],dist[100],pred[100];

void readGraph(){
	int i,j;
	FILE* fp;
	fp=fopen("ford.txt","r");
	if(fp==NULL){
		printf("Error");
		exit(1);
	}
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	fclose(fp);
}

void printGraph(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d   ",graph[i][j]);
		}
		printf("\n");
	}
}

void initialize(){
	int i;
	for(i=0;i<n;i++){
		dist[i]=999;
		pred[i]=-1;
	}
}

void relax(int x,int y){
	if(dist[x]+graph[x][y]<dist[y]){
		dist[y]=dist[x]+graph[x][y];
		pred[y]=x;
	}
}

int bellmanFord(int start){
	int i,j,k;
	initialize();
	dist[start]=0;
	for(k=0;k<n-1;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(graph[i][j]!=999){
					relax(i,j);
				}
			}
		}
	}
	int flag=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(dist[i]+graph[i][j]<dist[j]){
				flag=1;
			}
		}
	}
	if(flag==0){
		return 1;
	}
	else{
		return 0;
	}
}

void printResult(){
	int i,w;
	for(i=1;i<n;i++){
		printf("S to %c -> %d\n",'A'+(i-1),dist[i]);
	}
}

int main(){
	int i;
	readGraph();
	printGraph();
	int b = bellmanFord(0);
	printf("\n");
	if(b==1){
		printResult();
	}
	else{
		printf("Graph has negative weight cycle");
	}
	
	return 0;
}