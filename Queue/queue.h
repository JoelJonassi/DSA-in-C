/**
 * FIFO
 * */
#ifndef _Queue_
#define _Queue_
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


typedef struct _queueList_
{
	void *data;
	struct _queueList_ *next;
	struct _queueList_ *prev;
} QueueList;

typedef struct _queue_{
	struct _queueList_ *first;
	struct _queueList_ *last;
} Queue;

typedef struct _user_{
	char *name;
	int age;
} User;


Queue* new_queue();
void enqueue(Queue* queue, void* data);
bool dequeue(Queue* queue);
Queue peek(Queue* queue);
void display(void* data);
void display_list(Queue* queue, void (*display) (void* data));


#endif
