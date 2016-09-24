#include "q.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    queue q = queue_new();
    int i;
    for (i = 1; i< 50; i++){
        enqueue(q,i);
    }
    queue_print(q);
    dequeue(q);
    enqueue(q, 7);
    queue_print(q);
    queue_free(q);
    return EXIT_SUCCESS;
}
