#include <stdio.h>
int a[20],n;
void insert(int m)
{
    int c[20],k=0,pos=0;
    for(int i=0;i<n;i++)
    {
       if(a[i]<m)
       {
           pos=i;
           break;
       }
    }
      
    for(int i=n-1;i>=pos;i--)
    {
        a[i+1]=a[i];
    }
    a[pos]=m;
    for(int i=0;i<=n;i++)
    printf("%d ",a[i]);
}
int main()
{
    int temp,num;
    printf("enter the no of students");
    scanf("%d",&n);
    printf("enter the marks ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the number to be inserted");
    scanf("%d",&num);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    insert(num);
}
