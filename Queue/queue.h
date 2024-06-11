/**
 * FIFO
 * */
#ifndef _Queue_
#define _Queue_
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


typedef struct _queue_
{
	void *data;
	struct _queue_ *next;
} Queue;

typedef struct _queueList_{
	struct _queueList_ *first;
	struct _queueList_ *last;
} QueueList;

typedef struct _user_{
	char *name;
	int age;
} User;

Queue* new_queue(void *data);
void enqueue(Queue* queue, void* data);
bool dequeue(Queue* queue);
Queue peek(Queue* queue);
void Display();


#endif
