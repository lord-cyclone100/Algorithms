#include<stdio.h>
#include<stdlib.h>

int graph[10][10],n,i,j,parent[100],k=0;

struct edge{
	int weight;
	int u;
	int v;
};

struct edge e[100];

void readGraph(){
	FILE *fp;
	fp = fopen("kuskal.txt","r");
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
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d  ",graph[i][j]);
		}
		printf("\n");
	}
}

void assignEdge(){
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			if(graph[i][j]!=999){
				e[k].weight=graph[i][j];
				e[k].u=i;
				e[k].v=j;
				k++;
			}
		}
	}
}

void sort(){
	int flag;
	for(i=0;i<k-1;i++){
		flag=0;
		for(j=0;j<k-i-1;j++){
			if(e[j].weight>e[j+1].weight){
				struct edge temp = e[j];
				e[j]=e[j+1];
				e[j+1]=temp;
				flag = 1;
			}
		}
		if(flag==0){
			break;
		}
	}
}

void makeSet(int x){
	parent[x]=-1;
}

void unionSet(int x,int y){
	parent[x]=y;
}

int findSet(int x){
	while(parent[x]>=0){
		x=parent[x];
	}
	return x;
}

void Kruskal(){
	for(i=0;i<n;i++){
		makeSet(i);
	}
	sort();
	int mincost=0;
	for(i=0;i<k;i++){
		int a=findSet(e[i].u);
		int b=findSet(e[i].v);
		if(a!=b){
			mincost+=e[i].weight;
			printf("%c    %c    %d\n",'A'+e[i].u,'A'+e[i].v,e[i].weight);
			unionSet(a,b);
		}
	}
	printf("Mincost:%d",mincost);
}

int main(){
	readGraph();
	printGraph();
	printf("\n");
	assignEdge();
	Kruskal();
	return 0;
}