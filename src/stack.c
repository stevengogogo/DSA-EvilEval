#include "stack.h"


void init_stack_double(stack_double* sd, int maxsize){
    sd->items = (double*)malloc(maxsize*sizeof(double));
    sd->maxsize = maxsize;
    sd->top = 0;
}

void kill_stack_double(stack_double* sd){
    free(sd->items);
}