#ifndef TEST_STACK_H
#define TEST_STACK_H

#include "acutest.h"
#include "stack.h"

#define MAX_INPUT 1000000

void test_stack_cycle(void){
    stack_double sd;
    stack_int si;
    stack_op so;

    //Initiation
    init_stack_double(&sd, MAX_INPUT);
    init_stack_int(&si, MAX_INPUT);
    init_stack_op(&so, MAX_INPUT);
    //Destroy
    kill_stack_double(&sd);
    kill_stack_int(&si);
    kill_stack_op(&so);
}

#endif