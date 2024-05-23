#include <stdio.h>

int arr[100],unsorted[100],n,i;

void sort(){
    int i,j,flag,temp;
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}

int binarySearch(int key,int low,int high){
    if(high>=low){
        int mid = low+(high-low)/2;
        if(key==arr[mid]){
            return mid;
        }
        else if(key>arr[mid]){
            return binarySearch(key,mid+1,high);
        }
        else if(key<arr[mid]){
            return binarySearch(key,low,mid-1);
        }
    }
    return -1;
}

int findIndex(int key){
    int i;
    for(i=0;i<n;i++){
        if(unsorted[i]==key){
            return i;
        }
    }
}

int main() {
    int key;
    printf("Enter length of array:");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        unsorted[i]=arr[i];
    }
    sort();
    printf("Enter key value to search:");
    scanf("%d",&key);
    int b=binarySearch(key,0,n);
    int f=findIndex(key);
    if (b==-1){
        printf("%d not found",key);
    }
    else{
        printf("%d found at index %d",key,f);
    }
    return 0;
}