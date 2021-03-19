#ifndef TEST_eqeval_H
#define TEST_eqeval_H

#define MAX_INPUT 1000000

#include "eqeval.h"

void test_read_string(void){
    FILE* fptr = fopen("test/data/input.txt", "r");
    char input[MAX_INPUT+1];
    char ele[MAX_INPUT+1];
    char readout[MAX_INPUT+1];
    int rpin = 0;

    while(fgets(input, MAX_INPUT, fptr)){

        while (pop_streq_item(input, &rpin, ele) != 0)
            strcat(readout, ele); // Reconstruct the elements
    
        TEST_ASSERT( strcmp(readout, input) );
    }
    fclose(fptr);
}

void test_str2op(void){
    char s[MAX_INPUT] = "+-*/()";
    char sym[2] = "0"; // {symbol, \0}
    char n[MAX_INPUT] = "3434343243242342423";
    double n_r = 3434343243242342423;
    double n_e = str2double(n);
    Operator s_r[] = {PLUS, MINUS, MULT, DIV, LP, RP};

    for(int i=0;i<strlen(s);i++){
        sym[0] = s[i]; // Copy symbol

        TEST_ASSERT( str2op(sym) == s_r[i]);
    }

    TEST_ASSERT( is_double_equal(n_r, n_e ) );
}


void test_evaluation(void){
    
}


#endif