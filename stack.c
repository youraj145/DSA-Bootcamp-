#include <stdio.h>
#include <stdlib.h> // Include for system function

#define MAXSIZE 10  // Corrected the definition of MAXSIZE
int stack[MAXSIZE]; // Added missing semicolon
int top = -1;

// Function prototypes
void push();
void pop();
void display();
void printStackArray(); // New function prototype

int main() { // Added return type for main and corrected its definition
    int choice; // Changed to an integer variable
    system("cls"); // Clear the console screen (Windows)

    do { // Changed 'Do' to 'do'
        printf("\n1. Push\n2. Pop\n3. Display\n4. Print Stack Array\n5. Exit\n"); // Added option to print stack array
        printf("Enter your choice: ");
        
        scanf("%d", &choice); // Corrected scanf to read an integer

        switch(choice) { // Added switch statement
            case 1:
                push(); break;
            case 2:
                pop(); break;
            case 3:
                display(); break; // Added break statement
            case 4:
                printStackArray(); break; // New case to print stack array
            case 5:
                break; // Added case for exit
            default:
                printf("Invalid choice\n"); // Added default case for invalid input
        }
    } while(choice != 5); // Corrected the loop condition

    return 0; // Added return statement for main
}

void push() { // Added return type for push function
    int n;
    if (top == MAXSIZE - 1) {
        printf("Stack Overflow\n");
        // Check if the stack is full (overflow condition)
    } else {
        printf("Enter an element: "); // Added colon for clarity
        scanf("%d", &n);
        top++; // Increment top index
        stack[top] = n; // Store the element in the stack
    }
}

void pop() { // Added pop function definition
    if (top == -1) {
        printf("Stack Underflow\n"); // Check if the stack is empty
    } else {
        printf("Popped element: %d\n", stack[top]); // Display the popped element
        top--; // Decrement top index
    }
}

void display() { // Added display function definition
    if (top == -1) {
        printf("Stack is empty\n"); // Check if the stack is empty
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]); // Display elements from top to bottom
        }
        printf("\n");
    }
}

void printStackArray() { // New function to print the stack array
    printf("Stack Array: ");
    for (int i = 0; i < MAXSIZE; i++) {
        if (i <= top) {
            printf("%d ", stack[i]); // Print elements in the stack
        } else {
            printf("X "); // Indicate empty slots
        }
    }
    printf("\n");
}