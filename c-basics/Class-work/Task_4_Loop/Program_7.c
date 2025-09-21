// Classic example using nested loops
#include <stdio.h>
int main()
{
    int n,i,j;
    
    // Step 1: Take input for number of rows
    printf("Enter the number of rows : ");
    scanf("%d", &n);

    //Step 2: Outer loop for controlling rows
    for(i=1;i<=n; i++)
    {
        //Step 3: Inner loop for printing stars
        for (j=1;j<=i; j++)
        {printf("* ");}

        // Step 4: Move to next line after each row
        printf("\n"); // This is part of the *outer* loop controlling
    }

    return 0;
}

/*

⚙️ Thinking Process :

How many rows? → user gives input (say n = 5).

# Outer loop → controls the rows.
   Row 1 → 1 star
   Row 2 → 2 stars
   Row 3 → 3 stars
   …
   Row i → i stars.

# Inner loop → prints stars in each row.
   For row i, inner loop runs i times.

After printing stars of one row, we print a newline.

*/