/*
 * =====================================================================================
 *
 *  Created:  08/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write versions of the library functions strncpy, strncat, and strncmp, 
 *  which operate on at most the first n characters of their argument strings. For example, 
 *  strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.
 * 
 * =====================================================================================
 */

#include <stdio.h>
#define MAXLENGTH 100

int mystrncmp(char *s, char *t, int n);
void mystrncat(char *s, char *t, int n);
void mystrncpy(char *s, char *t, int n);

int main(){
    char s[MAXLENGTH] = "HelloWorld";
    char t[] = "Hello";
    printf("%d\n", mystrncmp(s, t, 5));
    mystrncat(s, t, 5);
    printf("%s\n", s);
    char t2[] = "Goodbye";
    mystrncpy(s, t2, 10);
    printf("%s\n", s);
    return 0;
}

void mystrncpy(char *s, char *t, int n){
    while ((*s++ = *t++) && --n) ;
    while(--n)
        *s = '\0';
}

void mystrncat(char *s, char *t, int n){
    while(*s)
        s++;
    while((*s++ = *t++) && --n)
        ;
    *s = '\0';
}

int mystrncmp(char *s, char *t, int n){
    int i;
    for(i = 1; *s == *t && i < n; i++, s++, t++)
        if(i == n || *s == '\0' )
            return 0;
    return *s - *t;
}