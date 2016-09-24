#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 3000

/** insertion sort algorithm taking an array and its length and changing it so
    it is sorted.
*/
void insertion_sort(int *a, int n) {
    int i;
    int key;
    int q;
    for (i = 1;i < n; i++){
        key = a[i];
        for (q = i-1;q >= 0; q --){
            if (key < a[q]){
                a[q+1] = a[q];
                if (q == 0){
                    a[q] = key;
                }
            }else if (key > a[q]){
                a[q+1] = key;
                q = 0;
            }
        }
    }
}
/**main method that creates and array of int from an input file and calls the.
   insertion sort algorithm on it.
*/
int main(void) {
    int my_array[ARRAY_MAX]; /* creates and array with size ARRAY_MAX */
    int i, count = 0;
    /*while there is input add it to the array if it hasnt exceeded max */
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }
    insertion_sort(my_array, count);
    for (i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    return EXIT_SUCCESS;
}
