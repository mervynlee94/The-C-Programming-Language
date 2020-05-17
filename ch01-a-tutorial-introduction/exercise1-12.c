/*
 * =====================================================================================
 *
 *  Created:  17/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a program that prints its input one word per line.
 * 
 * =====================================================================================
 */

#include <stdio.h>

int main(){
    int c;
    while((c=getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t'){
            putchar('\n');
        }
        else{
            putchar(c);
        }
    }
}
