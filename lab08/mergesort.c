#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_MAX 100000

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
    merge_sort(a, w, n/2);
    merge_sort((a + (n/2)), (w + (n/2)), (n - (n/2)));

    merge(a, w, n);
    for (i = 0; i < n; i ++){
        a[i] = w[i];
    }
}


int main(void) {
    int my_array[ARRAY_MAX];
    int workspace[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;
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
