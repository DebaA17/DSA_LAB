#include <stdio.h>

void deleteElement(int arr[], int *size, int position) {
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int main() {
    int n, position;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n]; 
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &position);

    if (position < 0 || position >= n) {
        printf("Invalid position!\n");
        return 0;
    }

    deleteElement(arr, &n, position);

    printf("Updated array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}

