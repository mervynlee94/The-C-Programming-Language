/*
 * =====================================================================================
 *
 *  Created:  17/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a program to print a histogram of the frequencies of different 
 *  characters in its input.
 * 
 * =====================================================================================
 */

#include <stdio.h>
#define ASCII_RANGE 128

int main(){
    int c;
    int ascii_freq[ASCII_RANGE];
    for(int i = 0 ; i < ASCII_RANGE; i++){
        ascii_freq[i] = 0;
    }
    
    while((c = getchar()) != EOF){
       ++ascii_freq[c];
    }

    for(int i = 0 ; i < ASCII_RANGE; i++){
        for(int j = 0 ; j < ascii_freq[i]; j++){
            putchar('|');
        }
        putchar('\n');
    }
}