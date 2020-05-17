/*
 * =====================================================================================
 *
 *  Created:  17/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a program to copy its input to its output, 
 *  replacing each string of one or more blanks by a single blank.
 * 
 * =====================================================================================
 */

#include <stdio.h>

int main(){
   int c;

   while((c=getchar()) != EOF){
    // Not using else statement here since the book hasn't introduce it yet
     if(c == ' '){
         while((c=getchar())== ' ')
            ;
        putchar(' ');
        if(c == EOF ) break;
     }
    putchar(c);
    }
}