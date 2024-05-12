#include<stdio.h>
#include<stdlib.h>

int queue[100],front=-1,rear=-1;

int isEmpty(){
	if(front>rear){
		return 1;
	}
	return 0;
}

void enqueue(int value){
	if(front==-1&&rear==-1){
		front=0;
	}
	queue[++rear]=value;
}

void dequeue(){
	front++;
}

int peek(){
	return queue[front];
}

void bfs(int graph[10][10],int n,int start){
	int visited[100]={0};
	int current,i;
	visited[start]=1;
	enqueue(start);
	while(!isEmpty()){
		current=peek();
		printf("%d ",current);
		dequeue();
		for(i=0;i<n;i++){
			if (graph[current][i]==1 && visited[i]!=1){
				enqueue(i);
				visited[i]=1;
			}
		}
	}
}


int main(){
	FILE *fp;
	fp=fopen("../g.txt","r");
	if(fp==NULL){
		printf("\nError");
		exit(1);
	}
	
	int i,j,graph[10][10],n,v;
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
	printf("Enter start vertex:");
	scanf("%d",&v);
	printf("\nBFS Traversal: ");
	bfs(graph,n,v);
	
	return 0;
	
}
