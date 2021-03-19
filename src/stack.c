#include "stack.h"

/*Initiation*/

void init_stack_double(stack_double* sd, int maxsize){
    sd->items = (double*)malloc(maxsize*sizeof(double));
    assert(sd->items != NULL);
    sd->maxsize = maxsize;
    sd->top = 0;
}


void init_stack_int(stack_int* si, int maxsize){
    si->items = (int*)malloc(maxsize*sizeof(int));
    assert(si->items != NULL);
    si->maxsize = maxsize;
    si->top = 0;
}


void init_stack_op(stack_op* sd, int maxsize){
    sd->items = (Operator*)malloc(maxsize*sizeof(Operator));
    assert(sd->items != NULL);
    sd->maxsize = maxsize;
    sd->top = 0;
}

void init_stack_opor(stack_opor* sd, int maxsize){
    sd->ops = (Operator*)malloc(maxsize*sizeof(Operator));
    sd->orders = (int*)malloc(maxsize*sizeof(int));
    assert(sd->ops != NULL);
    assert(sd->orders != NULL);
    sd->maxsize = maxsize;
    sd->top = 0;
}

/*Destruction*/

void kill_stack_double(stack_double* st){
    free(st->items);
    st->items = NULL;
}

void kill_stack_op(stack_op* st){
    free(st->items);
    st->items = NULL;

}

void kill_stack_int(stack_int* st){
    free(st->items);
    st->items = NULL;
}

void kill_stack_int(stack_opor* st){
    free(st->ops);
    free(st->orders);
    st->ops = NULL;
    st->orders = NULL;
}

/*Push*/

void push_stack_double(stack_double* st, double item){
    assert(st->top < st->maxsize);
    ++(st->top);
    st->items[st->top] = item;  
}

void push_stack_int(stack_int* st, int item){
    assert(st->top < st->maxsize);
    ++(st->top);
    st->items[st->top] = item; 
}

void push_stack_op(stack_op* st, Operator item){
    assert(st->top < st->maxsize);
    ++(st->top);
    st->items[st->top] = item; 
}

void push_stack_opor(stack_opor* st, Operator op, int order){
    assert(st->top < st->maxsize);
    ++(st->top);
    st->ops[st->top] = op;
    st->orders[st->top] = order; 
}

/*Pop*/
double pop_stack_double(stack_double* st){
    double out;
    assert(st->top != 0);
    out = st->items[st->top];
    --(st->top);
    return out;
}

int pop_stack_int(stack_int* st){
    int out;
    assert(st->top != 0);
    out = st->items[st->top];
    --(st->top);
    return out;
}

Operator pop_stack_op(stack_op* st){
    Operator out;
    assert(st->top != 0);
    out = st->items[st->top];
    --(st->top);
    return out;
}
