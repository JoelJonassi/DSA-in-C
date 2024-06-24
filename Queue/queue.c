#include"queue.h"


Queue* new_queue(){
	Queue * new_element = (Queue*) malloc(sizeof(Queue));
	new_element->first = new_element->last = NULL;
	return new_element;
}

void enqueue(Queue* queue, void* data){
	QueueList* new = (QueueList*)malloc(sizeof(QueueList));
	new->data = data;
	new->next = queue->last;
	new->prev = NULL;

	if(!queue->first){
		queue->first = new;
		// new->prev = queue ->first;
	}else {
		queue->last->prev = new;
	}
	queue->last = new;
}

bool dequeue(Queue* queue){

	return true;
}

Queue peek(Queue* queue){

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
