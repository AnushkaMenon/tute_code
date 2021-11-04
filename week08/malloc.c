// Allocating memory for a struct student using malloc
// Written by Anushka, Nov. 2021

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 1024

struct student {
    int zID;
    double mark;
    char name[MAX_NAME_LENGTH];
};

struct student *create_student(int zID, double mark, char *name);

int main(void) {
    struct student *my_student = create_student(1234567, 55.3, "Bill");
    
    printf("zID: %d, mark: %lf, name: %s\n", my_student->zID, my_student->mark, my_student->name);
    
    return 0;
}

// Create a new struct student and return a pointer to it
struct student *create_student(int zID, double mark, char *name) {
    // If you want to malloc an int:
    //  int *my_memory = malloc(sizeof(int));

    struct student *new_student = malloc(sizeof(struct student));
    
    new_student->zID = zID;
    new_student->mark = mark;
    // Can't directly assign strings - must use strcpy()
    strcpy(new_student->name, name);
    
    return new_student;
}

