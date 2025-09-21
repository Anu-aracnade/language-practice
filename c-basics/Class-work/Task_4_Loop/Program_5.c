#include <stdio.h>
#include <math.h> // <math.h> library is used here

int main()
{
    int n, i, isPrime = 1; // assumed prime initially

    // Input from the user
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 1)
    {
        isPrime = 0; // numbers <= 1 are not prime
    }
    else // for numbers > 1
    {
        // let's check the numbers one by one 
        for (i = 2; i <= sqrt(n); i++) // check below lines
        {
            if (n % i == 0)
            {
                isPrime = 0; // found a divisor, not prime
                break;
            }
        }
    }

    if (isPrime)
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);

    return 0;
}

/*
Better idea (optimized):

Check divisibility from 2 up to √n.
Because if n has a factor larger than √n, the corresponding
smaller factor must already have been found.
👉 Example: 36
Factors: (2×18), (3×12), (6×6) [ so, here i = 2,3,4,5,6 are taken for checking , but the loop 
                                 will end when only one case of divisor is found ,here it will be 
                                 i=2 ; and it will show outpur as ** not a prime number **]  

Notice: once we reach √36 = 6, we’ve already checked all smaller pairs.
So checking up to √n is enough

*/