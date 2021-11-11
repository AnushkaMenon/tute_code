// An explanation of how to copy linked lists
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

// Create a copy of a linked list, and return the new list's head
struct node *copy(struct node *old_head) {
    /*
        --------------------------------------------------------------------
        first, need to handle the case where old_head is NULL (i.e. there
         are no items in the provided linked list)
            in this case, we can just return NULL because a copy of a NULL
             list is just NULL
        --------------------------------------------------------------------     

        if (old_head == NULL) {
            return NULL;
        }

        --------------------------------------------------------------------
        next, we want to loop over all of the nodes in the provided linked
         list and copy each node
            copying a node will involve creating a new node using malloc
                -> we can use the create_node() function to do this
        --------------------------------------------------------------------

        struct node *curr = old_head;
        while (curr != NULL) {
            struct node *new_node = create_node(curr->data);
            curr = curr->next;
        }

        --------------------------------------------------------------------
        this will create a copy of each node in the provided linked list,
         but it won't actually link them up together
        
        if we have a list:  (1) -> (2) -> X
         once we create node (2), we need to somehow keep track of (1) so
         that we can set (1)->next = (2)

        to do this, we can use another pointer to store the previous node to
         the one that we are trying to copy 
        --------------------------------------------------------------------

        struct node *prev = NULL;
        struct node *curr = old_head;

        while (curr != NULL) {
            struct node *new_node = create_node(curr->data);

            if (prev != NULL) {
                prev->next = new_node;
            }

            prev = new_node;
            curr = curr->next;
        }

        --------------------------------------------------------------------
        if our linked list looks like this:
                (1) -> (2) -> (3) -> (4) -> X

        our pointers would move like this as we progressed through our loop
        (p = prev, c = curr):

             X  (1) -> (2) -> (3) -> (4) -> X  
             p   c

             X  (1) -> (2) -> (3) -> (4) -> X  
                 p      c

            X  (1) -> (2) -> (3) -> (4) -> X  
                       p      c

            X  (1) -> (2) -> (3) -> (4) -> X  
                              p      c

        at the end of the loop, prev and curr's values would be:
            X  (1) -> (2) -> (3) -> (4) -> X  
                                     p     c

        (note that (4) would not be linked to NULL, but in this case we assume
        that (4)->next has already been set to NULL in create_node())

        the last thing to do is to return the head of our new linked list,
         however we haven't stored the head anywhere!
            -> we can create a new pointer called head to store the head of
                our new list
               initially, we can set the head to be NULL
               then, in our loop, if the node we create should be the first
                node in the list, we can set head to be that node
                -> we know we're on the first node if prev == NULL!
        --------------------------------------------------------------------

        struct node *prev = NULL;
        struct node *curr = old_head;

        struct node *head = NULL;

        while (curr != NULL) {
            struct node *new_node = create_node(curr->data);
            
            if (prev != NULL) {
                head = new_node;                
            } else {
                prev->next = new_node;
            }

            prev = new_node;
            curr = curr->next;
        }
        
        --------------------------------------------------------------------
        that's it! the last thing to do is just to return the head of our new
         linked list :)
        --------------------------------------------------------------------
    */
    /*
        --------------------------------------------------------------------
        FINISHED CODE:
        --------------------------------------------------------------------
    */
        if (old_head == NULL) {
            return NULL;
        }

        struct node *prev = NULL;
        struct node *curr = old_head;

        struct node *head = NULL;

        while (curr != NULL) {
            struct node *new_node = create_node(curr->data);
            
            if (prev == NULL) {
                head = new_node;                
            } else {
                prev->next = new_node;
            }

            prev = new_node;
            curr = curr->next;
        }
        
        return head;
}