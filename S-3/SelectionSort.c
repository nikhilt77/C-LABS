// Selection sort
#include <stdio.h>

void main() {
    int n,temp;
    printf("Enter Array size: ");
    scanf("%d",&n);
    int A[n];
    printf("Enter Array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(A[i]>A[j]){
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
    printf("Sorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d\t",A[i]);
    }
}
