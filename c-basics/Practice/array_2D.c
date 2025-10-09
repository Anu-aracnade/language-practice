#include <stdio.h>
int main()
{
    int arr[3][2];    // Input from the user for the 2D array , using nested loop 
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter your array input for arr[%d][%d]", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < 3; i++)              // Output of the loop in 2D format
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}