#include <stdio.h>
#include <stdlib.h>

int main(void){
    double a,b,c,h = 0;
    int n,w;
    while (4 == scanf("%d%lg%lg%lg", &n, &a,&b,&c)){
        if (a < b && a < c){
            if ((b+c)/2 > h){
                h = (b+c)/2;
                w = n;
            }
        }else if (b < a && b < c){
            if ((a+c)/2 > h){
                h = (a+c)/2;
                w = n;
            }
        }else {
            if ((a+b)/2 > h){
                h = (a + b)/2;
                w = n;
            }
        }
    }
    printf("%d\n",w);
    return EXIT_SUCCESS;
}
