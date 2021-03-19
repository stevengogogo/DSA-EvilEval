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





double eval_string(char* eqstr){
    char symbol[MAX_INPUT];
    char symbol2[MAX_INPUT];
    stack_nopor st;
    Operator op;
    opor pr; 
    double num;
    double ans;
    int rpin=0;
    double first_number;
    int is_first_number = 1;

    init_stack_nopor(&st, MAX_INPUT);

    while(pop_streq_item(eqstr, &rpin, symbol) > 0){

        //Update order base for ( )
        if ((symbol[0]=='(') | (symbol[0]==')')){
            op = str2op(symbol);
            update_stack_opor_orderbase(&st, op);
            continue;
        }

        // Accounter a number
        if (isdigit(symbol[0]) & is_first_number){
            num = str2double(symbol);
            st.nums[1] = num; // insert first number to 0+num
            is_first_number = 0;
        }

        if (ispunct(symbol[0])){
            op = str2op(symbol); // get operator
            pop_streq_item(eqstr, &rpin, symbol);
            assert(isdigit(symbol[0])); //get number
            num = str2double(symbol);

            // Get operator and order
            pr = get_opor(op, &st);
            push_stack_nopor(&st, num, pr);
        }


    ans = get_eq_answer(&st);
    kill_stack_nopor(&st);
    return ans;
}
