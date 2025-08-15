#include <stdio.h>
int main()
{
    int A;
    printf("Enter your Age\n");
    scanf("%d", &A);
    if (A < 18)
    {
        printf("You are eligible for the exam");
    }
    else if (A >= 18 && A <= 30)
    {
        printf("You have to register yourself first");
    }
    else
    {
        printf("You are not eligible for the exam");
    }
    return 0;
}