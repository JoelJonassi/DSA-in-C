#include"queue.h"


Queue* new_queue(){
	Queue * new_element = (Queue*) malloc(sizeof(Queue));
	new_element->first = new_element->last = NULL;
	return new_element;
}

void enqueue(Queue* queue, void* data){
	QueueList* new = (QueueList*)malloc(sizeof(QueueList));
	new->data = data;
	new->prev = queue->last;
	new->next = NULL;

	if(!queue->first){
		queue->first = new;
	}else {
		queue->last->next = new;
	}
	
	queue->last = new;
	
}

void* dequeue(Queue* queue){
	void* data = NULL;
	assert(queue);
	if(queue->first == NULL)
		return data;
	data = queue->first->data;
	QueueList* second = queue->first->next;
	if(second){
		queue->first = NULL;
	}else{
		queue->last = NULL;
	}
	free(queue->first);
	queue->first = second;

	return data;
}

void* peek(Queue* queue){
	return queue->first->data;
}

void display(void *data){
	if(data == NULL) return;
	User* user = (User*) data;
	if(user != NULL){
		printf("name %s \nAge %d\n", user->name, user->age);
	}else{
		printf("Error casting...");
	}
}

void display_list(Queue* queue, void (*display)(void* data)){
	QueueList* lst = queue->first;
	while(lst){
		display(lst->data);
		lst = lst->next;
	}
}
