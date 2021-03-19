#ifndef STRPARSE_H
#define STRPARSE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> //isdigit(), ispunct()

/** pop an operator or a number (in string) and move the pin forward.
 * @param eq_str The string of equation
 * @param rpin start site for reading
 * @param placeholder printout
*/
int pop_streq_item(char* eq_str, int*  rpin, char* placeholder);


#endif