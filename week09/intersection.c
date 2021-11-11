// An explanation of how to find the intersection of two sorted
//  linked lists
// Written by Anushka, Nov. 2021
struct node {
    int data;
    struct node *next;
};

// Create a node and return a pointer to it
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

//  Creates a node, adds a node to the end of a given list
//   and returns the new head of the list
struct node *add_last(struct node *head, int data) {
    struct node *new_node = create_node(data);

    // If the list is empty, new_node will be the new head of
    //  the list
    if (head == NULL) {
        return new_node;
    }

    // Find the last node of the list
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    
    // Link last node of the list to the new node
    curr->next = new_node;

    return head;
}

// Create a new linked list which contains the elements which were
//  common to both set1 and set2
struct node *set_intersection(struct node *set1, struct node *set2) {
    /*
        --------------------------------------------------------------------
        METHOD1:
        -------

        we want to go through each node in set1 and check whether any of
         the nodes in set2 have the same value

        to do this, we can use a 2D while loop!
        --------------------------------------------------------------------
        
        struct node *first_ptr = set1;
        
        while (first_ptr != NULL) {

            struct node *second_ptr = set2;
            while (second_ptr != NULL) {

                if (first_ptr->data == second_ptr->data) {
                    // we want to add this node to our list!
                }

                second_ptr = second_ptr->next;
            }

            first_ptr = first_ptr->next;
        }

        --------------------------------------------------------------------
        now, we need to actually handle copying matching elements and adding
         them to our new list

        to do this, we first need to create a pointer to the head of our
         new list -> we can just initialize this to be NULL

        then, we can call add_last() to add a new node to the end of our
         list
            -> add_last() will return the new head of the list, so remember
               to reassign head to be whatever value add_last() returned!
        --------------------------------------------------------------------

        struct node *head = NULL;
        struct node *first_ptr = set1;
        
        while (first_ptr != NULL) {

            struct node *second_ptr = set2;
            while (second_ptr != NULL) {

                if (first_ptr->data == second_ptr->data) {
                    head = add_last(head, first_ptr->data);
                }

                second_ptr = second_ptr->next;
            }

            first_ptr = first_ptr->next;
        }

        --------------------------------------------------------------------
        lastly, we just need to return the head of our new list!
        --------------------------------------------------------------------
    */
    /*
        --------------------------------------------------------------------
        METHOD 1 FINISHED CODE:
        --------------------------------------------------------------------
    */
        struct node *head = NULL;
        struct node *first_ptr = set1;
        
        while (first_ptr != NULL) {

            struct node *second_ptr = set2;
            while (second_ptr != NULL) {

                if (first_ptr->data == second_ptr->data) {
                    head = add_last(head, first_ptr->data);
                }

                second_ptr = second_ptr->next;
            }

            first_ptr = first_ptr->next;
        }
        
        return head;

    /*
        --------------------------------------------------------------------
        METHOD2:
        -------

        let's first write a loop to go through the nodes in set1 and set2 at
         the same time

        then, we can check if first_ptr's data is equal to second_ptr's data
        --------------------------------------------------------------------
        
        struct node *first_ptr = set1;
        struct node *second_ptr = set2;
        
        while (first_ptr != NULL && second_ptr != NULL) {
            if (first_ptr->data == second_ptr->data) {
                // add to new linked list
            }
        
            first_ptr = first_ptr->next;
            second_ptr = second_ptr->next;
        }

        --------------------------------------------------------------------
        the problem here is that this is how we are looping through our
         list (f = first_ptr, s = second_ptr):
        
         set1: (1) -> (2) -> (3) -> (4) -> X
                f
         set1: (3) -> (4) -> (5) -> (6) -> X 
                s

            ** 1 != 3 **

         set1: (1) -> (2) -> (3) -> (4) -> X
                       f
         set2: (3) -> (4) -> (5) -> (6) -> X 
                       s

            ** 2 != 4 **

         set1: (1) -> (2) -> (3) -> (4) -> X
                              f
         set2: (3) -> (4) -> (5) -> (6) -> X 
                              s

            ** 3 != 5 **

        ...and so on

        given that we know both set1 and set2 are in INCREASING order,
         instead, what we can do is this:
            -> if f == s,
                -> copy the node into our new linked list
                -> move both f and s to their next nodes
            -> if f < s (e.g if f is (2) and s is (4)),
                -> f's value MAY occur later in s's list - we don't know yet
                -> ONLY move f to the next node
            -> if s < f (e.g if s is (7) and f is (9)),
                -> s's value MAY occur later in f's list - we don't know yet
                -> ONLY move s to the next node

        this will result in this behaviour when looping:

         set1: (1) -> (3) -> (8) -> (9) -> X
                f
         set1: (2) -> (3) -> (6) -> (7) -> (8) -> (10) -> X 
                s

            ** 1 < 2: move f **

         set1: (1) -> (3) -> (8) -> (9) -> X
                       f
         set1: (2) -> (3) -> (6) -> (7) -> (8) -> (10) -> X
                s

            ** 3 > 2: move s **

         set1: (1) -> (3) -> (8) -> (9) -> X
                       f
         set1: (2) -> (3) -> (6) -> (7) -> (8) -> (10) -> X 
                       s

            ** 3 == 3: move both **

         set1: (1) -> (3) -> (8) -> (9) -> X
                              f
         set1: (2) -> (3) -> (6) -> (7) -> (8) -> (10) -> X
                              s

            ** 8 > 6: move s **

         set1: (1) -> (3) -> (8) -> (9) -> X
                              f
         set1: (2) -> (3) -> (6) -> (7) -> (8) -> (10) -> X
                                     s

            ** 8 > 7: move s **

         set1: (1) -> (3) -> (8) -> (9) -> X
                              f
         set1: (2) -> (3) -> (6) -> (7) -> (8) -> (10) -> X
                                            s

            ** 8 == 8: move both **

         set1: (1) -> (3) -> (8) -> (9) -> X
                                     f
         set1: (2) -> (3) -> (6) -> (7) -> (8) -> (10) -> X
                                                    s

            ** 9 < 10: move f **

         set1: (1) -> (3) -> (8) -> (9) -> X
                                           f
         set1: (2) -> (3) -> (6) -> (7) -> (8) -> (10) -> X
                                                    s

            ** f == NULL: exit loop **
        --------------------------------------------------------------------

        struct node *first_ptr = set1;
        struct node *second_ptr = set2;
        
        while (first_ptr != NULL && second_ptr != NULL) {
            if (first_ptr->data == second_ptr->data) {
                // add to new linked list

                first_ptr = first_ptr->next;
                second_ptr = second_ptr->next;
            } else if (first_ptr->data < second_ptr->data) {
                first_ptr = first_ptr->next;
            } else if (second_ptr->data < first_ptr->data) {
                second_ptr = second_ptr->next;
            }
        }

        --------------------------------------------------------------------
        lastly, if the two nodes are equal, we just need to actually copy
         the node to our new list

        to do this, we'll create a pointer called head to store the head of
         our list (we can set it to NULL initially)

        we can then call add_last() to actually add the node to our list
            -> since add_last() returns the new head of the list, make
               sure to assign to head add_last()'s return value!
        --------------------------------------------------------------------

        struct node *head = NULL;

        struct node *first_ptr = set1;
        struct node *second_ptr = set2;
        
        while (first_ptr != NULL && second_ptr != NULL) {
            if (first_ptr->data == second_ptr->data) {
                head = add_last(head, first_ptr->data);

                first_ptr = first_ptr->next;
                second_ptr = second_ptr->next;
            } else if (first_ptr->data < second_ptr->data) {
                first_ptr = first_ptr->next;
            } else if (second_ptr->data < first_ptr->data) {
                second_ptr = second_ptr->next;
            }
        }

        --------------------------------------------------------------------
        lastly, we just need to return the head of our new list!
        --------------------------------------------------------------------
    */
    /*
        --------------------------------------------------------------------
        METHOD 2 FINISHED CODE:
        --------------------------------------------------------------------
    */
        struct node *head = NULL;

        struct node *first_ptr = set1;
        struct node *second_ptr = set2;
        
        while (first_ptr != NULL && second_ptr != NULL) {
            if (first_ptr->data == second_ptr->data) {
                head = add_last(head, first_ptr->data);

                first_ptr = first_ptr->next;
                second_ptr = second_ptr->next;
            } else if (first_ptr->data < second_ptr->data) {
                first_ptr = first_ptr->next;
            } else if (second_ptr->data < first_ptr->data) {
                second_ptr = second_ptr->next;
            }
        }

        return head;
}