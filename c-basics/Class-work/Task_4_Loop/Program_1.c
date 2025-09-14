#include <stdio.h>
int main()
{
    int a = 1, n;
    printf("Enter your limit : ");
    scanf("%d", &n);
    
    
    // Using while loop
    printf("Using 'while' loop :\n");
    printf("The set of natural numbers upto %d are : \n", n);

    while (a <= n)
    {
        printf("%d ", a);
        a++;
    }
    
    
    //  Using for loop
    printf("\nUsing 'for' loop :\n ");
    printf("The set of natural numbers upto %d are : \n", n);
    for (a = 1; a <= n; a++)
        printf("%d ", a);

   
        // Using do-while loop
    printf("\nUsing 'do-while' loop :\n");
    a = 1;
    printf("The set of natural numbers upto %d are : \n", n);
    do
    {
        printf("%d ", a);
        a++;
    } while (a <= n);

    return 0;
}