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
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    while(celsius <= upper){
        fahr = ((9.0/5.0) * celsius) + 32.0;
        printf("%3.0f %6.1f\n", fahr, celsius);
        celsius = celsius + step;
    }
}