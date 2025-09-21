#include <stdio.h>
#include <math.h>
int main()
{
    int n, temp, digit, count = 0;
    int sum = 0;

    // Take user input
    printf("Enter the number :");
    scanf("%d", &n);

    //
    temp = n;
    while (temp > 0)
    {
        temp = temp / 10;
        count++;
    }

    temp = n;
    while (temp > 0)
    {
        digit = temp % 10;
        sum = sum + pow(digit, count);
        temp = temp / 10;
    }

    if (sum == n)
    {
        printf("%d is an Armstrong number.\n", n);
    }
    else
    {
        printf("%d is not an Armstrong number.\n", n);
    }

    return 0;
}