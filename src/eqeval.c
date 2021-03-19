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
