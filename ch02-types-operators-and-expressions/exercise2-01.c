/*
 * =====================================================================================
 *
 *  Created:  20/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a program to determine the ranges of char, short, int, and
 *  long variables, both signed and unsigned, by printing appropriate values from 
 *  standard headers and by direct computation. Harder if you compute them: determine 
 *  the ranges of the various floating-point types.
 * =====================================================================================
 */

#include <stdio.h>
#include <limits.h>

int main(){
    printf("Min Signed Char: %d\n", CHAR_MIN );
    printf("Max Signed Char: %d\n", CHAR_MAX);
    printf("Min Signed Short : %d\n", SHRT_MIN);
    printf("Max Signed Short : %d\n", SHRT_MAX);
    printf("Min Signed Int: %d\n", INT_MIN);
    printf("Max Signed Int: %d\n", INT_MAX);
    printf("Min Signed Long: %ld\n", LONG_MIN);
    printf("Max Signed Long: %ld\n", LONG_MAX);
    printf("Max Unsigned Char %d\n", UCHAR_MAX);
    printf("Max Unsigned Short: %d\n", USHRT_MAX);
    printf("Max Unsigned Int: %u\n", UINT_MAX);
    printf("Max Unsigned Long: %lu\n", ULONG_MAX);
    return 0;
}