#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"


/// <summary>
/// Check if the list is empty
/// </summary>
/// <param name="st"></param>
/// <returns></returns>
bool isEmpty(Stack* st) {
    return st == NULL ? true : false;
}

/// <summary>
/// Create a Node
/// </summary>
/// <param name="st"></param>
/// <param name="value"></param>
/// <returns></returns>
Stack* createNode(Stack* st, void* data) {
    st = (Stack*)malloc(sizeof(Stack));
    st->data = data;
    st->next = NULL;
    return st;
}

/// <summary>
/// Push the element to the stack
/// </summary>
/// <param name="st"></param>
/// <param name="value"></param>
/// <returns></returns>
Stack* push(Stack* st, void* data) {
    if (st == NULL) {
        st = createNode(st, data);
    }
    else {
        Stack* newNode = NULL;
        newNode = createNode(newNode, data);
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
void* pop(Stack* st) {
    void* data = NULL;
    Stack* auxNode;
    if (isEmpty(st)) {
        printf("Stack is underflow");
    }
    else {
        data = st->data;
        auxNode = st;
        st = st->next;
        free(auxNode);
    }
    return data;
}


/// <summary>
/// Get the most top element to the stack
/// </summary>
/// <param name="st"></param>
/// <returns></returns>
void* top(Stack st) {
    if(isEmpty(&st))
        return NULL;
    return st.data;
}

/// <summary>
/// Get the element at the given position
/// </summary>
/// <param name="st"></param>
/// <param name="pos"></param>
/// <returns></returns>
void* peek(Stack st, int pos) {
    Stack* node = &st;
    if (isEmpty(&st))
        return NULL;
    for (int i = 0; i < pos && node != NULL; i++) {
        node = node->next;
    }
    return node != NULL ? node->data : NULL;
}

void display(void* data) {
    User* user = (User*)data;
    if(user!= NULL) {
        printf("Name: %s Age %d\n",user->name, user->age);
    }
}