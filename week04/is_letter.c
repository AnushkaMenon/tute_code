// Program to continuously read characters from the user and output whether
//  the inputted character was a letter or not
// Written by Anushka, Oct. 2021

#include <stdio.h>

int main(void) {
    char my_char;
    
    // Scanning in characters
    while (scanf(" %c", &my_char) == 1) {
        if ((my_char >= 'a' && my_char <= 'z') || (my_char >= 'A' && my_char <= 'Z')) {
            printf("You inputted a letter!\n");
        } else {
            printf("You inputted a character, but it was not a letter\n");
        }
    }
    
    printf("Exited character loop\n");

    return 0;
}
