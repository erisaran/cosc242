#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"

struct htablerec {
    int capacity;
    int num_keys;
    char **keys;
};

static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;

    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}

static unsigned int htable_hash(htable h, unsigned int i_key) {
    return i_key % h->capacity;
}

htable htable_new(int capacity) {
    htable h = emalloc(sizeof *h);
    int i;
    h->capacity = capacity;
    h->num_keys = 0;
    h->keys = emalloc(capacity * sizeof h->keys[0]);
    for (i = 0; i < capacity; i ++){
        h->keys[i] = NULL;
    }
    return h;
}

void htable_free(htable h) {
    int i;
    for (i = 0; i < h->capacity; i ++){
        free(h->keys[i]);
    }
    free(h->keys);
    free(h);
}

int htable_insert(htable h, char *key) {
    unsigned int index = htable_hash(h,htable_word_to_int(key));
    int i;
    if (h->keys[index] == NULL){
        h->keys[index] = emalloc((strlen(key) + 1) * sizeof h->keys[0][0]);
        strcpy(h->keys[index], key);
        h->num_keys++;
        return 1;
    }else if (strcmp(key, h->keys[index]) != 0){
        if (h->num_keys == h->capacity){
            return 0;
        }
        for (i = 0; i < h->capacity; i ++){
            if (h->keys[(index + i)%h->capacity] == NULL){
                h->keys[(index + i)%h->capacity] =
                    emalloc((strlen(key) + 1) * sizeof h->keys[0][0]);
                strcpy(h->keys[(index + i)%h->capacity], key);
                h->num_keys++;
                return 1;
            }
        }
    }
    return 0;
}

void htable_print(htable h, FILE *stream) {
    int i;
    for (i = 0; i < h->capacity; i++) {
        fprintf(stream, "%2d %s\n", i, h->keys[i] == NULL ? "" : h->keys[i]);
    } 
}
