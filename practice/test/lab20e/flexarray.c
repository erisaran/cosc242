#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"
    
struct flexarrayrec {
int capacity;
int itemcount;
    int *items;
};

void *emalloc(size_t s){
    void *f = malloc(s);
    if (f == NULL){
        exit(EXIT_FAILURE);
    }
    return f;
}
void *erealloc(void *f, size_t s){
    f = realloc(f,s);
    if (f == NULL){
        exit(EXIT_FAILURE);
    }
    return f;
}

void select_sort(int *a, int s){
    int p,q,key,smallest,i,found = 0;
    for (p = 0; p < s-1;p++){
        key = a[p];
        if (p == s/2){
            for (i =0;i<s;i++){
                fprintf(stderr,"%d\n",a[i]);
            }
        }
        for (q = p;q < s; q++){
            if (a[q] < key){
                key = a[q];
                smallest = q;
                found = 1;
            }
        }
        if (found){
            a[smallest] = a[p];
            a[p] = key;
        }
        found = 0;
    }
}

flexarray flexarray_new() {
    flexarray f = emalloc(sizeof f);
    f->capacity =2;
    f->itemcount = 0;
    f->items = emalloc(f->capacity * sizeof f->items[0]);
    return f;
}
    
void flexarray_append(flexarray f, int num) {
    if (f->capacity == f->itemcount){
        f->capacity += f->capacity;
        f->items = realloc(f->items,f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount++] = num; 
}
    
void flexarray_print(flexarray f) {
    int i;
    for (i=0;i<f->itemcount;i++){
        printf("%d\n",f->items[i]);
    }
}
    
void flexarray_sort(flexarray f) {
    select_sort(f->items,f->itemcount);
}
    
void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}
