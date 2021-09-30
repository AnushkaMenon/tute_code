// Calculates the area of a rectangle
// Written by Anushka, Sep. 2021

#include <stdio.h>

int main(void) {

    // get length, width from user
    double length;
    double width;
    
    printf("Enter length: ");
    scanf("%lf", &length);
    
    // only allow positive lengths
    if (length < 0) {
        printf("Only positive lengths allowed.\n");
        return 1;
    }
    
    printf("Enter width: ");
    scanf("%lf", &width);
    
    // only allow positive widths
    if (width < 0) {
        printf("Only positive widths allowed.\n");
        return 1;
    }
   
    // calculate the area
    double area = length * width;
    
    // print area of rectangle
    printf("The area is %lf\n", area);
    
    return 0;
}
