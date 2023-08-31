#include <stdio.h>
void main(){
    int m,n,flag=0;
    printf("enter the order: ");
    scanf("%d %d",&m,&n);
    int a[m][n];
    printf("enter the matrix: ");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==j&&a[i][j]==0){
                flag=1;
                break;
            }
            else if(i!=j&&a[i][j]!=0){
                flag=2;
            }
        }
    }
    if(flag==0){
        printf("diagonal");
        }
        else{
            printf("not diagonal");
        }
}
