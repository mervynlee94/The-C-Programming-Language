/*
 * =====================================================================================
 *
 *  Created:  04/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Suppose that there will never be more than one character of pushback. 
 *  Modify getch and ungetch accordingly.
 *
 * =====================================================================================
 */

#include <stdio.h>
#define BUFSIZE 100


int buf = 0;

int getch(void){
    int c;
    if(buf != 0){
        c = buf;
    }
    else{
        c = getchar();
    }
    buf = 0;
    return c;
}

void ungetch(int c){
    if(buf!=0){
        printf("ungetch: too many characters\n");
    }
    else
        buf = c;
}


int main(){
    char c = 'H';
    ungetch(c);
    while((c = getch())!= EOF){
        putchar(c);
    }
    return 0;
}