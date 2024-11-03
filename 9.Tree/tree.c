#include "tree.h"
#include<stdlib.h>
#include<stdio.h>

/**
 * Method to compare generic data and cast to integer
 * @param root_data data from a root child
 * @param child_data data to be inserted to the tree
 * @return Returns 1 if child_data is greater than root data
 * otherwise returns -1.
 */
int equal(void* root_data, void* child_data) {
    int aux_root_data = (int)root_data;
    int aux_child_data = (int)child_data;
    if(aux_root_data < aux_child_data)
        return 1; // rigth
    return -1; // left
}

/**
 * Method to create a space of memory to allocate a tree
 * @return Returns a sapce of memory created
 */
Tree* new_node(void* data) {
    Tree* new_root = (Tree*) malloc(sizeof(Tree));
    new_root->data = data;
    new_root->left=new_root->right = NULL;
    return new_root;
}


/**
 * Method to insert data to generic tree
 * @param root
 * @param data
 * @param equal
 * @return
 */
Tree* insert(Tree* root, void* data, int (*equal)(void* root_data, void* child_data)) {
    if(data == NULL) return root;
    if(root == NULL) {
        root = new_node(data);
        return root;
    }
    if(equal(root->data, data) > 0) {
        root->right = insert(root->right, data, equal);
    }else {
        root->left = insert(root->left, data, equal);
    }
    return root;
}

/**
 * Method to print integer data
 * @param data
 */
void print_int(void* data) {
    printf(" %d", (int)data);
}

/**
 *
 * @param root
 */
void preorder_rec(Tree* root) {
    if(root != NULL) {
        print_int(root->data);
        preorder_rec(root->left);
        preorder_rec(root->right);
    }
}

void preorder_iter(Tree* root) {
    Stack* st;
    while(root != NULL || !isEmpty(st)) {
        if(root != NULL) {
            print_int(root->data);
            st = push(st, root);
            root = root->left;
        }else {
            root = pop(st);
            print_int(root->data);
            root = root->right;
        }
    }
}

/**
 *
 * @param root
 */
void inorder_rec(Tree* root) {
    if(root != NULL) {
        inorder_rec(root->left);
        print_int(root->data);
        inorder_rec(root->right);
    }
}

void postorder_rec(Tree* root) {
    if(root != NULL) {
        postorder_rec(root->left);
        postorder_rec(root->right);
        print_int(root->data);
    }
}