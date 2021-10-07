// Squares all elements in an array
// Written by Anushka, Oct. 2021

#include <stdio.h>
#include <math.h>

#define ARR_LENGTH 5

void square(int arr[]);

int main(void) {
    int nums[ARR_LENGTH] = {2, 4, 6, 8, 10};
    
    square(nums);
    
    int i = 0;
    while (i < ARR_LENGTH) {
        printf("%d\n", nums[i]);
        i++;
    }
    
    return 0;
}

void square(int arr[]) {
    int i = 0;
    
    while (i < ARR_LENGTH) {
        arr[i] = arr[i] * arr[i];
        i++;
    }
}
