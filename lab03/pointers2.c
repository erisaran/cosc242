#include <stdio.h>
#include <stdlib.h>

void repeats(int *a, int n) {
    int *times;
    int i, q;
    times = malloc(n * sizeof times[0]);
    if (NULL == times) {
        fprintf(stderr, "malloc failed\n");
        return;
    }
    for (i = 0; i< n; i ++){
        times[a[i]] += 1;
    }
    for (q = 0; q < n; q ++){
        printf("Times %d appears is %d.\n",q,times[q]);
    }
    free(times);
}

int main(void) {
    int array_size = 0;
    int *my_dynamic_array;
    int i = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &array_size);
    /* initialise the array to the appropriate size */
    my_dynamic_array = malloc(array_size * sizeof my_dynamic_array[0]);
    if (NULL == my_dynamic_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < array_size; i++) {
        my_dynamic_array[i] = rand() % array_size;
    }
    printf("What’s in the array:\n");
    for (i = 0; i < array_size; i++) {
        printf("%d ", my_dynamic_array[i]);
    }
    printf("\n");
    repeats(my_dynamic_array,array_size);
    /* release the memory associated with the array */
    free(my_dynamic_array);
    return EXIT_SUCCESS;
}
