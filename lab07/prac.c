#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 80
#define ARRAY_LEN 100

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr,"Malloc failed\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void bigger(char *a[],double aver,int n){
    if (n > 0){
        if (strlen(a[0]) > aver){
            printf("%s\n",a[0]);
        }
        bigger(a + 1, aver, n-1);
    }
}

int main(void){
    char word[STRING_LEN];
    char *wordlist[ARRAY_LEN];
    int num_words;
    double average = 0.0;
    int i;

    num_words = 0;
    while (num_words < ARRAY_LEN && 1 == scanf("%79s", word)){
        wordlist[num_words] = emalloc((strlen(word) + 1) * sizeof wordlist[0][0]);
        strcpy(wordlist[num_words],word);
        num_words++;
    }

    for (i = 0; i < num_words; i++) {
        average += strlen(wordlist[i]);
    }

    average = average / num_words;
    

    bigger(wordlist,average,num_words);

    if (num_words > 0){
        fprintf(stderr,"%.2f\n",average);
    }

    for (i = 0; i < num_words; i++) {
        free(wordlist[i]);
        }

    return EXIT_SUCCESS;
}