#include "stack.h"

int get_order(Operator op){
        switch (op)
    {
    case PLUS:
        return 0;
        break;
    case MINUS:
        return 0;
        break;
    case MULT:
        return 1;
        break;
    case DIV:
        return 1;
        break;
    case LP:
        return 2;
        break;
    case RP:
        return  -2;
        break;
    default: {
        perror("Error Order convertion");
        raise(SIGINT);
        break;
    }
    }
}


int is_parenthesis(Operator op){
    if (op==LP)
        return 1;
    else if(op==RP)
        return 1;
    else 
        return 0;
}


/*Initiation*/

void init_stack_nopor(stack_nopor* sd, int maxsize){
    opor init_op;

    sd->nums = (double*)malloc((maxsize+1+2)*sizeof(double));
    sd->opors = (opor*)malloc((maxsize+1)*sizeof(opor));
    assert(sd->nums != NULL);
    assert(sd->opors != NULL);
    sd->maxsize = maxsize;
    sd->order_base = 0;

    //Initiate operation
    init_op.op = PLUS;
    init_op.order = 0;

    sd->nums[0] = 0;
    sd->nums[1] = 0;
    sd->opors[0] = init_op;
    sd->top = 0; //insert 0+0
}



/*Destruction*/
void kill_stack_nopor(stack_nopor* st){
    free(st->nums);
    free(st->opors);
    st->nums = NULL;
    st->opors = NULL;
}



void update_stack_opor_orderbase(stack_nopor* st, Operator op){
    if (is_parenthesis(op)){
        st->order_base += get_order(op);
    }
}

/*Push*/
void push_stack_nopor(stack_nopor* st, double num, opor pr){
    assert(st->top < st->maxsize);
    assert(st->top >= -1);

    if (st->opors[st->top].order < pr.order){ // push in
        ++(st->top);  // extend
        st->opors[st->top] = pr;
        st->nums[st->top+1] = num;
    }

    else if(st->top==0){ //eval and replace
        st->nums[0] = eval(st->opors->op, st->nums[0], st->nums[1]);
        st->nums[1] = num;
        st->opors[0] = pr;
    }

    else{
        eval_stack_nopor_once(st);
        push_stack_nopor(st, num, pr);
    }
}

/*Pop*/
void eval_stack_nopor_once(stack_nopor* st){
    assert(st->top >= 0);
    double a,b;
    double c;
    opor pr;

    // Get numbers
    a = st->nums[st->top];
    b = st->nums[st->top + 1];

    // Get Operator
    pr = st->opors[st->top];
    
    // Eval 
    c = eval(pr.op, a, b);

    //Update
    st->nums[st->top] = c;
    --(st->top);
}

void eval_stack_nopor(stack_nopor* st){
    while(st->top > 0){
        eval_stack_nopor_once(st);
    }
}

double get_eq_answer(stack_nopor* st){
    double ans;
    eval_stack_nopor(st);
    eval_stack_nopor_once(st);
    assert(st->top==-1); // pop all items
    ans = st->nums[0];
    return ans;
}

double eval(Operator op, double a, double b){
    switch (op)
    {
    case PLUS:
        return a + b ;
        break;
    case MULT:
        return a*b;
        break;
    case MINUS:
        return a-b;
    case DIV:
        return a/b;
    default: {
        perror("Error Symbol to convert to operator");
        raise(SIGINT);
        break; 
    }
    }
}

opor get_opor(Operator op , stack_nopor* st){
    opor pr;
    assert(is_parenthesis(op) == 0);
    pr.order = get_order(op) + st->order_base;
    pr.op = op;
    return pr;
};
