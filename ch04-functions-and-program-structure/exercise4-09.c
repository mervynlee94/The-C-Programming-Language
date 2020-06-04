/*
 * =====================================================================================
 *
 *  Created:  04/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what 
 *  their properties ought to be if an EOF is pushed back, then implement your design.
 *
 * =====================================================================================
 */

#include <stdio.h>
#define BUFSIZE 100

/* 
At page 19,
We must declare c to be a type big enough to hold any value that getchar returns. 
We can't use char since c must be big enough to hold EOF in addition to any possible char. 
Therefore we use int.
*/
int buf[BUFSIZE]; /* Use int to hold EOF */
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

int main(){
   
    int c;
    c = 'H';
    ungetch(c);
    while((c = getch())!= EOF){
        putchar(c);
    }
    return 0;
}