/*
 * =====================================================================================
 *
 *  Created:  31/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a version of itoa that accepts three arguments instead of two. 
 *  The third argument is a minimum field width; the converted number must be padded 
 *  with blanks on the left if necessary to make it wide enough.

 * =====================================================================================
 */

#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);
void itoa(int n, char s[], int minWidth);

int main(){
    char s[MAXLINE];
    itoa(-214, s, 6);
    printf("%s", s);
    return 0;
}

void itoa(int n, char s[], int minWidth){
    int i, sign;
    unsigned int npositive;
    if ((sign = n) < 0) 
        npositive = -n; 
    else
        npositive = n;
        
    i = 0;
    do { 
        s[i++]=npositive%10+'0';
    } 
    while ((npositive /= 10) > 0);
    
    if (sign < 0)
        s[i++] = '-'; 
    int paddedZero = minWidth - i;
    while(paddedZero--)
        s[i++] = ' '; 
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

