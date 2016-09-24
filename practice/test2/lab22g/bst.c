#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "mylib.h"
#include <string.h>

struct bstnode {
    char *key;
    bst left;
    bst right;
};

bst bst_new(){
    return NULL;
}

int bst_search(bst b, char *str){
    if (b == NULL){
        return 0;
    }else if (strcmp(str,b->key) == 0){
        return 1;
    }else if (strcmp(str,b->key) < 0){
        return bst_search(b->left,str);
    }else if (strcmp(str,b->key) > 0){
        return bst_search(b->right,str);
    }
    return 0;
}

bst bst_insert(bst b, char *str){
    if (b == NULL){
        b = emalloc(sizeof *b);
        b->key = emalloc((strlen(str)+1) * sizeof str[0]);
        strcpy(b->key, str);
        b->left = NULL;
        b->right = NULL;
    }else if (strcmp(str,b->key) < 0 ){
        b->left = bst_insert(b->left,str);
    }else if (strcmp(str,b->key) > 0){
        b->right = bst_insert(b->right, str);
    }
    return b;
}

void bst_inorder(bst b, void f(char *str)){
    if (b == NULL){
        return;
    }
    bst_inorder(b->left,f);
    f(b->key);
    bst_inorder(b->right,f);
}

void bst_preorder(bst b, void f(char *str)){
    if (b == NULL){
        return;
    }
    
    bst_preorder(b->left,f);
    bst_preorder(b->right,f);
    f(b->key);
}

bst bst_free(bst b){
    if (b == NULL){
        return b;
    }
    bst_free(b->left);
    bst_free(b->right);
    free(b->key);
    free(b);
    return b;
}
