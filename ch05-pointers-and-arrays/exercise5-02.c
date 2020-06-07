/*
 * =====================================================================================
 *
 *  Created:  07/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write getfloat, the floating-point analog of getint. What type does getfloat 
 *  return as its function value?
 * 
 * =====================================================================================
 */

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
int getch(void);
void ungetch(int);
int getfloat(float *pn);

char buf[BUFSIZE];
int bufp = 0;

int main(){
    int c;
    float d;
    while((c = getfloat(&d)) != EOF && c != 0){
        printf("%f\n", d);
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

 int getfloat(float *pn){
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
        *pn = 10.0 * *pn + (c-'0');
    float dec;
    if(c == '.'){
        c = getch();
        if(!isdigit(c)){
            ungetch(c);
            return 0;
        }
        for(dec = 1.0; isdigit(c); c = getch(), dec*=10)
            *pn = 10.0 * *pn + (c-'0');
        
    }
    *pn /= dec;
    *pn *= sign;
    if(c != EOF)
        ungetch(c);
    return c;
 }