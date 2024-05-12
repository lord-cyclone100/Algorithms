#include<stdio.h>
#include<stdlib.h>

int distance[100];

void initialize(int n,int start){
	int i;
	for(i=0;i<n;i++){
		distance[i]=999;
	}
	distance[start]=0;
}

void relax(int graph[10][10],int i,int j){
	if(graph[i][j]!=0 && distance[i]+graph[i][j]<distance[j]){
		distance[j]=distance[i]+graph[i][j];
	}
}

int bellmanFord(int graph[10][10],int n,int start){
	int i,j,k;
	initialize(n,start);
	for(k=1;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				relax(graph,i,j);
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(distance[i]+graph[i][j]<distance[j]){
				return 0;
			}
		}
	}
	return 1;
}

void printResult(n){
	int i;
	printf("Source\t\tShortest distance\n");
	for(i=0;i<n;i++){
		printf("%d\t\t%d\n",i,distance[i]);
	}
}

int main(){
	int graph[10][10],i,j,n,start,b;
	FILE *fp;
	fp = fopen("ford.txt","r");
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
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	printf("Enter starting vertex:");
	scanf("%d",&start);
	
	b=bellmanFord(graph,n,start);
	if(b ==1){
		printf("Negative weight cycle detected");
	}
	else{
		printResult(n);
	}
	return 0;
}
