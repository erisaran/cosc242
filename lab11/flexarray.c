#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"

void quicksort(int *a, int n){
    int pivot = a[0];
    int i = -1;
    int j = n;
    int k;
    if (n < 2){
        return;
    }
    for (;;){
        do { i++;
        } while (a[i]< pivot);
        do { j--;
        } while (a[j] > pivot);
        if (i < j){
            k = a[i];
            a[i] = a[j];
            a[j] = k;
        }else {
            break;
        }
    }
    quicksort(a,j+1);
    quicksort(a+j+1,n-(j+1));
    
}
                    
struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};
flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}
void flexarray_append(flexarray f, int num) {
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
    quicksort(f->items,f->itemcount);
}
void flexarray_free(flexarray f) {
    free(f->items);
}
