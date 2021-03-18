#ifndef TEST_STACK_H
#define TEST_STACK_H

#include "acutest.h"
#include "stack.h"

void test_stack_cycle(void){
    int sd_size = 1000000;
    stack_double* sd;

    init_stack_double(sd, sd_size);
    kill_stack_double(sd);
}

#endif