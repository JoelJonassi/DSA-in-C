#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct _stack_ {
	void* data;
	struct _stack_ *next;
} Stack;

typedef struct _user_{
	char *name;
	int age;
} User;
/// <summary>
/// Check if the list is empty
/// </summary>
/// <param name="st"></param>
/// <returns></returns>
bool isEmpty(Stack* st);

/// <summary>
/// Create a Node
/// </summary>
/// <param name="st"></param>
/// <param name="value"></param>
/// <returns></returns>
Stack* createNode(Stack* st, void* data);

/// <summary>
/// Push the element to the stack
/// </summary>
/// <param name="st"></param>
/// <param name="value"></param>
/// <returns></returns>
Stack* push(Stack* st, void* data);

/// <summary>
/// Pop the element to the stack
/// </summary>
/// <param name="st"></param>
/// <returns></returns>
void* pop(Stack* st);

/// <summary>
/// Get the most top element to the stack
/// </summary>
/// <param name="st"></param>
/// <returns></returns>
void* top(Stack st);
/// <summary>
/// Get the element at the given position
/// </summary>
/// <param name="st"></param>
/// <param name="pos"></param>
/// <returns></returns>
void* peek(Stack st, int pos);

void display(void* data);
#pragma endregion


