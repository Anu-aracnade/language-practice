#include <stdio.h>
int main()
{
    int n, i, j;
    // Taking user input
    printf("Enter the number of rows : ");
    scanf("%d", &n);

    /*Outer loop :(basically assigning how many
                  slots should be booked for
                  items to print in each row)
                  and also controlling rows*/

    for (i = n; i >= 1; i--)
    {

        for (j = i; j >= 1; j--) //inner loop: prints i stars 
        {
            printf("* ");
        }                     /*Think everything in reverse order 
                                in this code*/

        printf("\n");         // move to next line
    }

    return 0;
}

/*
⚡ Key Idea:

Outer loop controls the number of rows (going downward from n to 1).
Inner loop controls how many * get printed in that row (i stars each time).
That’s why the triangle looks inverted compared to Program 7.

*/