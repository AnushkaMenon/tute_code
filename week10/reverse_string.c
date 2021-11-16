#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void iter_print_string_reverse(char *string);
void recursive_print_string_reverse(char *string);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./reverse_string [str]");
        exit(1);
    }
    
    char *str = argv[1];
    
    iter_print_string_reverse(str);
    printf("\n");
    recursive_print_string_reverse(str);
    printf("\n");
    
    return 0;
}

void iter_print_string_reverse(char *string) {
    int index = strlen(string) - 1;
    
    while (index >= 0) {
        printf("%c", string[index]);
        index--;
    }
}

void recursive_print_string_reverse(char *string) {
    if (string[0] == '\0') {
        return;
    }
    
    recursive_print_string_reverse(&string[1]);
    printf("%c", string[0]);
}
