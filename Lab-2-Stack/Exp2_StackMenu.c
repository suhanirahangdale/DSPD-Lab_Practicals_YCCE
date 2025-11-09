//SuhaniRahangdale-IT-B-121
/* Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX) 
        a. Push an Element on to Stack 
        b. Pop an Element from Stack 
        c. Demonstrate how Stack can be used to check Palindrome 
        d. Demonstrate Overflow and Underflow situations on Stack 
        e. Display the status of Stack 
        f. Exit 
        Support the program with appropriate functions for each of the above operations.
*/
#include <stdio.h>
#include <string.h>
#define MAX 50

int stack[MAX];
int top = -1;
void push(int x) {
    if(top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = x;
    printf("%d pushed to stack.\n", x);
}
void pop() {
    if(top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top--]);
}
void display() {
    if(top == -1) {
        printf("Stack is Empty.\n");
        return;
    }
    printf("Stack elements: ");
    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}
void checkPalindrome() {
    char str[50];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);
    top = -1; // Clear stack

    for(int i = 0; i < len; i++)
        push(str[i]);

    for(int i = 0; i < len; i++) {
        if(str[i] != stack[top--]) {
            printf("Not a Palindrome\n");
            return;
        }
    }
    printf("Palindrome\n");
}
int main() {
    int choice, value;
    while(1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. Check Palindrome\n4. Display Stack\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}