#ifndef TEST_STACK_H
#define TEST_STACK_H

#include "acutest.h"
#include "utils.h"
#include "stack.h"

#define MAX_INPUT 1000000

void test_stack_cycle(void){
    stack_double sd;
    stack_opor so;
   

    //Initiation
    init_stack_double(&sd, MAX_INPUT);
    init_stack_opor(&so, MAX_INPUT);
    //Destroy
    kill_stack_double(&sd);
    kill_stack_opor(&so);
}



void test_stack_push_pop(void){
    stack_double sd;
    stack_opor so;

    double ed = 343;
    opor pr = {
        .op = PLUS,
        .order = 4
    };

    //Init
    init_stack_double(&sd, MAX_INPUT);
    init_stack_opor(&so, MAX_INPUT);

    //Push
    push_stack_double(&sd, ed);
    push_stack_opor(&so, pr);

    TEST_ASSERT(sd.top==1);
    TEST_ASSERT(so.top==1);

    //Pop
    TEST_ASSERT(is_double_equal(ed, pop_stack_double(&sd)));
    TEST_ASSERT(is_opor_equal(pr, pop_stack_opor(&so)));

    TEST_ASSERT(sd.top==0);
    TEST_ASSERT(so.top == 0);

    //Kill
    kill_stack_double(&sd);
    kill_stack_opor(&so);
}

#endif