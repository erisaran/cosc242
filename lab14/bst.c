#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "mylib.h"

struct bst_node { /* should live in bst.c */
    char *key;
    bst left;
    bst right;
};

bst bst_new(){
    return NULL;
}

int bst_search(bst b, char *key){
    if (b == NULL){
        return 0;
    }else if (strcmp(key,b->key) == 0){
        return 1;
    }else if (strcmp(key,b->key) < 0){
        return bst_search(b->left, key);
    }else if (strcmp(key,b->key) > 0){
        return bst_search(b->right, key);
    }
    return 0;
}

bst bst_insert(bst b, char *key){
    if (b == NULL){
        b = emalloc(sizeof *b);
        b->key = emalloc((strlen(key)) + 1 * sizeof key[0]);
        strcpy(b->key, key);
        return b;
    }else if (strcmp(b->key,key) == 0){
        return b;
    }else if (strcmp(key,b->key) < 0){
        b->left = bst_insert(b->left, key);
        return b;
    }else if (strcmp(key,b->key) > 0){
        b->right = bst_insert(b->right, key);
        return b;
    }
    return b;
    
}

void bst_inorder(bst b, void f(char *s)){
    if (b == NULL){
        return;
    }
    bst_inorder(b->left, f);
    f(b->key);
    bst_inorder(b->right,f);
}

void bst_preorder(bst b, void f(char *s)){
    if (b == NULL){
        return;
    }
    f(b->key);
    bst_preorder(b->left, f);
    bst_preorder(b->right, f);
}

bst bst_free(bst b){
    if (b== NULL){
        return b;
    }
    bst_free(b->left);
    bst_free(b->right);
    free(b->key);
    free(b);
    return b;
}

bst bst_delete(bst b,char *str){
    bst q;
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
            b->right = bst_delete(b->right, q->key);
        }
    }else if (strcmp(str, b->key) < 0){
        b->left = bst_delete(b->left, str);
        return b;
    }else if (strcmp(str, b->key) > 0){
        b->right = bst_delete(b->right, str);
        return b;
    }
    return b;
}

