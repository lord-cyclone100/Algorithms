#include<stdio.h>
#include<stdlib.h>

int graph[10][10],n,pred[100],dist[100],sptset[100];

void readGraph(){
	int i,j;
	FILE *fp;
	fp = fopen("dijkstra.txt","r");
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
		dist[i]=999;
		pred[i]=0;
		sptset[i]=0;
	}
}

int extractMin(){
	int i,minindex,minvalue=999;
	for(i=0;i<n;i++){
		if(sptset[i]==0 && dist[i]<minvalue){
			minindex=i;
			minvalue=dist[i];
		}
	}
	return minindex;
}

void Dijkstra(int start){
	initialize();
	int i,w,j;
	dist[start]=0;
	for(i=0;i<n;i++){
		int u=extractMin();
		sptset[u]=1;
		for(w=0;w<n;w++){
			if(graph[u][w] != 999){
				if(sptset[w]==0 && graph[u][w]+dist[u]<dist[w]){
					dist[w]=graph[u][w]+dist[u];
					pred[w]=u;
				}
			}
		}
	}
}

void printShortestPath(){
	int i,w;
	for(i=1;i<n;i++){
		printf("S to %c:%d\n",'A'+i,dist[i]);
		w=i;
		while(w!=0){
			printf("%c<-",'A'+w);
			w=pred[w];
		}
		printf("S");
		printf("\n\n");
	}
}

int main(){
	int i;
	readGraph();
	printGraph();
	Dijkstra(0);
	printf("Shortest distances\n");
	printShortestPath();
	return 0;
}