#include <stdio.h>
#include <stdlib.h>

#define MAX_SEATS 40

typedef struct {
    char name[50];
    int seatNumber;
} Passenger;

void reserveSeat(Passenger passengers[], int seatNumber) {
    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number. Please try again.\n");
        return;
    }

    if (passengers[seatNumber - 1].seatNumber != 0) {
        printf("Seat already reserved. Please choose another seat.\n");
        return;
    }

    printf("Enter passenger name: ");
    scanf("%s", passengers[seatNumber - 1].name);

    passengers[seatNumber - 1].seatNumber = seatNumber;
    printf("Seat %d reserved for %s.\n", seatNumber, passengers[seatNumber - 1].name);
}

void cancelReservation(Passenger passengers[], int seatNumber) {
    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number. Please try again.\n");
        return;
    }

    if (passengers[seatNumber - 1].seatNumber == 0) {
        printf("No reservation found for seat %d.\n", seatNumber);
        return;
    }

    printf("Cancelled reservation for seat %d (Passenger: %s).\n", seatNumber, passengers[seatNumber - 1].name);
    passengers[seatNumber - 1].seatNumber = 0;
    passengers[seatNumber - 1].name[0] = '\0';
}

void displaySeatStatus(Passenger passengers[]) {
    printf("==================================================\n");
    printf("                    Seat Status                   \n");
    printf("==================================================\n");
    printf("  Seat No.    Passenger Name\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (passengers[i].seatNumber != 0) {
            printf("    %2d         %s\n", passengers[i].seatNumber, passengers[i].name);
        }
    }
    printf("==================================================\n");
}

int main() {
    Passenger passengers[MAX_SEATS] = {0};
    int choice, seatNumber;

    while (1) {
        printf("\nBus Reservation System\n");
        printf("1. Reserve a seat\n");
        printf("2. Cancel seat reservation\n");
        printf("3. Display seat status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter seat number to reserve: ");
                scanf("%d", &seatNumber);
                reserveSeat(passengers, seatNumber);
                break;
            case 2:
                printf("Enter seat number to cancel reservation: ");
                scanf("%d", &seatNumber);
                cancelReservation(passengers, seatNumber);
                break;
            case 3:
                displaySeatStatus(passengers);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
