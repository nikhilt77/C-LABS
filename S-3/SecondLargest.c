#include <stdio.h>
//#include <string.h>
int main()
{
  int n;
  printf("enter the no of elements u wish to enter");
  scanf("%d",&n);
  int b[n];
  int lg,smg;
  for(int i=0;i<n;i++)
  {
      scanf("%d",&b[i]);
  }
  lg=b[0];
  smg=b[1];
  for(int i=0;i<n;i++)
  {
      if(lg<b[i])
      {
          smg=lg;
          lg=b[i];
      }
      if(smg<b[i]&&b[i]<lg)
      {
          smg=b[i];
      }
  }
  printf("largest and second largest elements are %d\t%d",lg,smg);
}
