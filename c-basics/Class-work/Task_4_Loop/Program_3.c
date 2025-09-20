#include <stdio.h>
int main()
{
    int i, a, b;
    printf("Enter your number : ");
    scanf("%d", &a);
    printf("Enter the range of the multiplication table : ");
    scanf("%d", &b);
    printf("Multiplication table for %d:\n", a);
    for (i = 1; i <= b; i++)
    {
        printf("%d x %d = %d", a, i, a * i);
        printf("\n");
    }
    return 0;
}