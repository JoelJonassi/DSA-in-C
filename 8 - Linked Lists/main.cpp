/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author Asus
 * \date   September 2023
 *********************************************************************/

#include<stdio.h>      
#include<stdlib.h> 
#include <assert.h> 

typedef struct _node {
	int data;
	struct _node* next;
} Node, *NodePtr;

typedef struct _list {
	Node* first;
	Node* last;
} *ListPtr, List;



/**
 * .
 * 
 * \return 
 */
ListPtr NewList() {
	ListPtr list = (ListPtr)malloc(sizeof(List));
	assert(list);
	list->first = list->last = NULL;
	return list;
}

/**
 * .
 * 
 * \param value
 * \return 
 */
Node* NewNode(int value) {
	Node* node = (Node*)malloc(sizeof(Node));
	assert(node);
	node->data = value;
	node->next = NULL;
	return node;
}

Node* NewEmptyNode() {
	Node* node = (Node*)malloc(sizeof(Node));
	assert(node);
	node->next = NULL;
	return node;
}

/**
 * .
 * 
 * \param list
 * \return 
 */
int len(ListPtr list) {
	NodePtr first = list->first;
	int count = 0;
	while (first) {
		count++;
		first = first->next;
	}
	return count;
}

/**
 * Insert on head takes O(1).
 * 
 * \param first
 * \param node
 * \return 
 */
void HeadInsertNode(ListPtr list, NodePtr node) {
	node->next = list->first;
	list->first = node;
	if (!list->last) {
		list->last = node;
	}
}
/**
 * Head insert 
 * O(n) depend the position we want to insert.
 * 
 * \param first
 * \param node
 * \param pos
 * \return 
 */
NodePtr HeadInsertNodePosition(NodePtr first, NodePtr node, int pos) {
	if (first == NULL) return first;
	NodePtr auxFirst = first;
	int i = 1;
	while (auxFirst != NULL && i < pos) {

		auxFirst = auxFirst->next;
		i++;
	}
	node->next = auxFirst->next;
	auxFirst->next = node;
	return first;
}

/**
 * .
 * 
 * \param list
 * \param node
 */
void InsertInSortedList(ListPtr list, NodePtr node) {
	NodePtr p = list->first, q = NULL;
	if (p == NULL)
		list->first = node;
	else {
		while (p && p->data < node->data) {
			q = p;
			p = p->next;
		}
		if (p == list->first) {
			node->next = list->first;
			list->first = node;
		}
		else {
			node->next = q->next;
			q->next = node;
		}
	}
}

/**
 * .
 * 
 * \param list
 */
void RemoveDuplicate(ListPtr list) {
	NodePtr q = list->first;
	NodePtr p = q->next;
	while (q->next != NULL) {
		if (q->data == p->data) {
			q->next = p->next;
			free(p);
			p = q->next;
		}
		else {
			q = p;
			p = p->next;
		}
	}
}
/**
 * Reverse elements in linked list.
 * 
 * \param list
 */
void ReverseElement(ListPtr list) {
	int i = 0, *arr = (int*)malloc(len(list) * sizeof(int));
	NodePtr first = list->first;
	while (first != NULL) {
		arr[i++] = first->data;
		first = first->next;
	}
	i--;
	first = list->first;
	while (first != NULL) {
		first->data = arr[i--];
		first = first->next;
	}
}

/**
 * Reverse using sliding pointers.
 * 
 * \param list
 */
void ReversePointers(ListPtr list) {
	NodePtr first = list->first, p1 = NULL, p2=NULL, p3 = first;
	while (p3 != NULL) {
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
		p2->next = p1;
	}
	list->first = p2;
}

/**
 * .
 * 
 * \param list1
 * \param list2
 */
void Concatenate(ListPtr list1, ListPtr list2) {
	NodePtr firstl1 = list1->first, firstl2 = list2->first;
	while (firstl1->next) {
		firstl1 = firstl1->next;
	}
	firstl1->next = firstl2;
}

/**
 * Solve this MEthod.
 * 
 * \param list1
 * \param list2
 * \return 
 */
NodePtr Merge(ListPtr list1, ListPtr list2) {
	NodePtr first = list1->first, second = list2->first, third = NULL, last = NULL;

	if (first->data < second->data) {
		third = last = first;
		first = first->next;
		last->next = NULL;
		
	}
	else  {
		third = last = second;
		second = second->next;
		last->next = NULL;
		printf("%p %p %p\n", third, last, first);

	}
	while (first && second) {
		if (first->data < second->data) {
			last->next = first;
			last = first;
			first = first->next;
			last->next = NULL;
		}
		else  {
			last->next = second;
			last = second;
			second = second->next;
			last->next = NULL;
		}
	}
	if (first != NULL && last != NULL) {
		last->next = first;
	}
	else if (second != NULL && last != NULL) {
		last->next = second;
	}
		

	return third;
	
}

/**
 * Recursive reverse sliding pointers.
 * 
 * \param list
 * \param p1
 * \param p2
 */
void RecursiveReversePointers(ListPtr list, NodePtr p1, NodePtr p2) {
	if (p2 != NULL) {
		RecursiveReversePointers(list, p2, p2->next);
		p2->next = p1;
	}
	else {
		list->first = p1;
	}
}

/**
 * O(1).
 * 
 * \param list
 * \param node
 */
void TailInsert(ListPtr list, NodePtr node) {
	if (list->last) {
		list->last->next = node;
		list->last = node;
	}else{
		list->first = list->last = node;
	}
}

/**
 * .
 * 
 * \param first
 */
void Display(NodePtr first) {
	while (first != NULL) {
		printf("%d\n", first->data);
		first = first->next;
	}
}

/**
 * .
 * 
 * \param first
 */
void DisplayRecursive(NodePtr first) {
	if (first == NULL)
		return;
	else {
		printf("%d\n", first->data);
		DisplayRecursive(first->next);
	}
}


/**
 * Get max of linked list.
 * 
 * \param list
 * \return 
 */
int Max(ListPtr list) {
	NodePtr first = list->first;
	int max = list->first->data;
	while (first != NULL) {
		if (first->data > max) {
			max = first->data;
		}
		else {
			first = first->next;
		}
	}
	return max;
}

/**
 * .
 * 
 * \param list
 * \param key
 * \return 
 */
NodePtr Search(ListPtr list, int key) {
	NodePtr node = list->first;
	while (node != NULL) {
		if (node->data == key)
			return node;
		node = node->next;
	}
	return NULL;
}

/**
 * .
 * 
 * \param list
 * \param key
 * \return 
 */
NodePtr SearchRecursive(NodePtr list, int key) {
	if (list == NULL || list->data == key)
		return list;
	return SearchRecursive(list->next, key);
}

//NodePtr 



int main() {
	ListPtr list = NewList(), list2 = NewList(), list3 = NULL;
	NodePtr p1 = NULL, p;
	HeadInsertNode(list, NewNode(98));
	HeadInsertNode(list, NewNode(90));
	HeadInsertNode(list, NewNode(40));
	HeadInsertNode(list, NewNode(25));
	HeadInsertNode(list, NewNode(12));

	HeadInsertNode(list2, NewNode(43));
	HeadInsertNode(list2, NewNode(21));
	HeadInsertNode(list2, NewNode(16));
	HeadInsertNode(list2, NewNode(10));
	HeadInsertNode(list2, NewNode(10));

	//HeadInsertNodePosition(first, NewNode(12), 4);
	//TailInsert(list, NewNode(98));
	//InsertInSortedList(list, NewNode(50));
	//RemoveDuplicate(list);
	//RecursiveReversePointers(list, p1, list->first);
	printf("List1\n");
	Display(list->first);
	printf("List2\n");
	Display(list2->first);

	//Concatenate(list, list2);
	p = Merge(list, list2);

	printf("Merge list\n");
	Display(p);

	printf("Search : %d\n", SearchRecursive(list->first, 3) == NULL ? -1 : SearchRecursive(list->first, 3)->data);
	printf("Max : %d\n", Max(list));
	Display(list->first);

	return 0;
}
