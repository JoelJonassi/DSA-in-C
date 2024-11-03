#include <stdio.h>
#include "stack.h"

int main() {
    Stack* stl = NULL;
    User* user = (User*)malloc(sizeof(User));
    user->name = "Joel Jonassi";
    user->age = 25;
    User* user1 = (User*)malloc(sizeof(User));
    user1->name = "Maria Joana";
    user1->age = 24;

    User* user2 = (User*)malloc(sizeof(User));
    user2->name = "Luís Costa";
    user2->age = 24;
    stl = push(stl, user1);
    display(top(*stl));
    stl = push(stl, user2);
    display(top(*stl));
    stl = push(stl, user);
    display(top(*stl));
    display(pop(stl));

    free(user->name);
    free(user1->name);
    free(user2->name);


    return 0;
}
