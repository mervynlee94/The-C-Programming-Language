/*
 * =====================================================================================
 *
 *  Created:  17/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: How would you test the word count program? 
 *  What kinds of input are most likely to uncover bugs if there are any?
 * 
 * =====================================================================================
 */

#include <stdio.h>
#define IN 1 /* inside a word */ 
#define OUT 0 /* outside a word */

int main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw; 
    }
}
    printf("%d %d %d\n", nl, nw, nc); 
}

/*
Example Input:
- Lines with normal characters, tabs and spaces
- Blank input
- With tab only
- With space only
*/