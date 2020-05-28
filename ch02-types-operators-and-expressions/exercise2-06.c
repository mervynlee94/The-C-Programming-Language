/*
 * =====================================================================================
 *
 *  Created:  28/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a function setbits(x,p,n,y) that returns x with the n bits that begin 
 *  at position p set to the rightmost n bits of y, leaving the other bits unchanged.
 *
 * =====================================================================================
 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
int main(void) {
	printf("%u", setbits(55, 3, 2, 62));
	return 0;
}

unsigned setbits(unsigned x, int p , int n, unsigned y){
    return (x & ~(~(~0 << n) << (p+1-n))) |  ((y & ~(~0 << n)) << (p+1-n));
    
    /*
    Step 1: Obtain the rightmost 2 bits of y with y & ~(~0 << n)
    62 = 111110
    Therefore you will get 62 & ~(~0 << 2)
     111110
    &000011
    -------
     000010 (2)
    -------
    Step 2: Obtain the the part of x (n bits) that begin on position p and turn it OFF bits, 
    ready to replaced by the rightmost n bits of y using ~(~(~0 << n) << (p+1-n))
    (~0 << n) -> 111100
    ~(~0 << n) -> 000011
    ~(~0 << n) << (p+1-n) -> 001100 (12) The on bits indicate the part to be replaced.
    To replace the parts, we first need to make that parts into off bits
    ~( ~(~0 << n) << (p+1-n) ) -> 110011
    Step 3: We perform AND with x to switch off the respective parts and remain unchanged
    for the rest
    (x & ~(~(~0 << n) << (p+1-n)))
     11(01)11
    &11(00)11
    ---------
     11(00)11   LEFT OUTCOME
    ---------
    Step 4: From Step 1, Since we want replace 0000(10) from y in Step 1 into (00) part in x 11(00)11,
    we need to shift it to correct position with << (p+1-n) behind  y & ~(~0 << n)
    0000(10) << 2 -> 00(10)00     RIGHT OUTCOME
    Now we finally perform OR between the outcome of this step and step 3
     11(00)11   FROM LEFT OUTCOME
    |00(10)00   FROM RIGHT OUTCOME
    ---------
     11(10)11 (59)
    */
}