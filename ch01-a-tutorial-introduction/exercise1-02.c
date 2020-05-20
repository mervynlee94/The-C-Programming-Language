/*
 * =====================================================================================
 *
 *  Created:  17/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Experiment to find out what happens when prints's argument string contains \c, 
 *  where c is some character not listed above.
 * 
 * =====================================================================================
 */

#include <stdio.h>

int main(){
    printf("hello, world\v");
}