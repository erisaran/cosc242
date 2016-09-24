#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int f = 0;
    int g = 1;
    int i;
    int s = 0;
    for (i = 1; i <= 40;i ++){
        printf("%10d", g);
        s = g;
        g += f;
        f = s;
        if (i%5 == 0 && i != 0){
            printf("\n");
        }
    }
    printf("\n");
    
    return EXIT_SUCCESS;
}
