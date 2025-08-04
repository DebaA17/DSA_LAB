#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(sizeof(int) * 5); // allocate memory
    if (ptr == NULL) {
        return 1; // safety check
    }

    ptr[0] = 10;
    ptr[1] = 20;

    printf("Values: %d %d\n", ptr[0], ptr[1]);

    free(ptr); // ✅ this line frees the memory

    return 0;
}
