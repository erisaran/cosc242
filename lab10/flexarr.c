#include <stdio.h>
#include <stdlib.h>
void insertion_sort(int *a, int n) {
int i;
 int key;
 int q;
 for (i = 1;i < n; i++){ /* for every item except the first */
     key = a[i]; /* make key the current item */
     for (q = i-1;q >= 0; q --){ /* for each item that came before */
         if (key < a[q]){ /* if any are bigger than key */
             a[q+1] = a[q]; /* move it up one place */
             if (q == 0){ /* if key is smaller than everything else */
                 a[q] = key; /* put it first */
             }
         }else if (key >= a[q]){ /* else if a previous item is smaller */
             a[q+1] = key; /* put key in the empty spot above */
             q = 0; /* set q to 0 to skip the rest of the search */
         }
     }
 }
}
static void array_print(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}
int main(void) {
    int capacity = 2;
    int itemcount = 0;
    int item;
    int *my_array = malloc(capacity * sizeof my_array[0]);
    if (NULL == my_array) {
        fprintf(stderr, "memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    while (1 == scanf("%d", &item)) {
        if (itemcount == capacity) {
            capacity += capacity;
            my_array = realloc(my_array, capacity * sizeof my_array[0]);
            if (NULL == my_array) {
                fprintf(stderr, "memory reallocation failed.\n");
                exit(EXIT_FAILURE);
            }
        }
        my_array[itemcount++] = item;
    }
    insertion_sort(my_array,itemcount);
    array_print(my_array, itemcount);
    free(my_array);
    return EXIT_SUCCESS;
}
