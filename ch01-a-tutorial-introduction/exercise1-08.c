/*
 * =====================================================================================
 *
 *  Created:  17/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a program to count blanks, tabs, and newlines.
 * =====================================================================================
 */

#include <stdio.h>

int main(){
   int c, nl, nb, nt;
   
   nl = nb = nt = 0;
   while((c=getchar()) != EOF){
       if (c == '\n')
            ++nl;
        else if (c == '\t')
            ++nt;
        else if (c == ' ')
            ++nb;
    }
   printf("Newline: %d\nTab: %d\nSpace: %d", nl, nt, nb);
}