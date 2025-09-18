#include <stdio.h>
int main() 
{
int a, b;
    // Read two integers: start and end of range
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Invalid input\n");
        return 1;
    }
// Ensure lo <= hi by swapping if necessary
    int lo = a, hi = b;
    if (lo > hi) {
        int tmp = lo;
        lo = hi;
        hi = tmp;
    }

    // Print even numbers first
    printf("Even numbers:");
    for (int i = lo; i <= hi; ++i) {
        // i % 2 == 0 => even. Using % is fine for negative numbers too.
        if (i % 2 == 0) {
            printf(" %d", i);
        }
    }
    printf("\n");

    // Print odd numbers next
    printf("Odd numbers:");
    for (int i = lo; i <= hi; ++i) {
        // Alternative test: (i & 1) != 0 also works and is fast
        if (i % 2 != 0) {
            printf(" %d", i);
        }
    }
    printf("\n");

    return 0;
}
