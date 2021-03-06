#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue-llist.h"

typedef struct q_item *q_item;

struct q_item {
    double item;
    q_item next;
};

struct queue {
    q_item first;
    q_item last;
    int length;
};

queue queue_new() {
    queue q = emalloc(sizeof *q);
    q->first = NULL;
    q->last = NULL;
    q->length = 0;
    return q;
}

void enqueue(queue q, double item) {
    q_item i = emalloc(sizeof *i);
    i->item = item;
    i->next = NULL;
    if (q->length == 0) {
        q->first = i;
    } else {
        q->last->next = i;
    }
    q->last = i;
    q->length++;
}

double dequeue(queue q) {
    double item;
    q_item dead;
    if (q->length == 0){
        return 0;
    }
    item = q->first->item;
    dead = q->first;
    q->first = q->first->next;
    q->length--;
    free(dead);
    return item;
}

void queue_print(queue q) {
    /* print queue contents one per line to 2 decimal places */
    q_item qi = q->first;
    while (qi != NULL){
        printf("%.2f\n",qi->item);
        qi = qi->next;
    }
}

void queue_print_info(queue q) {
    if (q->length == 0) {
        printf("The queue is empty\n");
    } else {
        printf("first %.2f, last %.2f, length %d\n", q->first->item,
               q->last->item, q->length);
    }
}

int queue_size(queue q) {
    return q->length;
}

/*void queue_free_aux(q_item i) {
  }*/

queue queue_free(queue q) {
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
