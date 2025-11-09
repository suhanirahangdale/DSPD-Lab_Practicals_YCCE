//Suhani Rahangdale (B-121)
/*Write a program to implement a Binary Search algorithm. Write a search function which takes a SearchList as its first parameter and a Comparable as its second. If either parameter is null, or if the SearchList is empty, you should return NULL.
 implement the following algorithm: 
• Examine the value in the middle of the current array and print it. 
• If the midpoint value is the value that we are looking for, return true 
• If the value that we are looking for is greater than the midpoint value, adjust the current array to start at the midpoint and print the index.
• if the value that we are looking for is less than the midpoint value, adjust the current array to end at the midpoint  and print the index.
• Continue until you find the value, or until the start reaches the end, 
*/


#include <stdio.h>
int* binarySearch(int arr[], int n, int key) {
    if(arr == NULL || n == 0) 
        return NULL;

    int start = 0, end = n - 1;
    while(start <= end) {
        int mid = (start + end) / 2;
        printf("Middle Value: %d\n", arr[mid]);   
        if(arr[mid] == key)
            return &arr[mid]; 
        else if(key > arr[mid]) {
            start = mid + 1;
            printf("Adjusting start to index: %d\n", start);
        }
        else {
            end = mid - 1;
            printf("Adjusting end to index: %d\n", end);
        }
    }
    return NULL; 
}
int main() {
    int arr[20], n, key, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if(n == 0) {
        printf("NULL\n");
        return 0;
    }

    printf("Enter elements in sorted order:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value to search: ");
    scanf("%d", &key);

    int *result = binarySearch(arr, n, key);

    if(result == NULL)
        printf("NULL\n");
    else
        printf("Found\n");

    return 0;
}