#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_MAX 30000 /* defines max array size */

/** insertion sort algorithm taking an array and its length and changing it so
    it is sorted.
*/
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
void print_array(int *a, int n) {
    if (n > 0) {
        printf("%d\n", a[0]);
        print_array(a + 1, n - 1);
    }
}
/**main method that creates and array of int from an input file and calls the.
   insertion sort algorithm on it as well as displays time info in stderr.
*/
int main(void) {
    int my_array[ARRAY_MAX]; /* set max array size */
    int count = 0;
    /* while the array hasnt reached its limit and there are still items to be
       read*/
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }
    insertion_sort(my_array, count); /*call the sort algorithm */
    /* print out each array item */
    print_array(my_array,count);
    return EXIT_SUCCESS;
}
