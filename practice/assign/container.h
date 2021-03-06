#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <stdio.h>

typedef enum container_e {FLEX_ARRAY, RED_BLACK_TREE} container_t;
typedef struct containerrec *container;

extern void container_add(container c, char *word);
extern container container_new(container_t t);
extern container container_free(container c);
extern void container_print(container c, FILE *stream);
extern int container_search(container c, char *word);

#endif
