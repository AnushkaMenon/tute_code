// Program to get strings from user input until EOF and
//  print each string out twice
// Written by Anushka, Oct. 2021

#include <stdio.h>

#define MAX_LENGTH 4096

int main(void) {

    char my_string[MAX_LENGTH];
    
    while (fgets(my_string, MAX_LENGTH, stdin) != NULL) {
       printf("%s", my_string);
       printf("%s", my_string);
    }
    
    return 0;
}

/*Write a program echo_twice.c which reads lines
    from its input until EOF and prints them twice.
    
    The only functions you can use are fgets and printf.
    You can assume lines contain at most 4096 characters.

    For example:
        ./echo_twice
        My cat's breath smells like cat food. [user input]
        My cat's breath smells like cat food.
        My cat's breath smells like cat food.
        My eyes! The goggles do nothing! [user input]
        My eyes! The goggles do nothing!
        My eyes! The goggles do nothing!
*/
