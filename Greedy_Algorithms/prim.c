#include<stdio.h>
#include<stdlib.h>

int graph[10][10],n,parent[100],key[100],mstset[100],start;

void readGraph(){
	int i,j;
	FILE *fp;
	fp = fopen("prim.txt","r");
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
			printf("%d  ",graph[i][j]);
		}
		printf("\n");
	}
}

void initialize(){
	int i;
	for(i=0;i<n;i++){
		key[i]=999;
		parent[i]=0;
		mstset[i]=0;
	}
}

int extractMin(){
	int i;
	int minindex=-1,minvalue=999;
	for(i=0;i<n;i++){
		if(mstset[i]==0 && key[i]<minvalue){
			minindex=i;
			minvalue=key[i];
		}
	}
	return minindex;
}

void Prim(){
	int i,j;
	initialize();
	key[start]=0;
	for(i=0;i<n;i++){
		int u=extractMin();
		//printf("\n%d",u);
		mstset[u]=1;
		for(j=0;j<n;j++){
			if(graph[u][j]!=999){
				if(mstset[j] == 0 && graph[u][j]<key[j]){
					key[j]=graph[u][j];
					parent[j]=u;
				}
			}
		}
	}
}

void printMST(){
	int i,mincost=key[0];
	for(i=0;i<n;i++){
		if(i==start){
			continue;
		}
		else{
			mincost+=key[i];
			printf("%c    %c    %d\n",'A'+parent[i],'A'+i,graph[i][parent[i]]);
		}
	}
	printf("Minimum cost:%d",mincost);
}

int main(){
	readGraph();
	printGraph();
	int start;
	printf("Enter start vertex:");
	scanf("%d",&start);
	Prim(start);
	printMST();
	return 0;
}