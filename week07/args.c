// Program to print out modified command line arguments
// Written by Anushka, Oct. 2021

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("You supplied %d arguments!\n", argc);
    
    // Print an error if the user doesn't enter any
    //  additional command line arguments
    if (argc <= 1) {
        printf("Usage: ./args [arguments]\n");
        return 1;
    }
    
    // Loop over command line arguments
    //  (Ignore the first argument since it's the program name)
    int i = 1;
    while (i < argc) {
        // note: argv[i] is a string
        int j = 0;
        while (argv[i][j] != '\0') {
            // note: argv[i][j] is a character of the
            //  argv[i] string
            printf("%c|", argv[i][j]);
            j++;
        }
        printf(" ");
        i++;
    }
    
    return 0;
}

/*
    Print out each command line argument (except the program name)
    with '|' after each character.
    
    For example:
        ./args hello hi
        h|e|l|l|o| h|i|
*/
