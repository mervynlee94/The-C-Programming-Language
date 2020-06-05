/*
 * =====================================================================================
 *
 *  Created:  31/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a recursive version of the function reverse(s), which reverses 
 *  the string s in place.
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void reverse(char s[], int i, int len);

int main(){
    char s[] = "Hello World!";
    reverse(s, 0, strlen(s)-1);
    printf("%s", s);
    return 0;
}

void reverse(char s[], int i, int len){
    int tmp;
    if(i < len){
        tmp = s[i];
        s[i] = s[len];
        s[len] = tmp;
        reverse(s, i+1, len-1);
    }
}   

