#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *insert_first(int data, struct node *next);
void print_list(struct node *head);

int main(void) {
    int i = 0;
    struct node *head = NULL;
    while (i < 10) {
        head = insert_first(i, head);
        i++;
    }
    
    print_list(head);
    
    // need to loop through the whole list to free each node
    struct node *curr = head;
    while (curr != NULL) {
        // save curr->next in a temporary variable because
        //  we can't access curr->next once we free curr
        struct node *temp = curr->next;
        free(curr);
        curr = temp;
    }
    
    return 0;
}

// Insert at the beginning of the linked list
struct node *insert_first(int data, struct node *next) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = next;

    return new;
}

void print_list(struct node *head) {
    struct node *curr = head;
    
    while (curr != NULL) {
        printf("[%d] -> ", curr->data);
        curr = curr->next;
    }
    
    printf("X\n");
}
