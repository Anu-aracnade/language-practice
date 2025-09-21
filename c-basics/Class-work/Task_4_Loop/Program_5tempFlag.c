#include <stdio.h>
int main()
{
    // We are going to use [temp] as a flag/marker here.
    int n, i, temp=0;

    // take user input
    printf("Enter your number :");
    scanf("%d", &n);

    //Checking the value of i one by one upto n/2 ,or till a divisor is found.
    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0) // checking if the input number 'n' is divisible by any of the value of i.
        {
            temp++;  // [temp] used as a marker , whether a *divisor* was found or not !
            break;
        }
    }  // check for the value of [temp] and n(input) ,and determine whether it's a prime or not.
        if (temp == 0 && n != 1)
        {
            printf("%d is a Prime number",n);
        }
        else
        {
            printf("%d is not a Prime number",n);
        }
    

    return 0;
}

/*
✨ The core idea

For a number num to be not prime, it must have a factor (divisor) other than 1 and itself.
Now, if any divisor exists, one of the divisor in the pair will always be ≤ n/2.

😁Example 1: n = 20
Factors of 20 = 1, 2, 4, 5, 10, 20
Small factors ≤ n/2 (10) → 2, 4, 5, 10
Large factors > n/2 → 20 (but that’s the number itself, which we don’t check).

👉 So if you’ve already checked till n/2, you’ve caught all possible 
divisors except the number itself.

😁Example 2: n = 37 (prime)
Factors of 37 = 1, 37
Nothing exists between 2 and 37/2 = 18.5.
So the loop checks i = 2, 3, 4, … 18. None divide evenly → prime ✅

🤔Why not check after num/2?

Let’s suppose n = 50.
Say someone asks: “What if I try divisor 30 (> 25)?”
50 ÷ 30 is not an integer.
Any divisor greater than 25 would mean the other pair divisor
is less than 25 — and you already checked that!
So checking beyond n/2 is just wasting time ⏳.

⚡So college’s logic is basically:
👉 "Instead of checking all the way till n, 
we’ll stop at half, because if a divisor exists, 
we’d already catch its smaller partner before reaching half."

*/