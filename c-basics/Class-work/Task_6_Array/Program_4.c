#include <stdio.h>
int main()
{
    int arr[100];
    int n, pos;

    // Step 1: Input array size
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    // Step 2: Input array elements
    printf("Enter %d elements :", n);
    for (int i = 0; i < n; i++)              // 'i' in this whole code is used as a 'loop counter'
    {
        scanf("%d", &arr[i]);
    }
    // Step 3: Input position
    printf("Enter position to delete (0 to %d): ", n - 1); //****look here it is ''n-1'' because 'indexing' is one less*****
    scanf("%d", &pos);

    // Step 4: Check valid position
    if (pos < 0 || pos >= n)
    {
        printf("Invalid position!\n");
        return 0;
    }

    // Step 5: Shift elements to the 'left' from the 'pos' index
    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    // Step 6: Decrease array size
    n--;

    printf("The array after deletion : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}