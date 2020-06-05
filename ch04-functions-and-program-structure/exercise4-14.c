/*
 * =====================================================================================
 *
 *  Created:  06/06/2020
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a recursive version of the function reverse(s), which reverses 
 *  the string s in place.
 *
 * =====================================================================================
 */

#include <stdio.h>
#define swap(t,x,y) { t tmp; tmp = x; x = y; y = tmp; }

int main(){
    char x,y;
    x = '1';
    y = '2';
    printf("x = %c, y = %c\n", x, y);
    swap(char, x, y);
    printf("x = %c, y = %c", x, y);
    return 0;
}


