#include <stdio.h>
#include <math.h>   // There is use of <math.h> library in this function.
int main()
{
    int num, numDigit, lastDigit, firstDigit;

    // Take input from the user
    printf("Enter your number : ");
    scanf("%d", &num);

    // Find the number of digits
    numDigit = (int)log10(num) + 1;

    // Extract the last digit
    lastDigit = num % 10;

    // Extract the first digit
    firstDigit = num / (int)pow(10,numDigit-1);

    // Print the output 
    printf("First digit : %d\n",firstDigit);
    printf("Last digit : %d\n",lastDigit);



    return 0;
}
