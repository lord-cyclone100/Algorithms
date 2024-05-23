#include<stdio.h>

void maxmin_with_DAC(int a[],int i,int j,int *max,int *min){
	if(i==j){
		*max = a[i];
		*min = a[i];
	}
	else if(i+j==1){
		if(i>j){
			*max = a[i];
			*min = a[j];
		}
		else{
			*max = a[j];
			*min = a[i];
		}
	}
	else{
		int mid,max2,min2,max1,min1;
		mid = (i+j)/2;
		maxmin_with_DAC(a,i,mid,&max1,&min1);
		maxmin_with_DAC(a,mid+1,j,&max2,&min2);
		if(max1 < max2){
            		*max = max2;
        	}
	        else{
	            *max = max1;
	        }
	        if(min1 > min2){
	            *min = min2;
	        }
	        else{
	            *min = min1;
	        }
	}
}

int main(){
	
	int arr[100],n,i,max1,min1;
	printf("Enter the length of array:");
	scanf("%d",&n);
	printf("Enter array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	maxmin_with_DAC(arr,0,n-1,&max1,&min1);
	printf("Maximum element:%d",max1);
	printf("\nMinimum element:%d",min1);
	return 0;
}
