// Program to look at struct pointers
// Written by Anushka, Oct. 2021

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 4096

struct student {
  int zID;
  double wam;
  char name[MAX_NAME_LENGTH];
};

int main(void) {
    /* Changing values using struct pointers
       is very similar to changing values of
       other pointers. The below code will
       change x to be 8:
        
            int x = 5;
            int *x_pointer = &x;
    
            *x_pointer = 8;
    */

    struct student my_student;
   
    struct student *s_pointer = &my_student;
    
    // These two are equivalent, '->' notation is just
    //  neater and easier to write
    (*s_pointer).zID = 5
    s_pointer->zID = 5;
    
    s_pointer->wam = 60.3;
    
    // Must use strcpy for assigning strings
    strcpy(s_pointer->name, "Bob");
    
    printf("%d, %lf, %s\n", my_student.zID, my_student.wam, my_student.name);
    
    return 0;
}
