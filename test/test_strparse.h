#ifndef TEST_STRPARSE_H
#define TEST_STRPARSE_H

#define MAX_INPUT 1000000

#include "strparse.h"

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


#endif