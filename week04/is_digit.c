// Program to continuously read integers from the user
// Written by Anushka, Oct. 2021

#include <stdio.h>

int main(void) {

    int num;
    
    // Scanning in integers
    while (scanf("%d", &num) == 1) {
        printf("Hello\n");
    }
    
    printf("Exited integer loop\n");
}
