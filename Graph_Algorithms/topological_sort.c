#include<stdio.h>
#include<stdlib.h>

int queue[100],front=-1,rear=-1;

void enqueue(int value){
	if(front==-1 && rear==-1){
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

int isEmpty(){
	if(front > rear){
		return 1;
	}
	return 0;
}

void topSort(int graph[10][10],int n){
	int indegree[100] = {0};
	int DAG[100] = {0};
	int i,j,element;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(graph[j][i]==1){
				indegree[i]++;
			}
		}
	}
	for(i=0;i<n;i++){
		if(indegree[i]==0){
			enqueue(i);
		}
	}
	while(!isEmpty()){
		element = peek();
		dequeue();
		DAG[element]=1;
		printf("%d ",element);
		for(j=0;j<n;j++){
			if(graph[element][j]==1){
				indegree[j]--;
				if(indegree[j]==0){
					enqueue(j);
				}
			}
		}
	}
	for(i=0;i<n;i++){
		if(DAG[i]==0){
			printf("\nThe graph contains a cycle. Topological sort not possible");
			return;
		}
	}
	printf("\nTopological sort possible");
	return;
}

int main(){
	FILE *fp;
	int n,i,j,graph[10][10],check;
	
	fp = fopen("top.txt","r");
	if(fp == NULL){
		printf("\nError");
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
	printf("Linear ordering:");
	topSort(graph,n);
	
	
	return 0;
}
