#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma region ArrayStack
typedef struct _stackArray {
	int top;
	int size;
	int* s;
} StackArray;

/// <summary>
/// Push to the stack
/// </summary>
/// <param name="st"></param>
/// <param name="value"></param>
void pushArray(StackArray* st, int value) {
	if (isFullArray(*st)) {
		printf("Stack overflow");
	}
	else {
		st->top++;
		st->s[st->top] = value;
	}
}

/// <summary>
/// Pop to the stack
/// </summary>
/// <param name="st"></param>
/// <returns></returns>
int popArray(StackArray* st) {
	int x = -1;
	if (isEmptyArray(*st) ) {
		printf("Stack underflow");
	}
	else {
		x = st->s[st->top];
		st->top--;
	}
	return x;
}

/// <summary>
/// Verify if the stack is empty
/// </summary>
/// <param name="st"></param>
/// <returns></returns>
int isEmptyArray(StackArray st) {
	return st.top == -1 ? 1 : 0;
}

/// <summary>
/// Verify if the stack is full
/// </summary>
/// <param name="st"></param>
/// <returns></returns>
int isFullArray(StackArray st) {
	return st.top == st.size ? 1 : 0;
}

/// <summary>
/// Peek the element at the given index
/// </summary>
/// <param name="st"></param>
/// <param name="pos"></param>
/// <returns></returns>
int peekArray(StackArray st, int pos) {
	int x = -1;
	if (st.top - pos < 0) 
		printf("Invalid position");
	else 
		x = st.s[st.top - pos + 1];
	return x;
}
/// <summary>
/// Get to most top element on array stack
/// </summary>
/// <param name="st"></param>
/// <returns></returns>
int StackTopArray(StackArray st) {
	return st.top >= 0 ? st.s[st.top] : st.top;
}

#pragma endregion


#pragma region LinkedListStack
typedef struct _stackLinkedList {
	int value;
	struct _stackLinkedList *next;
} StackLinkedList, Node;

/// <summary>
/// Check if the list is empty
/// </summary>
/// <param name="st"></param>
/// <returns></returns>
int isEmpty(StackLinkedList* st) {
	return st == NULL ? 1 : 0;
}

/// <summary>
/// Create a Node 
/// </summary>
/// <param name="st"></param>
/// <param name="value"></param>
/// <returns></returns>
StackLinkedList* createNode(StackLinkedList* st, int value) {
	st = (StackLinkedList*)malloc(sizeof(StackLinkedList));
	st->value = value;
	st->next = NULL;
	return st;
}

/// <summary>
/// Push the element to the stack
/// </summary>
/// <param name="st"></param>
/// <param name="value"></param>
/// <returns></returns>
StackLinkedList* push(StackLinkedList* st, int value) {
	if (st == NULL) {
		st = createNode(st, value);
	}
	else {
		StackLinkedList* newNode = NULL;
		newNode = createNode(newNode, value);
		newNode->next = st;
		st = newNode;
	}
	return st;
}

/// <summary>
/// Pop the element to the stack
/// </summary>
/// <param name="st"></param>
/// <returns></returns>
int pop(StackLinkedList* st) {
	int x = -1;
	StackLinkedList* auxNode;
	if (isEmpty(st)) {
		printf("Stack is underflow");
	}
	else {
		x = st->value;
		auxNode = st;
		st = st->next;
		free(auxNode);
	}
	return x;
}


/// <summary>
/// Get the most top element to the stack
/// </summary>
/// <param name="st"></param>
/// <returns></returns>
int StackTop(StackLinkedList st) {
	if(isEmpty(&st))
		return -1;
	return st.value;
}

/// <summary>
/// Get the element at the given position
/// </summary>
/// <param name="st"></param>
/// <param name="pos"></param>
/// <returns></returns>
int peek(StackLinkedList st, int pos) {
	StackLinkedList* node = &st;
	if (isEmpty(&st))
		return -1;
	for (int i = 0; i < pos && node != NULL; i++) {
		node = node->next;
	}
	return node != NULL ? node->value : -1;
}

#pragma endregion

#pragma region StackExecise
//Matching parenthesis
//Compare the following paramenters with 
typedef struct _stack {
	int top;
	int size;
	char *s;
}Stack;

int isEmptyString(Stack st) {
	if (st.top == -1)
		return 1;
	return 0;
}

int isFullString(Stack st) {
	if (st.top == st.size - 1)
		return 1;
	return 0;
}

void pushString(Stack *st, char c) {
	if (isFullString(*st))
		printf("Stack overflow\n");
	else{
		st->top++;
		st->s[st->top] = c;
	}
}

int popString(Stack* st) {
	int x = -1;
	if (isEmptyString(*st))
		printf("Stack underflow\n");
	else {
		x = st->s[st->top];
		st->top--;
	}
	return x;
}

int isBalacend(Stack stack, char* exp) {
	for (int i = 0; exp[i] != '\0'; i++) {
		if (exp[i] == '(' || exp[i] == ')') {
			if (exp[i] == '(')
				pushString(&stack, exp[i]);
			else if (exp[i] == ')') {
				if (isEmptyString(stack))
					return 0;
				popString(&stack);
			}
		}
		if (exp[i] == '{' || exp[i] == '}') {
			if (exp[i] == '{')
				pushString(&stack, exp[i]);
			else if (exp[i] == '}') {
				if (isEmptyString(stack))
					return 0;
				popString(&stack);
			}
		}
		if (exp[i] == '[' || exp[i] == ']') {
			if (exp[i] == '[')
				pushString(&stack, exp[i]);
			else if (exp[i] == ']') {
				if (isEmptyString(stack))
					return 0;
				popString(&stack);
			}
		}
	}
	return isEmptyString(stack) ? 1 : 0;
}

#pragma region
int main() {

	StackArray st = { .top = -1, .size = 5,  };
	st.s = (int*)malloc(st.size * sizeof(int));
	pushArray(&st, 1);
	pushArray(&st, 15);
	pushArray(&st, 8);
	popArray(&st);
	printf("peek %d at index %d\n", peekArray(st, 0), 0);
	printf("stack top = %d\n", StackTopArray(st));
	
	StackLinkedList* stl = NULL;
	stl = push(&stl, 4);
	stl = push(&stl, 5);
	stl = push(&stl, 6);
	pop(stl);
	printf("stack top = %d\n", StackTop(*stl));
	printf("peek %d at index %d\n", peek(*stl, 0), 0);

	// Matching parethensis
	char str[50] = "(((2+4)({[]})([8*8])))";
	Stack stmatch = { .top = -1, .size = strlen(str), .s = (char*)malloc(st.size * sizeof(char))};
	
	printf("is balanced : %s", isBalacend(stmatch, str) ? "true" : "false");

}