#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <signal.h>
#include "utils.h"



/** Bundle of operation and its priority*/
typedef struct {
    Operator op;
    int order;
} opor;



typedef struct {
    int maxsize;
    int top; // top of operation/order
    double* nums;
    opor* opors;
    int order_base;
} stack_nopor;


int get_order(Operator);

int is_parenthesis(Operator);

void init_stack_nopor(stack_nopor*,int maxsize);


/** Kill*/
void kill_stack_nopor(stack_nopor*);


void update_stack_opor_orderbase(stack_nopor* st, Operator op);

/** Push*/
void push_stack_nopor(stack_nopor*, double num, opor pr);

/** Pop*/
void eval_stack_nopor_once(stack_nopor*);

void eval_stack_nopor(stack_nopor*);

double get_eq_answer(stack_nopor*);

double eval(Operator, double a, double b);

opor get_opor(Operator op , stack_nopor* st);

#endif