#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int i;
    double j = 1.0;

    for (i =0; i < 10; i++){
        printf("%d %5.1f %5.2f\n", i, j, sqrt(j));
        j *= 2;
    }

    return EXIT_SUCCESS;
}
