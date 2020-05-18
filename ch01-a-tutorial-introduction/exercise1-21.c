/*
 * =====================================================================================
 *
 *  Created:  18/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a program entab that replaces strings of blanks by the 
 *  minimum number of tabs and blanks to achieve the same spacing. 
 *  Use the same tab stops as for detab. 
 *  When either a tab or a single blank would suffice to reach a tab stop, 
 *  which should be given preference?
 * 
 * =====================================================================================
 */

#include <stdio.h>
#define TAB 3
#define IN 1
#define OUT 1

int main(){
    int c, num_of_tab, space_remained, state, num_of_space;
    num_of_space = 0;
    while((c=getchar()) != EOF){
        if(c == ' '){
            ++num_of_space;
            state = IN;
            while((c=getchar()) == ' ')
                ++num_of_space;
            
            num_of_tab = num_of_space/TAB;
            space_remained = num_of_space%TAB;
            
            while(num_of_tab-- != 0)
                putchar('\t');
            while(space_remained-- != 0)
                putchar(' ');
        }
        if(state == IN){
            state = OUT;
            putchar(c);
            num_of_space = 0;
        }
        else{
            putchar(c);
            state = OUT;
            num_of_space = 0;
        }
    }
    
    return 0;
}