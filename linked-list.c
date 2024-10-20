#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node *next; // Pointer to the next node
};

// Global pointer to the start of the linked list
struct node *start = NULL;

// Function prototypes
void create();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtMiddle(int data, int position);
void display();

int main() {
    int choice, data, position;

    do {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Middle\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                printf("Enter the element to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter the element to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                printf("Enter the element to insert in the middle: ");
                scanf("%d", &data);
                printf("Enter the position (starting from 1): ");
                scanf("%d", &position);
                insertAtMiddle(data, position);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to create the linked list
void create() {
    int n;
    char ch;

    do {
        printf("Enter the element: ");
        scanf("%d", &n);
        
        // Create a new node
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = n;
        newNode->next = NULL;

        // If the list is empty, set start to the new node
        if (start == NULL) {
            start = newNode;
        } else {
            // Traverse to the end of the list and add the new node
            struct node *temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode; // Link the new node
        }

        printf("Want to continue adding elements? (Press 'Y' or 'y'): ");
        scanf(" %c", &ch); // Space before %c to consume any newline character
    } while (ch == 'Y' || ch == 'y');
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = start; // Link the new node to the current start
    start = newNode; // Update start to the new node
    printf("Inserted %d at the beginning of the list.\n", data);
}

// Function to insert a node at the end of the list
void insertAtEnd(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL; // New node will be the last node

    if (start == NULL) {
        start = newNode; // If the list is empty, set start to the new node
    } else {
        struct node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Link the new node
    }
    printf("Inserted %d at the end of the list.\n", data);
}

// Function to insert a node at a specific position in the list
void insertAtMiddle(int data, int position) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (position < 1) {
        printf("Position should be 1 or greater.\n");
        free(newNode); // Free the allocated memory
        return;
    }

    if (position == 1) {
        newNode->next = start; // Insert at the beginning
        start = newNode;
        printf("Inserted %d at position %d (beginning).\n", data, position);
        return;
    }

    struct node *temp = start;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next; // Traverse to the position
    }

    if (temp == NULL) {
        printf("Position is out of bounds. Inserting at the end instead.\n");
        free(newNode); // Free the allocated memory
        insertAtEnd(data); // Insert at the end if position is out of bounds
    } else {
        newNode->next = temp->next; // Link the new node
        temp->next = newNode; // Insert the new node
        printf("Inserted %d at position %d.\n", data, position);
    }
}

// Function to display the linked list
void display() {
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *temp = start;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); // Indicate the end of the list
}