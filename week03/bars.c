// Printing out a bar pattern using a 2D while loop
// Anushka, Sep. 2021

#include <stdio.h>

int main(void) {

    int size;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    int row = 0;
    while (row < size) {
        int col = 0;
        
        while (col < size) {
            if (col % 2 == 0) {
                printf("-");
            } else {
                printf("*");
            }
            
            col++;
        }
        
        printf("\n");
        row++;
    }

    return 0;
}

/*
Now modify so it prints the following pattern:
    ./bars
    Enter an integer: 9
    -*-*-*-*-
    -*-*-*-*-
    -*-*-*-*-
    -*-*-*-*-
    -*-*-*-*-
    -*-*-*-*-
    -*-*-*-*-
    -*-*-*-*-
    -*-*-*-*-
*/
