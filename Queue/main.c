#include"queue.h"

int main(){
	User* user = (User*)malloc(sizeof(User));
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	user->name = "Joel Jonassi";
	user->age = 25;
	User* user1 = (User*)malloc(sizeof(User));
	user1->name = "Maria Joana";
	user1->age = 24;

	User* user2 = (User*)malloc(sizeof(User));
	user2->name = "Luís Costa";
	user2->age = 24;
	enqueue(queue, user);
	//enqueue(queue, user1);
	//enqueue(queue, user2);
	display_list(queue, &display);
	dequeue(queue);
	display(peek(queue));
	
	return 1;
}
