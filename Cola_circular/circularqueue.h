#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef struct circularqueuearray {
    char data[TAM];
    int head;
    int tail;
    int len;
} cqueue;

void init(cqueue *q);
void print(cqueue *q);
bool is_empty(cqueue *q);
bool is_full(cqueue *q);
void enqueue(cqueue *q, char d);
void dequeue(cqueue *q);
char first(cqueue *q);
char last(cqueue *q);
void empty(cqueue *q);

#endif