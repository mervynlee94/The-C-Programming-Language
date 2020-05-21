/*
 * =====================================================================================
 *
 *  Created:  22/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a loop equivalent to the for loop above without using && or ||.
 * =====================================================================================
 */

#include <stdio.h>
#define LIMIT 100

int main(){
    char s[LIMIT];
    int lim, i, c;
    i = 0;
    lim = LIMIT;
    
    while(i < lim-1){
        if ((c=getchar())!= '\n'){
            if(c!= EOF){
                s[i++] = c;
            }
            else
                break;
        }
        else
            break;
    }
    return 0;
}