
#include <stdio.h>

int main() {
    int n;

    // Step 1: Take array size from user
    printf("Enter the size of array: ");
    scanf("%d", &n);

    // Edge case: If less than 2 elements, second largest not possible
    if (n < 2) {
        printf("Array must have at least 2 elements.\n");
        return 0;  // end program
    }

    int arr[n];  // declare array

    // Step 2: Input array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 3: Initialize largest and second largest (doing this step to create a basis of comparision with the the latter codes.)
    int largest, second_largest;

    if (arr[0] > arr[1]) {
        largest = arr[0];                
        second_largest = arr[1];
    } else {
        largest = arr[1];
        second_largest = arr[0];               
    }

    // Step 4: Traverse the array from index 2
    for (int i = 2; i < n; i++) {                       /*👉 If we find a number 'bigger' than 'current largest':-
                                                
                                                          The 'old largest' becomes the 'new secondLargest'.
                                                          Update 'largest' with this 'new number'.
                                                                                                    */
        if (arr[i] > largest) {
            // Current element is greater than largest
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
            // Current element is in between largest and second largest
            second_largest = arr[i];
        }
    }

    // Step 5: Output result
    printf("Second largest element is: %d\n", second_largest);

    return 0;
}

/*


*/