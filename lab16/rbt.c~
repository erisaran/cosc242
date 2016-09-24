#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbt.h"
#include "mylib.h"

#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))


struct rbt_node { /* should live in bst.c */
    char *key;
    rbt_colour colour;
    rbt left;
    rbt right;
};

rbt rbt_new(){
    return NULL;
}

int rbt_search(rbt b, char *key){
    if (b == NULL){
        return 0;
    }else if (strcmp(key,b->key) == 0){
        return 1;
    }else if (strcmp(key,b->key) < 0){
        return rbt_search(b->left, key);
    }else if (strcmp(key,b->key) > 0){
        return rbt_search(b->right, key);
    }
    return 0;
}

static rbt right_rotate(rbt b){
    rbt temp = b;
    b = b->left;
    temp->left = b->right;
    b->right = temp;
    return b;
}

static rbt left_rotate(rbt b){
    rbt temp = b;
    b = b->right;
    temp->right = b->left;
    b->left = temp;
    return b;
}

static rbt rbt_fix(rbt b){
    
    if (IS_RED(b->left) && IS_RED(b->left->left)){
        if (IS_RED(b->right)){
            b->colour = RED;
            b->left->colour = BLACK;
            b->right->colour = BLACK;
        }else if (IS_BLACK(b->right)){
            b->colour = RED;
            b->left->colour = BLACK;
            b = right_rotate(b);
        }
    }else if (IS_RED(b->left) && IS_RED(b->left->right)){
        if (IS_RED(b->right)){
            b->colour = RED;
            b->left->colour = BLACK;
            b->right->colour = BLACK;
        }else if (IS_BLACK(b->right)){
            b->colour = RED;
            b->left->right->colour = BLACK;
            b->left = left_rotate(b->left);
            b = right_rotate(b);
        }
    }else if (IS_RED(b->right) && IS_RED(b->right->left)){
        if (IS_RED(b->left)){
            b->colour = RED;
            b->left->colour = BLACK;
            b->right->colour = BLACK;
        }else if (IS_BLACK(b->left)){
            b->right->left->colour = BLACK;
            b->colour = RED;
            b->right = right_rotate(b->right);
            b = left_rotate(b);
        }
    }else if (IS_RED(b->right) && IS_RED(b->right->right)){
        if (IS_RED(b->left)){
            b->colour = RED;
            b->left->colour = BLACK;
            b->right->colour = BLACK;
        }else if (IS_BLACK(b->left)){
            b->right->colour = BLACK;
            b->colour = RED;
            b = left_rotate(b);
        }
    }
    return b;
}

rbt rbt_insert(rbt b, char *key){
    if (b == NULL){
        b = emalloc(sizeof *b);
        b->key = emalloc((strlen(key)) + 1 * sizeof key[0]);
        strcpy(b->key, key);
        b->colour = RED;
    }else if (strcmp(b->key,key) == 0){
    }else if (strcmp(key,b->key) < 0){
        b->left = rbt_insert(b->left, key);
    }else if (strcmp(key,b->key) > 0){
        b->right = rbt_insert(b->right, key);
    }
    b = rbt_fix(b);
    return b;
}

void rbt_inorder(rbt b, void f(char *s)){
    if (b == NULL){
        return;
    }
    rbt_inorder(b->left, f);
    f(b->key);
    rbt_inorder(b->right,f);
}

void rbt_preorder(rbt b, void f(char *s)){
    if (b == NULL){
        return;
    }
    if (IS_RED(b)){
        printf("red ");
    }else if(IS_BLACK(b)){
        printf("black ");
    }
    f(b->key);
    rbt_preorder(b->left, f);
    rbt_preorder(b->right, f);
}

rbt rbt_free(rbt b){
    if (b== NULL){
        return b;
    }
    rbt_free(b->left);
    rbt_free(b->right);
    free(b->key);
    free(b);
    return b;
}

rbt rbt_delete(rbt b,char *str){
    rbt q;
    if (b == NULL){
        return b;
    }
    if (strcmp(str, b->key) == 0){
        if (b->left == NULL && b->right == NULL){
            free(b->key);
            free(b);
            b = NULL;
        }else if (b->left != NULL && b->right == NULL){
            free(b->key);
            free(b);
            b = b->left;
            
        }else if (b->right != NULL && b->left == NULL){
            free(b->key);
            free(b);
            b = b->right;
            
        }else if (b->right != NULL && b->left != NULL){
            q = b->right;
            while (q->left != NULL){
                q = q->left;
            }
            strcpy(b->key, q->key);
            b->right = rbt_delete(b->right, q->key);
        }
    }else if (strcmp(str, b->key) < 0){
        b->left = rbt_delete(b->left, str);
        return b;
    }else if (strcmp(str, b->key) > 0){
        b->right = rbt_delete(b->right, str);
        return b;
    }
    return b;
}

