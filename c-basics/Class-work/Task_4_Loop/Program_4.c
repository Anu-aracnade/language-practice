#include <stdio.h>

int main() {
    int n, firstDigit, lastDigit, temp;

    // Read number from user
    printf("Enter your number: ");
    scanf("%d", &n);

    // Get last digit using modulo
    lastDigit = n % 10;

    // Copy n to temp to find first digit
    temp = n;

    // Keep dividing by 10 until temp is less than 10
    while (temp >= 10) {
        temp = temp / 10;  // remove last digit
    }
    firstDigit = temp;  // temp now holds the first digit

    // Print results
    printf("First digit: %d\n", firstDigit);
    printf("Last digit: %d\n", lastDigit);

    return 0;
}
