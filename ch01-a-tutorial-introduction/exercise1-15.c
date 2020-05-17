/*
 * =====================================================================================
 *
 *  Created:  17/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Rewrite the temperature conversion program of Section 1.2 
 *  to use a function for conversion.
 * =====================================================================================
 */

#include <stdio.h>

float fahr_to_celsius(float fahr);

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = fahr_to_celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

float fahr_to_celsius(float fahr)
{
    return 5.0 * (fahr-32.0) / 9.0;
}