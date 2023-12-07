#include <stdio.h>

int main(){
    int r1,c1,r2,c2,i,j,k;
    int a[100][100],b[100][100],A[100][3],B[100][3],C[100][3];
    
    printf("Enter the rows and columns of 1st matrix : ");
    scanf("%d %d",&r1,&c1);
    
    printf("Enter the rows and columns of 2nd matrix : ");
    scanf("%d %d",&r2,&c2);
   
    printf("Enter the elements of the 1st sparse matrix : ");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    
    printf("Enter the elements of the 2nd sparse matrix : ");
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    
    k=1;
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            if(a[i][j]!=0){
                A[k][0]=i;
                A[k][1]=j;
                A[k][2]=a[i][j];
                k++;
            }
        }
    }
    A[0][0]=r1;
    A[0][1]=c1;
    A[0][2]=k-1;
    
    printf("\nTuple form of 1st matrix\n");
    printf("Rows Columns Values\n");
    for(i=0;i<k;i++){
        for(j=0;j<3;j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    
    
    k=1;
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            if(b[i][j]!=0){
                B[k][0]=i;
                B[k][1]=j;
                B[k][2]=b[i][j];
                k++;
            }
        }
    }
    B[0][0]=r2;
    B[0][1]=c2;
    B[0][2]=k-1;
    
    printf("\nTuple form of 2nd matrix\n");
    printf("Rows Columns Values\n");
    for(i=0;i<k;i++){
        for(j=0;j<3;j++){
            printf("%d\t",B[i][j]);
        }
        printf("\n");
    }
    
    int m=1,n=1;
    k=1;
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            if(A[m][0]==i && A[m][1]==j && B[n][0]==i && B[n][1]==j){
                C[k][0]=A[m][0];
                C[k][1]=A[m][1];
                C[k][2]=A[m][2]+B[m][2];
                m++;
                n++;
                k++;
            }
            
            else if(A[m][0]==i && A[m][1]==j){
                C[k][0]=A[m][0];
                C[k][1]=A[m][1];
                C[k][2]=A[m][2];
                m++;             
                k++; 
            }
            
            else if(B[m][0]==i && B[m][1]==j){
                C[k][0]=B[n][0];
                C[k][1]=B[n][1];
                C[k][2]=B[n][2];
                n++;             
                k++;
            } 
        }
    }
    
    C[0][0]=r1;
    C[0][1]=c1;
    C[0][2]=k-1;
    
    printf("\nTuple form after addition\n");
    printf("Rows Columns Values\n");
    for(i=0;i<k;i++){
        for(j=0;j<3;j++){
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }

    
return 0;

}
