#include<stdio.h>
#include<stdlib.h>

int stack[100],top=-1;

void push(int value){
	stack[++top]=value;
}

void pop(){
	top--;
}

int isEmpty(){
	if(top==-1){
		return 1;
	}
	return 0;	
}

int peek(){
	return stack[top];
}

void dfs(int graph[10][10],int n,int start){
	int visited[100]={0};
	int current,i;
	visited[start]=1;
	push(start);
	while(!isEmpty()){
		current=peek();
		pop();
		printf("%d ",current);
		for(i=0;i<n;i++){
			if(graph[current][i]==1 && visited[i]==0){
				visited[i]=1;
				push(i);
			}
		}
	}
}

int main(){
	int graph[10][10],n,i,j,v;
	FILE *fp;
	fp=fopen("graph.txt","r");
	if(fp==NULL){
		printf("\Error");
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
	printf("Enter start vertex:");
	scanf("%d",&v);
	printf("\nDFS traversal:");
	dfs(graph,n,v);
	return 0;
}
