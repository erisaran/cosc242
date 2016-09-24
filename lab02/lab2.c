#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    double s1; double s2; double s3;
    int return_code;

    printf("Enter 3 scores.\n");
    fflush(stdout);
    return_code = scanf("%lg%lg%lg",&s1,&s2,&s3);
    if (return_code != 3) {
        printf("scanf returned code %d\n",return_code);
        return EXIT_FAILURE;
    }
    if (s1 < s2 && s1 < s3) {
        printf("average of highest 2: %f \n",(s2+s3)/2);
    }else if (s2 < s1 && s2 < s3){
        printf("average of highest 2: %f \n",(s1+s3)/2);
    }else {
        printf("average of highest 2: %f \n",(s1+s2)/2);
    }
    

    return 0;
}

    
