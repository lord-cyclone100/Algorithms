#include<stdio.h>
#include<stdlib.h>

int parent[100];

void sort(int arr[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		int flag=0;
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag = 1;
			}
		}
		if(flag==0){
			break;
		}
	}
}

void makeSet(int n){
	parent[n]=-1;
}

void unionSet(int i,int j){
	parent[i]=j;
	return;
}

int findSet(int i){
	while(parent[i]>=0){
		i=parent[i];
	}
	return i;
}

void kruskal(int graph[10][10],int n,int k,int edge[]){
	int i,j,l,m=0,mincost=0,solution[n-1][2];
	for(i=0;i<n;i++){
		makeSet(i);
	}
		sort(edge,k);
	for(l=0;l<k;l++){
		for(i=0;i<n;i++){
			for(j=0;j<i;j++){
				if(graph[i][j]==edge[l]){
					int u=findSet(i);
					int v=findSet(j);
					if(u != v){
						mincost += edge[l];
						unionSet(u,v);
						solution[m][0]=i;
						solution[m++][1]=j;
					}
				}
			}
		}		
	}
	printf("\nMinimum cost:%d\n",mincost);
	printf("Edge Set:\n");
	for(i=0;i<n-1;i++){
		for(j=0;j<2;j++){
			printf("%c ",solution[i][j]+'A');
		}
		printf("\n");
	}
}

int main(){
	int graph[10][10],i,j,k=0,n,edge[100];
	FILE *fp = fopen("kuskal.txt","r");
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
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(graph[i][j]!=999){
				edge[k++]=graph[i][j];
			}
		}
	}
	kruskal(graph,n,k,edge);
	return 0;
}
