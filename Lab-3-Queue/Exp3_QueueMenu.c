//suhani Rahangdale B-121
/*Design, Develop and Implement a menu driven Program in C for the following operations on QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to QUEUE
b. Delete an Element from QUEUE
c. Demonstrate Overflow and Underflow situations on QUEUE
d. Display the status of QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations
*/

#include <stdio.h>
#define MAX 5
char queue[MAX];
int front = -1, rear = -1;
void insert(char c) {
    if (rear == MAX - 1) printf("Queue Overflow!\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = c;
    }
}
void delete() {
    if (front == -1 || front > rear) printf("Queue Underflow!\n");
    else printf("Deleted: %c\n", queue[front++]);
}
void display() {
    if (front == -1 || front > rear) printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) printf("%c ", queue[i]);
        printf("\n");
    }
}
int main() {
    int ch; char val;
    do {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter character: "); scanf(" %c", &val); insert(val); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 4);
    return 0;
}