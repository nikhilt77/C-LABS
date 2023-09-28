#include<stdio.h>
void main ()
{
  int s, n, flag = 0;
  printf ("Enter number of elements: ");
  scanf ("%d", &n);
  int a[n];
  printf ("Enter search key: ");
  scanf ("%d", &s);
  printf ("enter elements: ");
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }
  for (int i = 0; i < n; i++)
    {
      if (a[i] == s)
	{
	  flag = i;
	}
    }
  if (flag != 0)
    {
      printf ("element found at %d", flag);
    }
  else
    {
      printf ("element not found");
    }
}
