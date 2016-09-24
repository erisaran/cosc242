#include <stdio.h>
#include <stdlib.h>

void repeats(int *a, int s){
    int n,i;
    int *f = malloc(s * sizeof f[0]);
    if (NULL == f) {
        fprintf(stderr, "memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    for (n = 0; n < s; n ++){
        for (i = 0; i < s; i ++){
            if (a[i] == n){
                f[n] += 1;
            }
        }
    }
    for (n = 0; n < s; n++){
        if (f[n] > 1){
            printf("%d occurs %d times\n", n, f[n]);
        }
    }
}

int main(void) {
    int array_size = 0;
    int *my_array;
    int i = 0;
    printf("Enter the size of the array:\n");
    scanf("%d", &array_size);
    my_array = malloc(array_size * sizeof my_array[0]);
    if (NULL == my_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < array_size; i++) {
        my_array[i] = rand() % array_size;
    }
    printf("What's in the array:\n");
    for (i = 0; i < array_size; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");
    repeats(my_array,array_size);
    free(my_array);
    return EXIT_SUCCESS;
}
