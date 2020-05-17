/*
 * =====================================================================================
 *
 *  Created:  17/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a program to copy its input to its output, 
 *  replacing each tab by \t, each backspace by \b, and each backslash by \\. 
 *  This makes tabs and backspaces visible in an unambiguous way.
 * =====================================================================================
 */

#include <stdio.h>

int main(){
    int c;

    while((c=getchar()) != EOF){
        if (c == '\t'){
            printf("\\t");
        }
        else if (c == '\b'){
            printf("\\b");
        }
        else if (c == '\\'){
            printf("\\\\");
        }
        else{
            putchar(c);
        }
    }
}