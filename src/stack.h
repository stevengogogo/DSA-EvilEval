#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "utils.h"





typedef struct {
    int maxsize;
    int top;
    double* items;
} stack_double;


/** @brief Initiate a stack with double. 
 * This function use malloc to allocate a stack with double array. `items` is allocated with size of maxsize and `top` is set to `0`*/
void init_stack_double(stack_double*,int maxsize);
void kill_stack_double(stack_double*);



#endif