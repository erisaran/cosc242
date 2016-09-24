#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"
struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

void *emalloc(size_t s){
    void *result = malloc(s);
    if (result == NULL){
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
void *erealloc(void *f, size_t s){
    f = realloc(f,s);
    if (NULL == f){
        fprintf(stderr, "realloc failed\n");
        exit(EXIT_FAILURE);
    }
    return f;
}

void insertion_sort(int *a, int size){
    int i,key,q,n;
    if (size == 0){
        return;
    }
    for (i = 1; i < size; i++){
        key = a[i];
        if (i == size/2){
            for (n = 0; n < size; n++){
                fprintf(stderr, "%d\n", a[n]);
            }
        }
        for (q = i-1; q >= 0; q --){
            if (key < a[q]){
                a[q+1] = a[q];
                if (q == 0){
                    a[q] = key;
                }
            }else if (key >= a[q]){
                a[q+1] = key;
                q = 0;
            }
        }
    }
}

flexarray flexarray_new() {
    flexarray f = emalloc(sizeof *f);
    f->capacity = 2;
    f->itemcount = 0;
    f->items = emalloc(f->capacity * sizeof f->items[0]);
    return f;
}
void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity){
        f->capacity += f->capacity;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount++] = num;
}
void flexarray_print(flexarray f) {
    int i;
    for (i = 0; i< f->itemcount; i++){
        printf("%d\n", f->items[i]);
    }
}
void flexarray_sort(flexarray f) {
    insertion_sort(f->items, f->itemcount);
}
void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}
