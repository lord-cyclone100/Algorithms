#include<iostream>
using namespace std;

bool isSafe(int graph[10][10],int n,int k,int colour[10],int c){
    for(int i=0;i<n;i++){
        if(graph[k][i]==1 && colour[i]==c){
            return false;
        }
    }
    return true;
}

void mcoloring(int graph[10][10],int n,int k,int colour[10],int m){
    if(k==n){
        for(int i=0;i<n;i++){
            cout<<colour[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=m;i++){
        if(isSafe(graph,n,k,colour,i)){
            colour[k]=i;
            mcoloring(graph,n,k+1,colour,m);
            colour[k]=0;
        }
    }
}

int main(){
    int graph[10][10],n,m,colour[10];
    FILE *fp;
    fp=fopen("graph.txt","r");
    if(fp==NULL){
        cout<<"error";
        return 0;
    }
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(fp,"%d",&graph[i][j]);
        }
    }
    fclose(fp);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter the number of colors: ";
    cin>>m;
    for(int i=0;i<n;i++){
        colour[i]=0;
    }
    mcoloring(graph,n,0,colour,m);
    return 0;
}