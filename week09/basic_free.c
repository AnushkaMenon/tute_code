// Simple program to demonstrate how to use free()
// Written by Anushka, Nov. 2021

#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main(void) {

    int *my_int = malloc(sizeof(int));
    
    struct node *my_node = malloc(sizeof(struct node));
    
    free(my_node);
    
    free(my_int);

    return 0;
}
