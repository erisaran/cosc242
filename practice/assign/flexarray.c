/**
   242 assignment flexarray file.
   Code for building an flexarray.
   @author Ben Dutton,  Alexander Dooley,  Murdoch Braid.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "flexarray.h"

/**
   @brief A flexarray struct with variables to define its capacity, itemcount
   and and array of strings.
*/
struct flexarrayrec {
    int capacity;
    int itemcount;
    char **items;
};

/**
   @brief quicksort is an implementation of the 
   quicksort algorithm.
   @params **a the string to be sorted 
   @params len the length of the array to be sorted
*/
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

/**
   @brief Creates a new flexarray
   @params Not used.
   @return result Returns an empty flexarray.

*/
flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

/**
   @brief This function appends an array onto the
   current array, if the current array size is to be
   exceeded. Otherwise it simply adds the string into
   the current array.
   @param f The current flexarray.
   @param item The string to be added.
   @return Not used.
*/
void flexarray_append(flexarray f, char *item) {
    if (f->capacity == f->itemcount) {
        f->capacity += f->capacity;
        f->items = erealloc(f->items, (f->capacity * sizeof f->items[0]));
    }
    f->items[f->itemcount] = emalloc(255 * sizeof f->items[0][0]);
    strcpy(f->items[f->itemcount++], item);
}

/**
   @brief This function prints the flexarray to the
   specified output stream.
   @param f The flexarray to be printed out.
   @param stream The output stream to be specified.
   @return Not used.
*/
void flexarray_print(flexarray f, FILE *stream) {
    int i;
    for (i = 0; i < f->itemcount; i++) {
        fprintf(stream, "%s ", f->items[i]);
    }
}

/**
   @brief This function takes a flexarray and calls the
   desired sorting algorithm on it.
   @param f The flexarray to be sorted.
   @return Not used.
*/
void flexarray_sort(flexarray f) {
    quicksort(f->items, f->itemcount);
}

/**
   @brief This function takes a flexarray and frees the
   memory that has been allocated to it.
   @param f The flexarray to be freed.
   @return Not used.
*/
void flexarray_free(flexarray f) {
    int i;
    for (i = 0; i < f->itemcount; i++) {
        free(f->items[i]);
    }
    free(f->items);
    free(f);
}

/**
   @brief Visits each item in the flex array and passes them as a parameter to
   a function.
   @param f The flexarray.
   @param g A function taking one string parameter.
   @return Not used.
*/
void flexarray_visit(flexarray f, void g(char *str)) {
    int i;
    for (i = 0; i < f->itemcount; i++) {
        g(f->items[i]);
    }
}

/**
   @brief This function acts as a search - the flexarray
   is iterated through to determine whether or not
   the given string exits.
   @params f The flexarray to be searched through
   @params str The string that is being searched for
   @return 1 If the string is found in the flexarray
   @return 0 If the string is not found in the flexarray.
*/
int flexarray_is_present(flexarray f, char *str) {
    int i;
    for (i = 0; i < f->itemcount; i++) {
        if (strcmp(str, f->items[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
