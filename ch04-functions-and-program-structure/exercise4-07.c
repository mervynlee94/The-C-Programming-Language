/*
 * =====================================================================================
 *
 *  Created:  04/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a routine ungets(s) that will push back an entire string onto the input. 
 *  Should ungets know about buf and bufp, or should it just use ungetch?
 *
 * =====================================================================================
 */

#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else 
        buf[bufp++] = c;
}

void ungets(char c[]){
    int i;
    for(i = 0; c[i] != '\0'; ++i)
        ;
    while(i)
        ungetch(c[--i]);
}

int main(){
    char s[] = "Hello World";
    int c;
    ungets(s);
    while((c = getch())!= EOF){
        putchar(c);
    }
    return 0;
}