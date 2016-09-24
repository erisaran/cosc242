#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"
    
struct flexarrayrec {
int capacity;
int itemcount;
    int *items;
};

void *emalloc(size_t s){
    void *r = malloc(s);
    if (r == NULL){
        exit(EXIT_FAILURE);
    }
    return r;
}

void *erealloc(void *f, size_t s){
    f = realloc(f,s);
    if (f == NULL){
        exit(EXIT_FAILURE);
    }
    return f;
}

void insert_sort(int *a, int s){
    int p,q,key,n;
    if (s == 0){
        return;
    }
    for (p = 1; p <s ; p++){
        key = a[p];
        if (p == s/2){
            for (n = 0; n< s; n++){
                fprintf(stderr, "%d\n", a[n]);
            }
        }
        for (q = p -1; q >=0;q --){
            if (a[q] > key){
                a[q+1] = a[q];
                if (q == 0){
                    a[q] = key;
                }
            }else {
                a[q + 1] = key;
                q = 0;
            }
        }
    }
}
        
    
flexarray flexarray_new() {
    flexarray f = emalloc(sizeof f);
    f->capacity = 2;
    f->itemcount = 0;
    f->items = emalloc(f->capacity * sizeof f->items[0]);
    return f;
}
    
void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity){
        f->capacity += f->capacity;
        f->items = erealloc(f->items,f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount ++] = num;
}
    
void flexarray_print(flexarray f) {
    int i;
    for (i = 0; i < f->itemcount; i++){
        printf("%d\n", f->items[i]);
    }
}
    
void flexarray_sort(flexarray f) {
    insert_sort(f->items, f->itemcount);
}
    
void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}
