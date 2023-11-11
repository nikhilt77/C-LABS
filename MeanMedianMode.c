
#include <stdio.h>

void mean(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    printf("mean=%d", sum / n);
}

void median(int a[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if(a[j]>a[j+1])
            {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            }
        }
    }
    if (n % 2 != 0)
    {
        printf("median is %d", a[n / 2]);
    }
    else
        printf("median is %d", (a[n / 2] + a[n / 2 - 1]) / 2);
}

void mode(int a[], int n)
{
    int max = 0, k = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
                cnt++;
        }
        if (cnt > max)
        {
            max = cnt;
            k = i;
        }
    }
    printf("mode is %d", a[k]);
}

int main()
{
    int len, b[20];
    printf("enter the array size");
    scanf("%d", &len);
    printf("enter the array elements");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &b[i]);
    }
    mean(b, len);
    median(b, len);
    mode(b, len);
    return 0;
}
