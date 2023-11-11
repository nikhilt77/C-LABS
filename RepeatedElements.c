#include <stdio.h>

int main() 
{
    int n, count = 1;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[50], fr[10] = {0};  // Initialize the fr array to zero

    // Get array elements from the user
    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    // Count the frequency of each element
    for (int i = 0; i < n; i++)
    {
        count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
                fr[j] = -1;
            }
        }
        if (fr[i] != -1)
        {
            fr[i] = count;
        }
    }

    // Display repeated elements in the array
    printf("\nRepeated elements in the array are:\n");
    int repeatedFound = 0;
    for (int i = 0; i < n; i++)
    {
        if (fr[i] > 1)
        {
            printf("%d\n", a[i]);  // Include a newline character
            repeatedFound = 1;
        }
    }

    if (!repeatedFound)
    {
        printf("No repeated elements found in the array.\n");
    }

    return 0;
}
