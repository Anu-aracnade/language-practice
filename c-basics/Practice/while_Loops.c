// While Loops
#include <stdio.h>
int main()
{

    char B;
    printf("Do you want to start the printing?y/n\n");
    scanf(" %c", &B);
    if (B == 'y')
    {
        int A = 0;
        while (A <= 100)

        {
            printf("%d\n", A);
            A++;
        }
    }
    else
    {
        printf("Invalid Input\n");
    }
    return 0;
}