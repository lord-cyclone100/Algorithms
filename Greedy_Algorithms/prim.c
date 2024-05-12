#include<stdio.h>
#include<stdlib.h>

void initialize(int key[],int parent[],int mstSet[],int n){
	int i;
	for(i=0;i<n;i++){
		key[i]=999;
		parent[i]=0;
		mstSet[i]=0;
	}
}
	
int extractMin(int arr[],int mstSet[],int n){
	int min=999,minIndex=0,i;
	for(i=0;i<n;i++){
		if(mstSet[i]==0 && arr[i]<min){
			minIndex = i;
			min = arr[i];
		}
	}
	return minIndex;
}

void prim(int graph[10][10],int n,int start){
	int i,key[100],parent[100],mstSet[100],w,mincost=0;
	initialize(key,parent,mstSet,n);
	key[start]=0;
	for(i=0;i<n;i++){
		int u = extractMin(key,mstSet,n);
		mstSet[u]=1;
		for(w=0;w<n;w++){
			if(graph[u][w] != 999){
				if(mstSet[w]==0 && key[w]>graph[u][w]){
					key[w]=graph[u][w];
					parent[w]=u;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		mincost += key[i];
	}
	printf("Mincost:%d",mincost);
	printf("\nEdge set:\n");
	for(i=1;i<n;i++){
		printf("%c %c\n",(char)(65+parent[i]),(char)(65+i));
	}
}

int main(){
	int graph[10][10],i,j,n,queue[100],start;
	FILE *fp = fopen("prim.txt","r");
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
			printf("%d   ",graph[i][j]);
		}
		printf("\n");
	}
	
	printf("Enter start vertex:");
	scanf("%d",&start);
	prim(graph,n,start);

	return 0;
}
