/*
 * =====================================================================================
 *
 *  Created:  17/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Run the ``hello, world'' program on your system. 
 *  Experiment with leaving out parts of the program, to see what error messages you get.
 * 
 * =====================================================================================
 */

#include <stdio.h>

// Without specific int as return type, compiler will issue a warning
// warning: type specifier missing, defaults to 'int' [-Wimplicit-int]
int main(){
    printf("hello, world");
}