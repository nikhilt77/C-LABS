#include <stdio.h>

void readMatrix(int matrix[100][100], int row, int col) {
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}

void convertToTuple(int matrix[100][100], int tuple[100][3], int row, int col) {
    int k = 1;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(matrix[i][j]!=0){
                tuple[k][0]=i;
                tuple[k][1]=j;
                tuple[k][2]=matrix[i][j];
                k++;
            }
        }
    }
    tuple[0][0]=row;
    tuple[0][1]=col;
    tuple[0][2]=k-1;
}

void printTuple(int tuple[100][3], int k) {
    printf("Rows Columns Values\n");
    for(int i=0; i<k; i++){
        for(int j=0; j<3; j++){
            printf("%d\t",tuple[i][j]);
        }
        printf("\n");
    }
}

void addTuples(int A[100][3], int B[100][3], int C[100][3]) {
    int m=1, n=1, k=1;
    for(int i=0; i<A[0][0]; i++){
        for(int j=0; j<A[0][1]; j++){
            if(A[m][0]==i && A[m][1]==j && B[n][0]==i && B[n][1]==j){
                C[k][0]=A[m][0];
                C[k][1]=A[m][1];
                C[k][2]=A[m][2]+B[n][2];
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
    C[0][0]=A[0][0];
    C[0][1]=A[0][1];
    C[0][2]=k-1;
}

int main(){
    int r1,c1,r2,c2;
    int a[100][100],b[100][100],A[100][3],B[100][3],C[100][3];
    
    printf("Enter the rows and columns of 1st matrix : ");
    scanf("%d %d",&r1,&c1);
    
    printf("Enter the rows and columns of 2nd matrix : ");
    scanf("%d %d",&r2,&c2);
   
    if (r1 != r2 || c1 != c2) {
        printf("Cannot add matrices with different dimensions.\n");
        return 0;
    }
    
    printf("Enter the elements of the 1st sparse matrix : ");
    readMatrix(a, r1, c1);
    
    printf("Enter the elements of the 2nd sparse matrix : ");
    readMatrix(b, r2, c2);
    
    convertToTuple(a, A, r1, c1);
    printf("\nTuple form of 1st matrix\n");
    printTuple(A, A[0][2] + 1);
    
    convertToTuple(b, B, r2, c2);
    printf("\nTuple form of 2nd matrix\n");
    printTuple(B, B[0][2] + 1);
    
    addTuples(A, B, C);
    printf("\nTuple form after addition\n");
    printTuple(C, C[0][2] + 1);

    return 0;
}
