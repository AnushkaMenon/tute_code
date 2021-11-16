#include <stdio.h>
#include <limits.h>

#include "min_list.h"

int iter_minimum(struct node* head);
int recursive_minimum(struct node* head);

int main(int argc, char *argv[]) {
    struct node *head = args_to_list(argc, argv);

    printf("Minimum is %d\n", iter_minimum(head));
    printf("Minimum is %d\n", recursive_minimum(head));

    return 0;
}

int iter_minimum(struct node *head) {
    if (head == NULL) {
        return INT_MAX;
    }
    
    struct node *curr = head;
    int min = curr->data;
    
    while (curr != NULL) {
        if (curr->data < min) {
            min = curr->data;
        }
        
        curr = curr->next;
    }
    
    return min;
}

int recursive_minimum(struct node *head) {
    if (head == NULL) {
        return INT_MAX;
    }
    
    int min = head->data;
    int new_min = recursive_minimum(head->next);
    
    if (new_min < min) {
        return new_min;
    } else {
        return min;
    }
}
