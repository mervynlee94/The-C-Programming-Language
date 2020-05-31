/*
 * =====================================================================================
 *
 *  Created:  31/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Rewrite the function lower, which converts upper case letters to lower case, 
 *  with a conditional expression instead of if-else.

 * =====================================================================================
 */

#include <stdio.h>

char lower(char c);
int main(){
    int c;
    while((c=getchar()) != EOF)
        printf("%c", lower(c));
    return 0;
}

char lower(char c){
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

