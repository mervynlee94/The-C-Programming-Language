/*
 * =====================================================================================
 *
 *  Created:  28/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a function invert(x,p,n) that returns x with the n bits that begin at 
 *  position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
 *
 * =====================================================================================
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
int main(void) {
	printf("%u", invert(55, 4, 4));
	return 0;
}
unsigned invert(unsigned x, int p, int n){
    return  x ^ (~(~0 << n) << (p+1-n)); 
}