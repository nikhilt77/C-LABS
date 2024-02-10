// Selection sort
#include<stdio.h>

void main(){
    int n,min,temp;
    
    printf("Enter elements:");
    scanf("%d",&n);
    int A[n];
    printf("Enter elements of A:");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(A[min]>A[j]){
                min=j;
            }
        }
        if(min!=i){
            int temp;
            temp=A[i];
            A[i]=A[min];
            A[min]=temp;
        }
    }
    printf("Sorted array:");
    for(int i=0;i<n;i++){
        printf("%d\t",A[i]);
    }
}
