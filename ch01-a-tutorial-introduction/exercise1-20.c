/*
 * =====================================================================================
 *
 *  Created:  18/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a program detab that replaces tabs in the input with the 
 *  proper number of blanks to space to the next tab stop. Assume a fixed set of 
 *  tab stops, say every n columns. Should n be a variable or a symbolic parameter?
 * 
 * =====================================================================================
 */

#include <stdio.h>
#define TAB 3
int main(){
    int c;
    int offset = 0;
    while((c=getchar()) != EOF){
        if(c == '\n'){
            putchar(c);
            offset = 0;
        }
        else if(c == '\t'){
            // Rather than inserting a fixed number of spaces for each tab, you should
            // be inserting a different number of spaces depending on how much has been
            // printed on the line so far (Tab Stop)
            // Example (with tab = 5)
            // hel\tWorld!
            // Output:
            // hel  World! (2 spaces to be replaced as "hel" took 3 spaces) 
            int num_of_space = TAB - (offset % TAB);
            while(num_of_space-- != 0){
                putchar(' ');
                offset++;
            }
        }
        else{
            putchar(c);
            offset++;
        }
    }
    
    return 0;
}