#include <stdio.h>
int main()
{
    int i;
    /*
              a[0] a[1] a[2] a[3]  a[4]
                ^    ^   ^     ^     ^
                |    |   |     |     |                             */            
    int a[5] = {3,   4,  56,   78,   98};  // Declare and initialize the array
    printf("The Array elements are : ");
    for (i = 0; i < 5; i++)
    {
    printf("%d ",a[i]); //Print each element of the array
    
    }

    return 0;
}

