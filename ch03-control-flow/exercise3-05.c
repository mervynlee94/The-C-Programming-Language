/*
 * =====================================================================================
 *
 *  Created:  01/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write the function itob(n,s,b) that converts the integer n into a base b 
 *  character representation in the string s. In particular, itob(n,s,16) formats s as a 
 *  hexadecimal integer in s.

 * =====================================================================================
 */

#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);
void itob(int n, char s[], int b);

int main(){
    char s[MAXLINE];
    itob(45235134, s, 16);
    printf("%s", s);
    return 0;
}

void itob(int n, char s[], int b){
    int i, sign;
    unsigned int npositive;
    if ((sign = n) < 0) 
        npositive = -n; 
    else
        npositive = n;
    i = 0;
    
    do { 
        s[i++]= (npositive%b) < 10 ? npositive%b +'0' : npositive%b + 55; 
    } 
    while ((npositive /= b) > 0); 
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


