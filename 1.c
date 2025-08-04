#include <stdio.h>

void insertElement(int arr[], int *size, int element, int position) {
    for (int i = *size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = element;
    (*size)++;
}

int main() {
    int n, element, position;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n + 1]; 
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter position (0 to %d): ", n);
    scanf("%d", &position);

    if (position < 0 || position > n) {
        printf("Invalid position!\n");
        return 0;
    }

    insertElement(arr, &n, element, position);

    printf("Updated array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
