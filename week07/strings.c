// Looking at strings in C
// Written by Anushka, Oct. 2021

#include <stdio.h>
#include <string.h>

void print_str(char *s);

int main(void) {
   
    // These two are equivalent!
    char my_str[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char my_str2[6] = "hello";
    
    int len = strlen(my_str2);
    printf("The length of the string is: %d\n", len);
    
    print_str(my_str2);
    
    // Print out the whole string
    printf("%s\n", my_str2);
    
    return 0;
}

// Prints out each character of a string on a separate line
void print_str(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        printf("%c\n", s[i]);
        i++;
    }
}
