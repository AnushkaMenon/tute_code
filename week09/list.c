// Program to do various linked list exercises
// Written by <your-name> (zID) on <date>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct node *create_node(int data);

int main(void) {
    struct node *head1 = NULL;
    
    int i = 0;
    while (i < 6) {
        head1 = add_last(head1, i);
        i++;
    }
    
    printf("List1 is:\n");
    print_list(head1);
    
    struct node *head2 = NULL;
    
    i = 3;
    while (i < 7) {
        head2 = add_last(head2, i);
        i++;
    }
    
    printf("List2 is:\n");
    print_list(head2);
    
    printf("\nCopy of List1 is:\n");
    print_list(copy(head1));
    
    printf("\nIntersection of List1 and List2 is:\n");
    struct node *new = set_intersection(head1, head2);
    print_list(new);
    
    return 0;
}

/** PRESCRIBED FUNCTIONS **/

struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    
    return new_node;
}

struct node *add_last(struct node *head, int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    // Return new if linked list is initially empty
    if (head == NULL) {
        return new;
    }

    // Otherwise, loop to end of list and add node.
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new;

    // We are inserting at the end --> head will not change
    return head;
}

void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}

// copy the whole list using malloc, then return the head of the
//  new list
struct node *copy(struct node *list) {
    if (list == NULL) {
        return NULL;
    }
    
    // old:  1 -> 2 -> 3 -> 4 -> X
    //                      c
    // copy: 1 -> 2 -> 3
    //                 p
    
    struct node *new_head = create_node(list->data);
    
    struct node *new_prev = new_head;
    struct node *curr = list->next;
    
    while (curr != NULL) {
        struct node *copy_node = create_node(curr->data);
        new_prev->next = copy_node;
        
        new_prev = new_prev->next;
        curr = curr->next;
    }
    
    return new_head;
}

struct node *list_append(struct node *first_list, struct node *second_list) {
    return NULL;
}

int identical(struct node *first_list, struct node *second_list) {
    return 5841;
}

struct node *set_intersection(
    struct node *first_list,
    struct node *second_list
) {

    struct node *head = NULL;

    // s:  1 -> 2 -> 3 -> 4 -> 5 -> X
    //                         s
    // f:  3 -> 4 -> 5 -> 6 -> 7 -> X
    //                    f
    // 3 -> 4 -> 5 -> X
    
    struct node *first_curr = first_list;
    struct node *second_curr = second_list;
    
    while (first_curr != NULL && second_curr != NULL) {
        if (first_curr->data == second_curr->data) {
           head = add_last(head, first_curr->data);
           first_curr = first_curr->next;
           second_curr = second_curr->next; 
        } else if (first_curr->data < second_curr->data) {
            first_curr = first_curr->next;
        } else if (second_curr->data < first_curr->data) {
            second_curr = second_curr->next;
        }
    }
    
    return head;
}










