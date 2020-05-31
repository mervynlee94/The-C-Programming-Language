/*
 * =====================================================================================
 *
 *  Created:  31/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: In a two's complement number representation, our version of itoa does not 
 *  handle the largest negative number, that is, the value of n equal to -(2wordsize-1). 
 *  Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.

 * =====================================================================================
 */

#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);
void itoa(int n, char s[]);

int main(){
    char s[MAXLINE];
    itoa(-2147483648, s);
    printf("%s", s);
    return 0;
}

void itoa(int n, char s[]){
    int i, sign;
    unsigned int npositive;
    if ((sign = n) < 0) 
        npositive = -n; 
    i = 0;
    do { 
        s[i++]=npositive%10+'0';
    } 
    while ((npositive /= 10) > 0); 
    if (sign < 0)
        s[i++] = '-'; 
        s[i] = '\0';
    reverse(s);
}

void reverse(char s[]){
    int c, i, j, len;
    for(i = 0, len = 0; s[i]!= '\0'; i++, len++)
        ;
    for (i = 0, j = len-1; i < j; i++, j--) 
        c = s[i], s[i] = s[j], s[j] = c;
}

