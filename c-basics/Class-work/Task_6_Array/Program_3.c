#include <stdio.h>

int main() {
    int arr[100];   // large enough size to handle insertions
    int n, pos, elem;

    // Step 1: Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Step 2: Input array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 3: Input element and position
    printf("Enter the element to insert: ");
    scanf("%d", &elem);

    printf("Enter the position (0 to %d): ", n); // ***** look here it is ''n''*****
    scanf("%d", &pos);

    // Step 4: Check for valid position
    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return 0;
    }

    // Step 5: Shift elements to the right                   
    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    // Step 6: Insert the new element
    arr[pos] = elem;
    n++; // array size increases

    // Step 7: Print updated array
    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


/*
🔄 Example :-
Array before insertion:
arr = [10, 20, 30, 40], n = 4

-------------------------------------------
We want to insert 99 at position 2 (0-based indexing → after 20).
                                             ----
Step 5: The Shifting Loop                       |
for (int i = n - 1; i >= pos; i--) {            |------ ( The main code)
    arr[i + 1] = arr[i];                        |  
}                                            ----

👉 n - 1 = 3 → loop starts at index 3 (last element).
👉 Loop condition: keep going until index = pos.
--------------------------------------------
Iteration 1 (i = 3):
arr[4] = arr[3]  →  arr[4] = 40
Now array looks like: [10, 20, 30, 40, 40]

👉 last element shifted to the right.
--------------------------------------------
Iteration 2 (i = 2):
arr[3] = arr[2]  →  arr[3] = 30
Now array: [10, 20, 30, 30, 40]

👉 the old 30 moves right, making a gap at index 2.
---------------------------------------------
Step 6: Insert New Element
arr[pos] = elem;   // arr[2] = 99  and ,pos = 2 here


Now array: [10, 20, 99, 30, 40]

👉 Element 99 is safely placed at position 2.
👉 All elements after it are preserved, just shifted.
----------------------------------------------
Final State
Array after insertion = [10, 20, 99, 30, 40]
------------------------------------------------
🔑 Core Idea :-

)Start from the back → avoid overwriting values before shifting them.
)Shift right until the target position.
)Insert new element at that empty spot.
)That’s it 🚀 — the shifting loop just opens up a "hole" at the required position.

--------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------
🔄 Without {n++} Example :-

Original:

arr = [10, 20, 30, 40], n = 4
Insert 99 at pos=2


After shifting and inserting → [10, 20, 99, 30, 40]
--------------------------------------------------------
👉 But if you don’t do {n++}, the program will still print only /n=4/ elements.
Output:

10 20 99 30   (oops! 40 is missed)
*/