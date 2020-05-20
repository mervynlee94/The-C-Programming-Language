/*
 * =====================================================================================
 *
 *  Created:  20/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a program to remove all comments from a C program. 
 *  Don't forget to handle quoted strings and character constants properly. 
 *  C comments don't nest.
 * 
 * =====================================================================================
 */

#include <stdio.h>

/*
We must assume the input is valid C program
*/
void inComment();
void inQuote(int c);
int main(){
    int c;
    while((c=getchar())!= EOF){
        if(c == '"'){
            inQuote(c);
        }
        else if(c == '/'){
            if((c=getchar()) == '*'){
                inComment();
            }
            else{
                putchar('/');
                putchar(c);
            }
        }
        else
            putchar(c);
        
    }
    return 0;
}

void inComment(){
    int c, d;
    int end = 0;
    while(!end && (c=getchar())!= EOF){
        if((c=getchar()) == '*'){
            if((c=getchar()) == '/')
                end = 1;
            else{
                putchar('*');
                putchar(c);
            }
        }
    }
}

void inQuote(int c){
    int d;
    putchar(c);
    while((d=getchar())!= c){
        putchar(d);
        if(d == '\\')
            getchar();
    }
}