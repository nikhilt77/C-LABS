#include <stdio.h>
void main() 
{
int m,n;
printf("enter the rows and columns");
scanf("%d %d",&m,&n);
int a[m][n];
printf("enter the matrix");
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    scanf("%d",&a[i][j]);
}
printf("transporse of a mtrix");
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        printf("%d",a[j][i]);
    }
    printf("\n");
}
}
