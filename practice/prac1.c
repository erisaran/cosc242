#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_MAX 100
#define WORD_MAX 80

void *emalloc(size_t s){
    void *memory = malloc(s);
    if (memory == NULL){
        fprintf(stderr,"Error");
        exit(EXIT_FAILURE);
    }
    return memory;
}

void aver(char **a, double av, int n) {
    if (n > 0){
        if (strlen(a[0]) > av){
            printf("%s\n",a[0]);
        }
        aver(a + 1, av, n -1);
    }
}

int main(void){
    char word[WORD_MAX];
    char *words[ARRAY_MAX];
    double average = 0.0;
    int i,count = 0;

    while (count < ARRAY_MAX && 1 == scanf("%79s",word)){
        words[count] = emalloc((strlen(word) + 1) * sizeof word[0]);
        average += strlen(word);
        strcpy(words[count],word);
        count ++;
    }

    if (count > 0){
        average /= count;
        aver(words,average,count);
        fprintf(stderr,"%.2f\n", average);
    }

    for (i = 0; i < count; i++){
        free(words[i]);
    }

    return EXIT_SUCCESS;
}
