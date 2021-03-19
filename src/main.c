#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "utils.h"
#include "eqeval.h"

# define MAX_INPUT 1000000

int main()
{
    
    FILE* fptr = fopen("test/data/input.txt", "r");
    char input[MAX_INPUT+1];
    char ele[MAX_INPUT+1];
    int rpin = 0;

    fgets(input, MAX_INPUT, fptr);

    pop_streq_item(input, &rpin, ele);
    TEST_ASSERT(rpin==1);

    fclose(fptr);

    return 0;
}