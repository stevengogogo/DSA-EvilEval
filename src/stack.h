#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <assert.h>
#include "utils.h"




typedef struct {
    Operator op;
    int order;
} opor;

typedef struct {
    int maxsize;
    int top;
    double* items;
} stack_double;

typedef struct {
    int maxsize;
    int top;
    int* items;
} stack_int;

typedef struct {
    int maxsize;
    int top;
    Operator* items;
} stack_op;

typedef struct {
    int maxsize;
    int top;
    opor* opors;
} stack_opor;



/** @brief Initiate a stack with double. 
 * This function use malloc to allocate a stack with double array. `items` is allocated with size of maxsize and `top` is set to `0`*/
void init_stack_double(stack_double*,int maxsize);
void init_stack_int(stack_int*, int maxsize);
void init_stack_op(stack_op*, int maxsize);
void init_stack_opor(stack_opor* sd, int maxsize);

/** Kill*/
void kill_stack_double(stack_double*);
void kill_stack_int(stack_int*);
void kill_stack_op(stack_op*);
void kill_stack_opor(stack_opor*);

/** Push*/
void push_stack_double(stack_double*, double item);
void push_stack_int(stack_int*, int item);
void push_stack_op(stack_op*, Operator item);
void push_stack_opor(stack_opor*, Operator item, int order);

/** Pop*/
double pop_stack_double(stack_double*);
int pop_stack_int(stack_int*);
Operator pop_stack_op(stack_op*);
opor pop_stack_opor(stack_opor);


#endif