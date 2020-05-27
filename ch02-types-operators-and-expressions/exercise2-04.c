/*
 * =====================================================================================
 *
 *  Created:  27/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write an alternative version of squeeze(s1,s2) that deletes each character 
 *  in s1 that matches any character in the string s2.
 *
 * =====================================================================================
 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void) {
	char s1[] = "abbbbbccccccddeee";
    char s2[] = "dae";
    squeeze(s1, s2);
    printf("%s", s1);
	return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    for (i = 0; s2[i] != '\0'; i++) {
        for(j = k = 0; s1[j] != '\0' ; j++){
            if(s2[i] != s1[j]){
                s1[k++] = s1[j];
            }
        }
        s1[k] = '\0';
    }
}