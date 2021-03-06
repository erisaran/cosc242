#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    char **items;
};

static void quicksort(char **a, int len) {
    int i = 0, j = 0, pivot = 0;
    char *temp;
    if (len < 2) {
        return;
    }
    pivot = 0;
    i = -1;
    j = len;
    for (;;) {
        do {
            i++;
        } while (strcmp(a[i], a[pivot]) < 0);
        do {
            j--;
        } while (strcmp(a[j], a[pivot]) > 0);
        if (i < j) {
            temp = emalloc(255 * sizeof temp[0]);
            strcpy(temp, a[i]);
            strcpy(a[i], a[j]);
            strcpy(a[j], temp);
            free(temp);
        } else {
            break;
        }
    }
    quicksort(a, j + 1);
    quicksort((a + j + 1), (len - j - 1));
}

flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

void flexarray_append(flexarray f, char *item) {
    if (f->capacity == f->itemcount) {
        f->capacity += f->capacity;
        f->items = erealloc(f->items, (f->capacity * sizeof f->items[0]));
    }
    f->items[f->itemcount] = emalloc(255 * sizeof f->items[0][0]);
    strcpy(f->items[f->itemcount++], item);
}

void flexarray_print(flexarray f, FILE *stream) {
    int i;
    for (i = 0; i < f->itemcount; i++) {
        fprintf(stream,"%s\n", f->items[i]);
    }
}

void flexarray_sort(flexarray f) {
    quicksort(f->items, f->itemcount);
}

void flexarray_free(flexarray f) {
    int i;
    for (i = 0; i < f->itemcount; i++) {
        free(f->items[i]);
    }
    free(f->items);
    free(f);
}

void flexarray_visit(flexarray f, void g(char *str)) {
    int i;
    for (i = 0; i < f->itemcount; i++) {
        g(f->items[i]);
    }
}

int flexarray_is_present(flexarray f, char *str) {
    int i;
    for (i = 0; i < f->itemcount; i++) {
        if (strcmp(str, f->items[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
