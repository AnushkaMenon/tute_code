// An intro to functions

#include <stdio.h>

int get_larger(int first_num, int second_num);

int main(void) {
    //int num;
    
    //int scanf_return = scanf("%d", &num);
    
    int num1 = 7;
    int num2 = 2;
    
    int bigger_num = get_larger(num1, num2);
    printf("%d\n", bigger_num);
    
    return 0;
}

int get_larger(int first_num, int second_num) {
    int larger = first_num;
    if (second_num > first_num) {
        larger = second_num;
    }

    return larger;
}

