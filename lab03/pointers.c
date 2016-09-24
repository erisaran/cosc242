#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void max_min(int *a, int n, int *max, int *min){
    int i;
    *min = a[0];
    for (i = 0; i < n; i++){
        if (a[i] > *max){
            *max = a[i];
        }
        if (a[i] < *min){
            *min = a[i];
        }
    }
}

int main(void) {
    int my_array[] = { 5,2,7,3,4 };
    int biggest, smallest;
    max_min(my_array,5, &biggest, &smallest);
    printf("max %d min %d\n",biggest,smallest);

    return 0;
}
