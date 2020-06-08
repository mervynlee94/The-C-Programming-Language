/*
 * =====================================================================================
 *
 *  Created:  08/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a pointer version of the function strcat that we showed in Chapter 2:
    strcat(s,t) copies the string t to the end of s.
 * 
 * =====================================================================================
 */

#include <stdio.h>
#define MAXLENGTH 100
void mystrcat(char *s, char *t);
int main(){
    char s[MAXLENGTH] = "Hello";
    char t[] = " World!";
    mystrcat(s, t);
    printf("%s", s);
    return 0;
}

void mystrcat(char *s, char *t) {
    while(*s)
        s++;
    while((*s++ = *t++))
        ;
}