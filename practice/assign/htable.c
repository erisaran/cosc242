/**
   242 assignment hashtable file.
   Code for building an hash table.
   @author Ben Dutton,  Alexander Dooley,  Murdoch Braid.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"
#include "container.h"

/**
   @brief This function takes a string and returns
   an int value to be used for creating an index.
   @params word The string to be converted to an int.
   @return result The int representing the specified string.
*/
static unsigned int htable_word_to_int(char *word) {
unsigned int result = 0;
while (*word != '\0') {
result = (*word++ + 31 * result);
 }
 return result;
}

/**
   @brief A hashtable struct to hold a capacity, number of keys, and array of
   containers and the type of container(either flexarray or rbt).
*/
struct htablerec {
    int capacity;
    int num_keys;
    container *keys;
    int *freq;
    container_t type;
};

/**
   @brief This function creates a new hashtable and
   allocates its memory using flexarray containers by default.
   @params capacity The size of the hashtable to be created.
   @return h The newly created hashtable.
*/
htable htable_new(int capacity){
    int i;
    htable h = emalloc(sizeof *h);
    h->type = FLEX_ARRAY;
    h->capacity = capacity;
    h->num_keys = 0;
    h->freq = emalloc(h->capacity * sizeof h->freq[0]);
    h->keys = emalloc(h->capacity * sizeof h->keys[0]);
    for (i = 0; i < h->capacity; i ++){
        
        h->keys[i] = NULL;
        h->freq[i] = 0;
    }
    return h;
}

/**
   @brief Used by the application file to set the hash tables container type.
   @param hash the hashtable to be changed.
   @param t the kind of container that the hash table will use.
*/
void htable_robust(htable hash, container_t t){
    hash->type = t;
}

/**
   @brief This function takes a specified hashtable and
   frees the associated memory.
   @params hash The hashtanble to be freed.
   @return Not used.
*/
void htable_free(htable hash){
    int i;
    free(hash->freq);
    for (i = 0; i < hash->capacity; i++){
        if (hash->keys[i] != NULL){
            container_free(hash->keys[i]);
        }
    }
    free(hash->keys);
    free(hash);
}

/**
   @brief This function inserts a specified string into
   a specified hashtable.
   @param h the hash table that is being inserted into.
   @param str the str to be inserted.
   @return an int to show if the string was inserted. 1 for yes 0 for no.
*/
int htable_insert(htable h, char *str){
    unsigned int hashing = htable_word_to_int(str);
    int index = hashing%h->capacity;
    container init;
    if (h->keys[index] == NULL){
        init = container_new(h->type);
        container_add(init, str);
        h->keys[index] = init;
        h->freq[index] = 1;
        h->num_keys ++;
        return 1;
    }else {
        container_add(h->keys[index], str);
        return 1;
    }
    return 0;
}

/**
   @brief This function takes the specified hashtable and prints
   it out to the specified output stream.
   @params h The hashtable to be printed out.
   @params stream The specified output stream.
   @return Not used.
*/
void htable_print(htable h, FILE *stream){
    int i;
    for (i = 0; i < h->capacity; i++){
        if (h->keys[i] != NULL){
            fprintf(stream, "%d ", i);
            container_print(h->keys[i], stream);
            fprintf(stream, "\n");
        }
    }
}

/**
   @brief This function determines whether or not a given string
   is in the specified hashtable.
   @params h The hashtable to be search through.
   @params key The string to be search for.
   @return 0 If the string cannot be found.
   @return 1 If the string can be found.
*/
int htable_present(htable h, char *key){
    unsigned int hashing = htable_word_to_int(key);
    int index = hashing % h->capacity;
    if (h->keys[index] == NULL){
        return 0;
    }
    if (container_search(h->keys[index],key) == 1){
        return 1;
    }
    return 0;
}
