#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"

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

static void merge_sort(int *a, int *w, int n) {
    int i;
    if (n < 2){
        return;
    }
    if (n < 35){
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

struct flexarrayrec {
    int capacity;
    int itemcount;
    char **items;
};
flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}
void flexarray_append(flexarray f, char *num) {
    if (f->itemcount == f->capacity) {
        f->capacity += f->capacity;
        f->items = erealloc(f->items,f->capacity * sizeof f->items);
    }
    f->items[f->itemcount++] = num;
}
void flexarray_print(flexarray f) {
    int i;
    for (i = 0; i < f->itemcount; i++) {
        printf("%d\n", f->items[i]);
    }
}
void flexarray_sort(flexarray f) {
    int *workspace = emalloc(f->itemcount * sizeof workspace[0]);
    merge_sort(f->items,workspace,f->itemcount);
    free(workspace);
}
void flexarray_free(flexarray f) {
    free(f->items);
}
