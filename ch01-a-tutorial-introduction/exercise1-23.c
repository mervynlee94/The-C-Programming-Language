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
void skipComment();
int main(){
    int c, prev;
    int in_string = 0;
    while((c=getchar())!= EOF){
        if(c == '"' && prev!= '\\'){
            in_string = !in_string;
        }
        if(c == '/' && !in_string){
            if((c=getchar()) == '*'){
                skipComment();
            }
            else{
                putchar('/');
                putchar(c);
            }
        }
        else{
            putchar(c);
        }
        prev = c;
    }
    return 0;
}

void skipComment(){
    int c;
    int end = 0;
    while(!end && (c=getchar())!= EOF){
        if((c=getchar()) == '*'){
            if((c=getchar()) == '/'){
                end = 1;
            }
            else{
                putchar('*');
                putchar(c);
            }
        }
    }
}