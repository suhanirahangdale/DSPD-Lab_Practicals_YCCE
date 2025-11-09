#include <stdio.h>
int main() {
    int n, i, sum_even = 0, sum_odd = 0;
    int arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) sum_even += arr[i];
        else sum_odd += arr[i];
    }
    printf("\nSum of elements at even positions: %d", sum_even);
    printf("\nSum of elements at odd positions: %d\n", sum_odd);
    return 0;
}