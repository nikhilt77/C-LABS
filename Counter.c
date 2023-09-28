#include<stdio.h>
void main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int count[n];
    for(int i=0;i<n;i++){
        count[i]=1;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count[i]++;
                count[j]=0;
            }
        }
    }
        for(int i=0;i<n;i++){
            if(count[i]>0){
              printf("%d repeats %d times",arr[i],count[i]);  
            }
            printf(/n);
        }
    }
