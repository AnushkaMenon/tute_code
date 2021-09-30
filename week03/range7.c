// Program to print all numbers in a user-defined range which
//  are divisible by 7
// Written by Anushka, Sep. 2021

#include <stdio.h>

int main(void) {

    int start;
    printf("Enter start: ");
    scanf("%d", &start);
    
    int finish;
    printf("Enter finish: ");
    scanf("%d", &finish);
    
    int i = start;
    
    while (i <= finish) {
        if (i % 7 == 0) {
            printf("%d\n", i);
        }
        i = i + 1;
    }

    return 0;
}

/*
Write a C program range7.c which reads 2 integers n and m, 
    and then prints the integers between n and m (including n and m)
    which are divisible by 7.
    
    ./range7
    Enter start: 3
    Enter finish: 49
    7
    14
    21
    28
    35
    42
    49
*/
