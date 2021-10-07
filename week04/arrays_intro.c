// Intro to arrays
// Written by Anushka, Oct. 2021

#include <stdio.h>

#define ARRAY_SIZE 8

void print_array(int arr[]);

int main(void) {

    int my_nums[ARRAY_SIZE];
    
    int j = 0;
    while (j < ARRAY_SIZE) {
        my_nums[j] = 1;
        j++;
    }
    
    print_array(my_nums);
    
    return 0;
}

void print_array(int arr[]) {
    int i = 0;
    while (i < ARRAY_SIZE) {
        printf("%d\n", arr[i]);
        i++;
    }
}




