/*
 * =====================================================================================
 *
 *  Created:  31/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. 
 *  Explain why. Use this observation to write a faster version of bitcount.

 * =====================================================================================
 */

#include <stdio.h>

int bitcount(unsigned x);
int main(){
    /*
    34 = 100010
    */
    printf("%d", bitcount(34));
    return 0;
}

/*
x - 1 is any binary number subtrated by 0000 0001
x - 1 has the property of changing the right most 1 to 0 and right most 0 to 1 by using borrows.
x - 1 has the property of inverting the last bit. So, x & x -1 will always set the last bit to 0.
*/
int bitcount(unsigned x){
    int b;
    for(b=0; x!=0; x &= x-1)
        ++b;
    return b;
}