/*
 * =====================================================================================
 *
 *  Created:  17/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a program to print a histogram of the lengths of words in its input. 
 *  It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
 * 
 * =====================================================================================
 */

#include <stdio.h>
#define MAX_LENGTH 20
#define IN 1
#define OUT 0

int main(){
    int c, nchar, state;
    state = OUT;
    int words[MAX_LENGTH];
    for(int i = 0 ; i < MAX_LENGTH; i++){
        words[i] = 0;
    }
    
    while((c = getchar()) != EOF){
        if(c == ' '|| c == '\n' || c == '\t'){
            state = OUT;
            ++words[nchar];
        }
        else if(state == OUT){
            state = IN;
            nchar = 1;
        }
        else{
            ++nchar;
        } 
    }

    for(int i = 0 ; i < MAX_LENGTH; i++){
        for(int j = 0 ; j < words[i]; j++){
            putchar('|');
        }
        putchar('\n');
    }
}