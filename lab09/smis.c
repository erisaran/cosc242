#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_MAX 1000000

int drop;

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

void merge(int *array, int *workspace,int len) {
int i = 0, j = len/2, k = 0;
while (i < len/2 && j < len){
if (array[i] < array[j]){
    workspace[k] = array[i];
    i++;
 }else {
    workspace[k] = array[j];
    j++;
 }
 k++;
 }
 if (i < len/2){
     while (i < len/2){
         workspace[k] = array[i];
         i++;
         k++;
     }
 }else if (j < len){
     while (j < len){
         workspace[k] = array[j];
         j++;
         k++;
     }
 }
}

void merge_sort(int *a, int *w, int n) {
    int i;
    if (n < 2){
        return;
    }
    if (n < drop){
        insertion_sort(a,n);
    }else{
        merge_sort(a, w, n/2);
        merge_sort((a + (n/2)), (w + (n/2)), (n - (n/2)));

        merge(a, w, n);
        for (i = 0; i < n; i ++){
            a[i] = w[i];
        }
    }
}


int main(int argc, char **argv) {    
    int my_array[ARRAY_MAX];
    int workspace[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;
    if (argc > 1){
        drop = atoi(argv[1]);
    }
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }
    start = clock();
    merge_sort(my_array, workspace, count);
    end = clock();
    for (i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
