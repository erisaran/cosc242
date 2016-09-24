#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 80
#define ARRAY_LEN 10000

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
int main(void) {
    char word[STRING_LEN];
    char *wordlist[ARRAY_LEN];
    char *temp;
    int num_words;
    int q;
    int i;
    
    num_words = 0;
    while (num_words < ARRAY_LEN && 1 == scanf("%79s", word)) {
        wordlist[num_words] = emalloc((strlen(word) + 1) * sizeof wordlist[0][0]);
        strcpy(wordlist[num_words], word);
        num_words++;
    }

    for (i = 1; i < num_words; i++) {
        temp = wordlist[i];
        for (q = i-1; q>=0; q--){
            if (strcmp(temp,wordlist[q]) < 0){
                wordlist[q+1] = wordlist[q];
                if (q == 0){
                    wordlist[q] = temp;
                }
            }else if (strcmp(temp,wordlist[q]) >= 0){
                wordlist[q+1] = temp;
                q = 0;
            }
        }
    }

    for (i = 0; i < num_words; i++) {
        printf("%s\n",wordlist[i]);
    }

    for (i = 0; i < num_words; i++) {
        free(wordlist[i]);
    }
    return EXIT_SUCCESS;
}
