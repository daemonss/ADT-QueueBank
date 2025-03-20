#ifndef QUEUE_H
#define QUEUE_H

#include "linked.h"
#include "boolean.h"

typedef LinkedList Queue;

// Deklarasi fungsi
void CreateQueue(Queue *Q);
boolean isEmptyQueue(Queue Q);
boolean isFull(Queue Q);
void EnQueue(Queue *Q, int X);
void DeQueue(Queue *Q, int *X);
int PanjangQueue(Queue Q);

#endif