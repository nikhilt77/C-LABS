#include <stdio.h>

int main()
{
    int n1,n2,a,b,c;
    printf("enter the two numbers");
    scanf("%d %d",&n1,&n2);
    if(n2>n1)
    {
        a=n2;
        b=n1;
    }
    else
    {
        a=n1;
        b=n2;
    }
    while(a>0)
    {
        c=a%b;
        a=b;
        b=c;
        if(c==0)
        break;
    }
    printf("hcf is %d",a);
}
