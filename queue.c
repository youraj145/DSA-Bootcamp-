#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10  // Maximum size of the queue

int Queue[MAXSIZE];
int front = 0;
int rear = -1;

// Function prototypes
void Insert();
void Delete();
void Display();

int main() {
    int choice; // Variable to store user choice

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user choice

        switch (choice) {
            case 1:
                Insert(); 
                break;
            case 2:
                Delete(); 
                break;
            case 3:
                Display(); 
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0; // Return statement for main
}

void Insert() {
    int n;
    if (rear == MAXSIZE - 1) {
        printf("Queue overflow. Cannot insert %d\n", n);
    } else {
        printf("Enter the element to insert: ");
        scanf("%d", &n);
        rear++; // Increment the rear index
        Queue[rear] = n; // Add the element to the queue
        printf("Inserted %d\n", n); // Confirm insertion
    }
}

void Delete() {
    if (front > rear) {
        printf("Queue underflow. No elements to delete.\n");
    } else {
        printf("Deleted element: %d\n", Queue[front]); // Display the deleted element
        front++; // Increment the front index
    }
}

void Display() {
    if (front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Queue[i]); // Display elements from front to rear
        }
        printf("\n");
    }
}