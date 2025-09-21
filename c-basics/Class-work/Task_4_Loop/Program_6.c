#include <stdio.h>
#include <math.h>
int main()
{
    int n, temp, digit, count = 0;
    int sum = 0;   // for pow() function

    // Step 1: Take user input
    printf("Enter the number :");
    scanf("%d", &n);

    //
    temp = n;  // keep a copy of the input number for later use

    // Step 2: Count number of digits, and then store the counted value in count.
    while (temp > 0)
    {
        temp = temp / 10;
        count++;
    }

    // Reset the temp to the original number
    temp = n;
    
    // Step 3: Extract each digit and calculate power
    while (temp > 0)
    {
        digit = temp % 10;                   //extract last digit
        sum = sum + pow(digit, count);       //add (digit^count)
        temp = temp / 10;                    //remove last digit 
    }

    //Step 4: Compare the sum with the original number
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

/*
Taking example of input number = 153

-----------------------------------------------------------------------
The workflow behind Step 2 [Count digits] is :

Loop iterations:
 temp = 153 → temp /= 10 → temp = 15 → count = 1
 temp = 15 → temp /= 10 → temp = 1 → count = 2
 temp = 1 → temp /= 10 → temp = 0 → count = 3 ✅

 Now we know 153 has 3 digits.
 Reset temp: temp = num = 153

------------------------------------------------------------------------

 The workflow behind Step 3 [Extract digits and sum powers] is :

 Let’s go iteration by iteration:

First iteration:
digit = 153 % 10 = 3
sum = 0 + 3³ = 27
temp = 153 / 10 = 15

Second iteration:
digit = 15 % 10 = 5
sum = 27 + 5³ = 27 + 125 = 152
temp = 15 / 10 = 1

Third iteration:
digit = 1 % 10 = 1
sum = 152 + 1³ = 152 + 1 = 153
temp = 1 / 10 = 0

Loop ends because [temp = 0] ,and 
as the condition was that (temp>0).
*/