#ifndef RBT_H_
#define RBT_H_

#include <stdio.h>

typedef enum { RED, BLACK } rbt_colour;
typedef struct rbt_node *rbt; /* should live in rbt.h */

extern int rbt_search(rbt b, char *key);
extern rbt rbt_insert(rbt b, char *key);
extern rbt rbt_free(rbt b);
extern void rbt_inorder(rbt b, void f(char *str));
extern void rbt_preorder(rbt b, void f(char *str));
extern rbt rbt_new();
extern rbt rbt_delete(rbt b, char *str);

#endif
