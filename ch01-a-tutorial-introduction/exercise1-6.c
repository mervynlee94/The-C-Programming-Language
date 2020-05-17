/*
 * =====================================================================================
 *
 *  Created:  17/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 * 
 * =====================================================================================
 */

#include <stdio.h>

int main(){
    while(getchar() != EOF)
        printf("The expression getchar() != EFO is %d\n", getchar() != EOF);

    printf("The expression getchar() != EFO is %d\n", getchar() != EOF);
    
    // There is no "EOF character", ctrl-D is translated 
    // by the terminal driver into the end-of-file condition
    // 0 is printed when ctrl-D is issued.
}