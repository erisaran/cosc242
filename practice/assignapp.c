#include <stdio.h>
#include <stdlib.h>
#include "htable.h"
#include "mylib.h"
#include "container.h"

int main(void){
    htable h = htable_new(3877,FLEX_ARRAY);
    htable_insert(h, "hi");
    htable_insert(h, "hi");
    htable_insert(h, "qq");
    htable_insert(h, "swag");
    htable_print(h, stdout);
    if (htable_present(h, "adsfa") == 1){
        printf("true");
    }
    htable_free(h);

    return EXIT_SUCCESS;

}
