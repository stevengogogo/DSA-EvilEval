#include "eqeval.h"


int pop_streq_item(char* eq_str, int* rpin, char* placeholder){
    char sym0 = eq_str[*rpin];
    int n_read = 0;
    while (sym0 != '\n'){
        if(ispunct(sym0)){ //If this site is an op
            placeholder[n_read] = sym0;
            placeholder[n_read+1] = '\0';
            n_read++;
            (*rpin)++;
            return n_read;
        }
        else if (isdigit(sym0)){
            while(isdigit(sym0)){
                placeholder[n_read] = sym0;
                n_read++;
                (*rpin)++;
                sym0 = eq_str[*rpin];
            }
            placeholder[n_read] = '\0';
            return n_read;
        }
        else{
            perror("Got Error Symbol");
            return -1;
        }
    }
    placeholder[n_read] = '\0';
    return 0;
}

Operator str2op(char* s){

    switch (s[0])
    {
    case '+':
        return PLUS;
        break;
    case '-':
        return MINUS;
        break;
    case '*':
        return MULT;
        break;
    case '/':
        return DIV;
        break;
    case '(':
        return LP;
        break;
    case ')':
        return RP;
        break;
    default: {
        perror("Error Symbol to convert to operator");
        raise(SIGINT);
        break;
    }
    }
}

double str2double(char* numstr){
    return atof(numstr);
}

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



double eval_string(char* eqstr){
    char symbol[MAX_INPUT];
    char symbol2[MAX_INPUT];
    Operator op;
    double num;
    int rpin=0;
    int order_base = 0;

    while(pop_streq_item(eqstr, &rpin, symbol) > 0){

        // + - * / ( )
        if (ispunct(symbol[0])){
            op = str2op(symbol);
            
            if (is_parenthesis(op))
                order_base += get_order(op);
            else 
                pop_streq_item(eqstr, &rpin, symbol2);
                //Todo

        }

        else if (isdigit(symbol[0])){
            num = str2double(symbol);
        }

    }    
}
