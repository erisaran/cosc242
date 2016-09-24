#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 3000

/** selection sort algorithm taking an array and its length and changing it so
    it is sorted.
*/
void selection_sort(int *a, int n) {
    int p;
    int key;
    int i = 0;
    int q;
    int smaller = 0; /* functions as a boolean to record if anything smaller was
                    found */
    for (p = 0; p < n-1; p++){ /* for each of the items except the last */
        key = a[p]; 
        for (q = p; q < n; q++){ /* for each item rightward of p */
            if (a[q] < key){ /* make key the smallest value */
                key = a[q];
                i = q;
                smaller = 1;
            }
        }
        if (smaller == 1){ /* if something smaller was found then swap it */
            a[i] = a[p];
            a[p] = key;
        }
        smaller = 0;
    }
}
/**main method that creates and array of int from an input file and calls the.
   selection sort algorithm on it.
*/
int main(void) {
    int my_array[ARRAY_MAX]; /* creates and array with size ARRAY_MAX */
    int i, count = 0;
/* while there is input add it to the array so long as it hasnt exceeded max */
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }
    selection_sort(my_array, count); 
    for (i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    return EXIT_SUCCESS;
}
