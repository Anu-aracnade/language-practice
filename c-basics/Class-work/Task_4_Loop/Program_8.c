// Floyd’s Triangle using for loop.
#include <stdio.h>
int main()
{
    int n, i, j;
    int num = 1;
    
    //Taking input from the user
    printf("Enter the number of rows : ");
    scanf("%d", &n);

     // Outer loop → controls rows
    for (i = 1; i <= n; i++)
    {
        // Inner loop → controls how many numbers per row
        for (j = 1; j <= i; j++)       
        {
            printf("%d ", num);    // print current num
            num++;                 /* then increase num
                                    move to the next number*/
        }

        printf("\n");              // new line after each row
    }

    return 0;
}

/*
Workflow with Example (n = 4)

👉 Initial: num = 1

Row 1 (i = 1)
 Inner loop runs j = 1 to 1
 Print num = 1
 Increment → num = 2
 End row → Output: 1

Row 2 (i = 2)
 Inner loop runs j = 1 to 2
   Print num = 2, then num = 3
   Increment after each print → num = 4

 End row → Output: 1
                   2 3

Row 3 (i = 3)
 and so on.....
 
⚡ Key Idea:
num acts like a running counter.
It never *resets* inside the loops.
It keeps increasing across rows, which is why
Floyd’s Triangle has a continuous sequence of numbers. 

*/