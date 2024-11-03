#include <stdio.h>
#include "tree.h"
int main()
{
    Stack* stl = NULL;
    User* user = (User*)malloc(sizeof(User));
    user->name = "Joel Jonassi";
    user->age = 25;
    User* user1 = (User*)malloc(sizeof(User));
    user1->name = "Maria Joana";
    user1->age = 24;
    stl = push(stl, user1);
    display(top(*stl));

    Tree* tree =  NULL;
    tree = insert(tree, (void*)1, &equal);
    tree = insert(tree, (void*)2, &equal);
    tree = insert(tree, (void*)3, &equal);
    tree = insert(tree, (void*)4, &equal);
    tree = insert(tree, (void*)5, &equal);
    tree = insert(tree, (void*)20, &equal);
    tree = insert(tree, (void*)21, &equal);
    tree = insert(tree, (void*)15, &equal);

    puts("Inorder");
    inorder_rec(tree);
    puts("\nPreorder Recursive");
    preorder_rec(tree);
    puts("\nPreorder Iterative");
    preorder_iter(tree);
    puts("\nPostorder");
    postorder_rec(tree);
    return 0;
}
