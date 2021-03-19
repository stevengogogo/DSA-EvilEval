#include "stack.h"

/*Initiation*/

void init_stack_double(stack_double* sd, int maxsize){
    sd->items = (double*)malloc(maxsize*sizeof(double));
    assert(sd->items != NULL);
    sd->maxsize = maxsize;
    sd->top = 0;
}


void init_stack_opor(stack_opor* sd, int maxsize){
    sd->opors = (opor*)malloc(maxsize*sizeof(opor));
    assert(sd->opors != NULL);
    sd->maxsize = maxsize;
    sd->top = 0;
}

/*Destruction*/

void kill_stack_double(stack_double* st){
    free(st->items);
    st->items = NULL;
}


void kill_stack_opor(stack_opor* st){
    free(st->opors);
    st->opors = NULL;
}

/*Push*/

void push_stack_double(stack_double* st, double item){
    assert(st->top < st->maxsize);
    ++(st->top);
    st->items[st->top] = item;  
}



void push_stack_opor(stack_opor* st, opor pr){
    assert(st->top < st->maxsize);
    ++(st->top);
    st->opors[st->top] = pr;
}

/*Pop*/
double pop_stack_double(stack_double* st){
    double out;
    assert(st->top != 0);
    out = st->items[st->top];
    --(st->top);
    return out;
}


opor pop_stack_opor(stack_opor* st){
    opor out;
    assert(st->top != 0);
    out = st->opors[st->top];
    --(st->top);
    return out;
}


int is_opor_equal(opor a, opor b){
    if (a.op != b.op)
        return 0;
    else if (a.order != b.order)
        return 0;
    else 
        return 1;
}