/*
 * =====================================================================================
 *
 *  Created:  27/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write the function any(s1,s2), which returns the first location in a string 
 *  s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from 
 *  s2. (The standard library function strpbrk does the same job but returns a pointer to the 
 *  location.)
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <limits.h>

int any(char s1[],char s2[]);

int main(void) {
	char s1[] = "abbbbbccccccddeee";
    char s2[] = "ce";
    int idx;
    idx = any(s1, s2);
    printf("%d", idx);
	return 0;
}

int any(char s1[], char s2[])
{
    int charmap[256];
    int i, idx = -1;
    for(i = 0 ; i < 256 ; i++)
        charmap[i] = 0;
    for(i = 0 ; s2[i] != '\0' ; i++){
        charmap[s2[i]]++;
    }
    for(i = 0 ; s1[i] != '\0' && idx == -1; i++){
        if(charmap[s1[i]] != 0){
            idx = i;
        }
    }
    return idx;
}