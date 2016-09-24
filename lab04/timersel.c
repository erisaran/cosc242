#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_MAX 30000
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
        smaller = 0; /* reset back to false state */
    }
}
/**main method that creates and array of int from an input file and calls the.
   selection sort algorithm on it as well as displays time info in stderr.
*/
int main(void) {
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;
    /* while the array hasnt reached its limit and there are still items to be
       read*/
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }
    start = clock();
    selection_sort(my_array, count); /*call the sort algorithm */
    end = clock();
    for (i = 0; i < count; i++) { /* print out each array item */
        printf("%d\n", my_array[i]);
    }
    /* display timer info in the stderr output stream. */
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
