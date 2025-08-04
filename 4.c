#include <stdio.h>

int main() {
    int arr[100], n, sum = 0;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];  // Add each element to sum
    }

    printf("Sum = %d\n", sum);
    return 0;
}

