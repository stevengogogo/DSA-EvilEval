#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <assert.h>
#include "utils.h"



/** Bundle of operation and its priority*/
typedef struct {
    Operator op;
    int order;
} opor;


/** Stack of doubles*/
typedef struct {
    int maxsize;
    int top;
    double* items;
} stack_double;

/**Stack of bundles of operators and orders*/
typedef struct {
    int maxsize;
    int top;
    opor* opors;
} stack_opor;



/** @brief Initiate a stack with double. 
 * This function use malloc to allocate a stack with double array. `items` is allocated with size of maxsize and `top` is set to `0`*/
void init_stack_double(stack_double*,int maxsize);
void init_stack_opor(stack_opor* sd, int maxsize);

/** Kill*/
void kill_stack_double(stack_double*);
void kill_stack_opor(stack_opor*);

/** Push*/
void push_stack_double(stack_double*, double item);
void push_stack_opor(stack_opor*, opor);

/** Pop*/
double pop_stack_double(stack_double*);
opor pop_stack_opor(stack_opor*);


int is_opor_equal(opor a, opor b);

#endif