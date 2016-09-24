#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "q.h"

struct queue {
    double *items;
    int head;
    int capacity;
    int num_items;
};

queue queue_new(){
    queue q = emalloc(sizeof *q);
    q->capacity = 5;
    q->head = 0;
    q->num_items = 0;
    q->items = emalloc(q->capacity * sizeof q->items[0]);
    return q;
}

void enqueue(queue q, double item){
    if (q->num_items == q->capacity){
        return;
    }
    q->items[(q->head + q->num_items) % q->capacity] = item;
    q->num_items ++;
}

double dequeue(queue q){
    double item;
    if (q->num_items == 0){
        return 0;
    }
    item = q->items[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->num_items --;
    return item;
}

void queue_print(queue q){
    int i;
    for (i = 0; i < q->num_items; i ++){
        printf("%f\n", q->items[(q->head + i) % q->capacity]);
    }
    printf("\n");
}

int queue_size(queue q){
    return q->num_items;
}

queue queue_free(queue q){
    free(q->items);
    free(q);
    return q;
}
