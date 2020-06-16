/*
 * =====================================================================================
 *
 *  Created:  07/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: As written, getint treats a + or - not followed by a digit as a valid 
 *  representation of zero. Fix it to push such a character back on the input.
 * 
 * =====================================================================================
 */

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
int getch(void);
void ungetch(int);
int getint(int *pn);

char buf[BUFSIZE];
int bufp = 0;

int main(){
    int d, c;
    while((c = getint(&d)) != EOF && c != 0){
        printf("%d\n", d);
    }
    return 0;
}

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

 void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getint(int *pn){
    int c, sign;
    while(isspace(c = getch()))
        ;
    if(!isdigit(c) && c!= EOF && c!= '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
      c = getch();
    if (!isdigit(c)){
       ungetch(c);
       return 0;
    }
    for(*pn = 0 ; isdigit(c); c = getch())
        *pn = 10 * *pn + (c-'0');
    *pn *= sign;
    if(c != EOF)
        ungetch(c);
    return c;
}