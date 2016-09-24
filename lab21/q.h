#ifndef QUEUE_H_
#define QUEUE_H_
#include "graph.h"
typedef struct queue *queue;
typedef struct q_item *q_item;
extern queue queue_new();
extern void enqueue(queue q, vertex item);
extern vertex dequeue(queue q);
/*extern void queue_print(queue q);*/
extern int queue_size(queue q);
extern queue queue_free(queue q);
#endif
