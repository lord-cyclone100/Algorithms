#include<stdio.h>

struct job{
	int id;
	int profit;
	int deadline;
};

struct job jb[100];
int n,track[100];

void sort(){
	int i,j,flag;
	for(i=0;i<n-1;i++){
		flag=0;
		for(j=0;j<n-i-1;j++){
			if(jb[j].profit<jb[j+1].profit){
				struct job temp=jb[j];
				jb[j]=jb[j+1];
				jb[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0){
			break;
		}
	}
}

int max(){
	int i,maximum=0;
	for(i=0;i<n;i++){
		if(jb[i].deadline>maximum){
			maximum=jb[i].deadline;
		}
	}
	return maximum;
}

void jobSequence(){
	int i,j,maxprofit=0;
	for(i=0;i<n;i++){
		track[i]=0;
	}
	sort();
	int m=max();
	int gchart[m+1];
	for(i=0;i<n;i++){
		for(j=m;j>0;j--){
			if(track[j]==0 && j<=jb[i].deadline){
				gchart[j]=jb[i].id;
				maxprofit+=jb[i].profit;
				track[j]=1;
				break;
			}
		}
	}
	for(i=1;i<=m;i++){
		printf("Job id %d selected\n",gchart[i]);
	}
	printf("Max Profit:%d",maxprofit);
}

int main(){
	int i;
	printf("Enter the number of jobs:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter job id profit and deadline:");
		scanf("%d %d %d",&jb[i].id,&jb[i].profit,&jb[i].deadline);
	}
	jobSequence();
	return 0;
}