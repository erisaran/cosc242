#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 5

int main(void) {
    double j1[ARRAY_SIZE]; double j2[ARRAY_SIZE]; double j3[ARRAY_SIZE];
    double a,b,c;
    int n;
    int i = 0; int q;
    double a1 = 0.0; double a2 = 0.0; double a3 = 0.0;
    double v1 = 0.0; double v2 = 0.0; double v3 = 0.0;
    
    while (4 == scanf("%d%lg%lg%lg",&n,&a,&b,&c)){
        j1[i] = a;
        a1 += a;
        j2[i] = b;
        a2 += b;
        j3[i] = c;
        a3 += c;
        i ++;
    }

    a1 = a1/ARRAY_SIZE;
    a2 = a2/ARRAY_SIZE;
    a3 = a3/ARRAY_SIZE;

    for (q = 0; q < ARRAY_SIZE; q ++){
        v1 += pow(j1[q] - a1,2);
        v2 += pow(j2[q] - a2,2);
        v3 += pow(j3[q] - a3,2);
    }

    v1 = v1/(ARRAY_SIZE -1);
    v2 = v2/(ARRAY_SIZE -1);
    v3 = v3/(ARRAY_SIZE -1);

    printf("judge 1 : %4.2f %f \n", a1 ,sqrt(v1));
    printf("judge 2 : %4.2f %f \n", a2 ,sqrt(v2));
    printf("judge 3 : %4.2f %f \n", a3 ,sqrt(v3));

    return 0;
}
         
