#include <stdio.h>

#include "acutest.h"

#include "test_utils.h"
#include "test_stack.h"
#include "test_strparse.h"


// Run TESTs 
TEST_LIST = {
    {"Stack Cycle", test_stack_cycle},
    {"String: Parse", test_read_string},
    {"Utility", test_utils},
    {NULL, NULL} // Terminate the test
};