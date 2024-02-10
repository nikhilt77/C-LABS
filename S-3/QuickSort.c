#include<stdio.h>

int Partition(int A[],int lb,int ub){
    int start=lb;
    int end=ub;
    int pivot=A[lb];
    while(start<=end){
        while(A[start]<=pivot){
           start++; 
        }
        while(A[end]>pivot){
            end--;
        }
        if(start<end){
          int temp=A[start];
          A[start]=A[end];
          A[end]=temp;
        }
    }
          int temp=A[lb];
          A[lb]=A[end];
          A[end]=temp;
          return end;
}

void QuickSort(int A[],int lb,int ub){
    if(lb<ub){
        int ref=Partition(A,lb,ub);
        QuickSort(A,lb,ref-1);
        QuickSort(A,ref+1,ub);
    }
}
void main(){
    int n;
    printf("Enter NUmber:");
    scanf("%d",&n);
    int A[n];
    printf("Enter Array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    QuickSort(A,0,n-1);
    printf("Sorted Array:");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}
