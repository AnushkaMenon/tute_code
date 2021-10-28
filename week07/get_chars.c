// Program to look at getchar() and putchar()
// Written by Anushka, Oct. 2021

#include <stdio.h>

int main(void) {
    
    /* scanf/printf equivalents of getchar/putchar:
        char my_char;
        scanf("%c", &my_char);
        printf("%c\n", my_char); */
    
    int my_char;
    
    my_char = getchar();
    
    while (my_char != EOF) {
        putchar(my_char);
        my_char = getchar();
    }
    
    return 0;
}
