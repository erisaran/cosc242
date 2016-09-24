#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"

static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}

struct htablerec {
    int capacity;
    int num_keys;
    char **keys;
    int *freq;
};

htable htable_new(int capacity){
    int i;
    htable h = emalloc(sizeof *h);
    h->capacity = capacity;
    h->num_keys = 0;
    h->freq = emalloc(h->capacity * sizeof h->freq[0]);
    h->keys = emalloc(h->capacity * sizeof h->keys[0]);
    /*printf("%lu \n", sizeof *h);*/
    for (i = 0; i < h->capacity; i ++){
        
        h->keys[i] = NULL;
        h->freq[i] = 0;
    }
    return h;
}

void htable_free(htable hash){
    /*int i;*/
    free(hash->freq);
    /*for (i = 0; i < hash->capacity; i++){
        free(hash->keys[i]);
        }*/
    free(hash->keys);
    free(hash);
}

static unsigned int htable_step(htable h, unsigned int i_key) {
    return 1 + (i_key % (h->capacity - 1));
}

             
int htable_insert(htable h, char *str){
    unsigned int hashing = htable_word_to_int(str);
    int index = hashing%h->capacity;
    int c = h->capacity;
    int i;
    unsigned int s = htable_step(h, hashing)% c;
    int step = s % c;
    /*printf("%d --- %d && ",index, c);*/
      
    if (h->keys[index] == NULL){
        h->keys[index] = emalloc((strlen(str) +1) * sizeof h->keys[0][0]);
        strcpy(h->keys[index], str);
        h->freq[index] = 1;
        h->num_keys ++;
        return 1;
    }else if (strcmp(h->keys[index], str) == 0){
        h->freq[index] += 1;
        return h->freq[index];
    }else if (h->keys[index] != NULL && strcmp(h->keys[index],str) != 0){
        if (h->num_keys == h->capacity){
            return 0;
        }else {
            for (i = 1; i< h->capacity; i++){
                if (h->keys[(index + step)%c] == NULL){
                    h->keys[(index + step)% c] = emalloc((strlen(str)+1) * sizeof h->keys[0][0]);
                    strcpy(h->keys[(index + step)%c],str);
                    h->freq[(index + step)%c] = 1;
                    h->num_keys ++;
                    return 1;
                }else if (strcmp(h->keys[(index + step)%c],str) == 0){
                    h->freq[(index + step)%c] ++;
                    return h->freq[(index + step)%c];
                }
                step = step + s ;
            }
            return 0;
        }
    }
    
    return 0;
}

void htable_print(htable h, FILE *stream){
    int i;
    /*int prints = 0;
    unsigned int x = htable_word_to_int("scramble");
    int y = x % h->capacity;
    int z = strcmp("scramble","disadvantageous");*/
    for (i = 0; i < h->capacity; i++){
        if (h->keys[i] != NULL){
            fprintf(stream, "%d of %s\n", h->freq[i], h->keys[i]);
            }
    }
    /*printf("%d %d %d\n",prints,y,z);*/
}

int htable_search(htable h, char *key){
    int collisions = 0;
    unsigned int hashing = htable_word_to_int(key);
    int index = hashing%h->capacity;
    unsigned int step = htable_step(h, hashing) % h->capacity;
    while (h->keys[index] != NULL && collisions < h->capacity && strcmp(h->keys[index], key) != 0){
        index = (index + step) % h->capacity; 
        collisions ++;
    }
    if (collisions == h->capacity){
        return 0;
    }else {
        return h->freq[index];
    }
}

