#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int distance[100];
bool spt[100];

int extractMin(bool spt[],int dist[],int n){
	int min = 999,i,minIndex;
	for(i=1;i<=n;i++){
		if(spt[i]==false && dist[i]<=min){
			min=dist[i];
			minIndex=i;
		}
	}
	return minIndex;
}

void printResult(int dist[],int n){
	int i;
	printf("Vertex		Shortest path from source\n");
	for(i=1;i<=n;i++){
		printf("%d\t\t%d\n",i,dist[i]);
	}
}

void Dijkstra(int graph[10][10],int n){
	int i,s,count;
	printf("Enter source vertex:");
	scanf("%d",&s);
	for(i=1;i<=n;i++){
		distance[i]=999;
		spt[i]=false;
	}
	distance[s]=0;
	count=1;
	while(count<n){
		int u = extractMin(spt,distance,n);
		spt[u]=true;
		for(i=1;i<=n;i++){
			if(spt[i]==false && graph[u][i]!=0 && distance[i]>distance[u]+graph[u][i]){
				distance[i]=distance[u]+graph[u][i];
			}
		}
		count++;
	}
	printResult(distance,n);
}



int main(){
	int n,graph[10][10],i,j,s;
	FILE *fp;
	fp = fopen("dijkstra.txt","r");
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
			printf("%d  ",graph[i][j]);
		}
		printf("\n");
	}
//	printf("Select a source:");
//	scanf("%d",&s);
	Dijkstra(graph,n);
	
	
	
	return 0;
}
