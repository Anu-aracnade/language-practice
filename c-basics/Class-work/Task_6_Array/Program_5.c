/*
📝 Problem Statement :-
1. Create a railway reservation system for 100 seats:
2. Initialize all seats as available (0).
3. Allow user to book a seat (set 1).
4. Allow user to cancel a booking (set 0).
5. Allow user to display current seat status.

----------------------------------------------------------
🎯 Step 1: Understand the Problem :-
1. We have:
2. int seats[100] array.
3. Menu system (while loop + switch case).
4. Three operations:
5. Book seat
6. Cancel booking
7. Display seat status

----------------------------------------------------------
🤔 Step 2: Approach :-
1. Initialize all array elements to 0.
2. Show menu until user chooses exit.
3. For booking:
4. Ask seat number.
5. If seats[seatNo] == 0 → set to 1 (booked).
6. Else → print "Already booked".
7. For cancel:
8. If seats[seatNo] == 1 → set to 0.
9. Else → "Not booked yet".
10. For display: print all 100 seats with status.

*/

#include <stdio.h>

int main() {
    int seats[100];   // array to store seat status: 0 = available, 1 = booked
    int choice, seatNo;

    // Initialize all 100 seats to 0 (available)
    for (int i = 0; i < 100; i++) {
        seats[i] = 0;
    }

    while (1) {
        // Menu shown to the user
        printf("\n=== Railway Reservation System ===\n");
        printf("1. Book a seat\n");
        printf("2. Cancel a seat\n");
        printf("3. Display seat status (detailed)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Book a seat (set to 1)
                printf("Enter seat number (1-100): ");
                scanf("%d", &seatNo);

                // Validate seat number input (convert to 0-based index)
                if (seatNo < 1 || seatNo > 100) {
                    printf("Invalid seat number! Please enter 1 to 100.\n");
                } else if (seats[seatNo - 1] == 0) {
                    seats[seatNo - 1] = 1;  // mark booked
                    printf("Seat %d booked successfully!\n", seatNo);
                } else {
                    printf("Seat %d is already booked!\n", seatNo);
                }
                break;

            case 2: // Cancel booking (set to 0)
                printf("Enter seat number (1-100): ");
                scanf("%d", &seatNo);

                 // Validate seat number input
                if (seatNo < 1 || seatNo > 100) {
                    printf("Invalid seat number! Please enter 1 to 100.\n");
                } else if (seats[seatNo - 1] == 1) {
                    seats[seatNo - 1] = 0;  // cancel booking
                    printf("Seat %d cancelled successfully!\n", seatNo);
                } else {
                    printf("Seat %d is not booked yet!\n", seatNo);
                }
                break;

            case 3: // Display seat status (detailed only)
                printf("\nDetailed seat list:\n");
                // Print seat number as 1-based index and status as string
                for (int i = 0; i < 100; i++) {
                    printf("Seat %d: %s\n", i + 1, (seats[i] == 0) ? "Available" : "Booked");
                }
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please enter 1, 2, 3 or 4.\n");
        }
    }

    return 0;
}


