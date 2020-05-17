/*
 * =====================================================================================
 *
 *  Created:  17/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 * 
 * =====================================================================================
 */

#include <stdio.h>

int main(){
    int c;

    while((c=getchar()) != EOF){
        if (c == '\t'){
            printf("\\t");
        }
        else if (c == '\b'){
            printf("\\b");
        }
        else if (c == '\\'){
            printf("\\\\");
        }
        else{
            putchar(c);
        }
    }
}