#include <stdio.h>
#include <stdlib.h>

int is_prime(int candidate){
    int i;
    for (i = 2; i < candidate;i++){
        if (candidate % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(void){
    int candidate = 2;
    int n = 0;
    while (n<200){
        if (is_prime(candidate)){
            printf("%5d",candidate);
            n++;
            if (n % 10 == 0){
                printf("\n");
            }
        }
        candidate ++;
    }
}
