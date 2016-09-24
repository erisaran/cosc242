#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "q.h"

struct q_item {
    double item;
    q_item next;
};
struct queue {
    q_item first;
    q_item last;
    int length;
};

queue queue_new(){
    queue q = emalloc(sizeof *q);
    q->first = NULL;
    q->last = NULL;
    q->length = 0;
    return q;
}

void enqueue(queue q, double item){
    if (q->first == NULL){
        q->first = emalloc(sizeof *q->first);
        q->first->item = item;
        q->first->next = q->last;
        q->last = q->first;
    }else {
        q->last->next = emalloc(sizeof *q->last);
        q->last->next->next = NULL;
        q->last->next->item = item;
        q->last = q->last->next;
    }
    q->length ++;
}

double dequeue(queue q){
    double item;
    q_item dead;
    if (q->length == 0){
        return 0;
    }
    item = q->first->item;
    dead = q->first;
    q->first = q->first->next;
    q->length --;
    free(dead);
    return item;
}

void queue_print(queue q){
    q_item qi = q->first;
    while (qi != NULL){
        printf("%f\n",qi->item);
        qi = qi->next;
    }
    printf("\n");
}

int queue_size(queue q){
    return q->length;
}

queue queue_free(queue q){
    q_item qi = q->first;
    q_item qdead = qi;
    while (qi != NULL){
        qi = qi->next;
        free(qdead);
        qdead = qi;
    }
    free(q);
    return q;
}
