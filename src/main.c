#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "utils.h"

int main()
{
    
    int sd_size = 1000;
    stack_double sd;

    init_stack_double(&sd, sd_size);
    kill_stack_double(&sd);

    return 0;
}