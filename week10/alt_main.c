#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// Alternative solution for the pancake exercise (main.c)
// Relies on you having a get_data() function available in list.h:
// Returns the data of the given list node
/*  char *get_data(struct node *n) {
        if (n == NULL) {
            return NULL;
        }
        
        return n->data;
}*/

void handle_command(struct list *pancake, char command);

int main(void) {
    struct list *pancake = create_list();

    char command;
    while (scanf(" %c", &command) == 1) {
        handle_command(pancake, command);
    }
    return 0;
}

// Handles a command
void handle_command(struct list *pancake, char command) {
    char extra_data[MAX_STR_LENGTH];

    // TODO: Finish this function. Add more command conditions!
    //
    // Important commands:
    // - 'a' <name>: place new pancake onto pancake stack
    // - 'e':        eat top pancake
    // - 'p':        print pancake stack
    //
    if (command == 'a') {
        fgets(extra_data, MAX_STR_LENGTH, stdin);
        push_head(pancake, extra_data);
        printf("Added: %s", extra_data);
    } else if (command == 'e') {
        struct node *top_pancake = pop_front(pancake);
        
        if (top_pancake == NULL) {
            printf("The customer has reached the plate! You cannot eat that!\n");
        } else {
            printf("The customer has eaten %s\n", get_data(top_pancake));
        }
    } else if (command == 'p') {
        print_list(pancake);
    }
}
