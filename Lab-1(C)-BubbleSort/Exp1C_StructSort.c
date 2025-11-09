//Suhani Rahangdale -IT-B-121
/* Write a program which creates a structure Student which must have the attribute Avg Marks
        with 3 more attributes sort the list of the student in descending order using Bubble sort.*/


#include <stdio.h>
#include <string.h>
struct Student {
    int rollno;
    char name[50];
    float marks[3];
    float avg;
};
int main() {
    struct Student s[100], temp;
    int n, i, j;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].rollno);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Enter 3 subject marks: ");
        s[i].avg = 0;
        for (j = 0; j < 3; j++) {
            scanf("%f", &s[i].marks[j]);
            s[i].avg += s[i].marks[j];
        }
        s[i].avg /= 3.0;
    }
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (s[j].avg < s[j + 1].avg) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
    printf("\nStudents sorted by average marks (Descending):\n");
    for (i = 0; i < n; i++)
        printf("%d\t%s\t%.2f\n", s[i].rollno, s[i].name, s[i].avg);
    return 0;
}