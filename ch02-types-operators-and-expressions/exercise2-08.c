/*
 * =====================================================================================
 *
 *  Created:  28/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a function rightrot(x,n) that returns the value of the integer x 
 *  rotated to the right by n positions.
 *
 * =====================================================================================
 */

#include <stdio.h>

unsigned rightrot(unsigned x,int n);
int wordlength();
int main(void) {
    /*
    00000000 00000000 00000000 10011001 (153)
    right rotation x 2
    01000000 00000000 00000000 00100110 (1073741862)
    */
	printf("%u",rightrot(153, 2));
	return 0;
}
unsigned rightrot(unsigned x, int n){
    return  (x >> n) | (x << (wordlength() - n));
}

int wordlength(){
    int i;
    unsigned v = (unsigned) ~0;
    for(i = 1; (v = v>>1) !=0 ; i++)
        ;
    
    return i;
}