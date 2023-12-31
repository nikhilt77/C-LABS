#include<stdio.h>
void main(){
    int n,s,flag=0;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int a[n],l=0,h=n-1,m;
    printf("enter element to be searched: ");
    scanf("%d",&s);
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    while(l<=h){
        m=(l+h)/2;
        if(s==a[m]){
            flag=m;
            break;
        }
        else if(s>a[m]){
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    if(flag!=0){
        printf("Element found at %d",flag);
    }
    else{
        printf("Element not found");
    }
}
