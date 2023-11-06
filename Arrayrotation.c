#include <stdio.h>
void rotate(int a[],int n,int d,int cr)
{
    int temp;
    for(int i=0;i<cr;i++)
 {
    if(d==1)
    {
      for(int j=0;j<n-1;j++)
     {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
     }
    }
    if(d==2)
    {
        for(int j=n-1;j>0;j--)
        {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
    }
 }
 for(int i=0;i<n;i++)
 printf("%d",a[i]);
}
int main()
{
    int b[20],len,count,ch;
    printf("enter array size");
    scanf("%d",&len);
    printf("enter count of rotation");
    scanf("%d",&count);
    printf("enter direction of rotation");
    scanf("%d",&ch);
    printf("enter the array elements");
    for(int i=0;i<len;i++)
    {
        scanf("%d",&b[i]);
    }
    rotate(b,len,ch,count);
}
