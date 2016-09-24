#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
int i;
 if (argc > 1){
     int c = atoi(argv[1]);
     for (i = 0; i < c; i++){
         printf("%d\n",rand()%1000000);
     }
 }
 return EXIT_SUCCESS;
}
