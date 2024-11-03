#ifndef _tree_lib_
#define _tree_lib_
#include "../Stack/stack.h"

typedef struct _tree_ {
    void* data;
    struct _tree_ *left, *right;
} Tree;

Tree* new_node(void* data);

Tree* insert(Tree* root, void* data, int (*equal)(void* root_data, void* child_data));

int equal(void* data1, void* data2);

void preorder_rec(Tree* root);

void preorder_iter(Tree* root);

void inorder_rec(Tree* root);

void inorder_iter(Tree* root);

void postorder_rec(Tree* root);
void postorder_iter(Tree* root);

void levelorder(Tree* root);

void print_int(void* data);
#endif