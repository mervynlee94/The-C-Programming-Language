/*
 * =====================================================================================
 *
 *  Created:  31/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Adapt the ideas of printd to write a recursive version of itoa; that is, 
 *  convert an integer into a string by calling a recursive routine.

 * =====================================================================================
 */

#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);
void itoa(int n, char s[]);

int main(){
    char s[MAXLINE];
    itoa(-25134, s);
    printf("%s", s);
    return 0;
}

void itoa(int n, char s[]){
    static int i = 0;
    if ( n < 0){
        s[i++] = '-';
        n = -n;
    }
    if (n/10)
        itoa(n/10, s);
    s[i++] = n%10 + '0';
}