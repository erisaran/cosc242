#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "htable.h"

int main(int argc, char **argv) {
    htable h = htable_new(18143);
    char word[256];
    if (argc > 0){
        h = htable_new(atoi(argv[1]));
    }
    while (getword(word, sizeof word, stdin) != EOF) {
        htable_insert(h, word);
    }
    
    htable_print(h, stdout);
    htable_free(h);
    return EXIT_SUCCESS;
}
