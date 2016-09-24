#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"
#include "rbt.h"
#include "container.h"

/**
   @brief A container struct.
 */
struct containerrec {
    container_t type;
    void *contents;
};

/**
   @brief This function prints out the specified string
       to the specified output stream.
   @params s The string to be printed out.
   @params stream The output stream to be specified.
   @return Not used.
 */
void print_key(char *s, FILE *stream) {
    fprintf(stream,"%s ", s);
}

/**
   @brief This function creates a new container to hold either a
       new red-black tree or flexarray.
   @params t Specifies whether a red-black tree or
       a flexarray is used.
   @return c The new container.
 */
container container_new(container_t t){
    container c = emalloc(sizeof *c);
    c->type = t;
    if (t == RED_BLACK_TREE){
        c->contents = rbt_new();
    }else {
        c->contents = flexarray_new();
    }
    return c;
}   

/**
   @brief This function allows a string to be added to the
       appropriate container.
   @params c The container to be specified.
   @params word The string to be added to the appropriate container.
   @return Not used.
 */
void container_add(container c, char *word) {
    if (c->type == RED_BLACK_TREE) {
        c->contents = rbt_insert(c->contents, word);
    } else {
        flexarray_append(c->contents, word);
    }
}

/**
   @brief This function frees the memory allocated to the
       specified container.
   @params c The container to be freed.
   @return c The container which has had its memory freed.
       It can now be allocated again.
 */
container container_free(container c){
    if (c->type == RED_BLACK_TREE){
        rbt_free(c->contents);
    }else {
        flexarray_free(c->contents);
    }
    free(c);
    return c;
}

/**
   @brief This function prints the specified container
       to the specified output stream.
   @params c The container to be printed.
   @params stream The specified output stream to print the
       contents of the container to.
   @return Not used.
 */
void container_print(container c, FILE *stream){
    if (c->type == RED_BLACK_TREE){
        rbt_preorder(c->contents, print_key,stream);
    }else {
        flexarray_print(c->contents, stream);
    }
}

/**
   @brief This function searches through the specified
       container to find the specified string.
   @params c The container to be searched through.
   @params word The string to be searched for.
   @return 1 If the string is found in the container.
   @return 0 If the string is not found in the container.
 */
int container_search(container c, char *word){
    if (c->type == RED_BLACK_TREE){
        return rbt_search(c->contents, word);
    }else {
        return flexarray_is_present(c->contents,word);
    }
    return 0;
}
