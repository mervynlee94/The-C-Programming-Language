/*
 * =====================================================================================
 *
 *  Created:  08/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write the function strend(s,t), which returns 1 if the string t occurs at the
 *  end of the string s, and zero otherwise.
 * 
 * =====================================================================================
 */

#include <stdio.h>

int strend(char *s, char *t);

int main(){
    char s[] = "Something";
    char t[] = "ing";
    printf("%d\n", strend(s, t));
    char t2[] = "one";
    printf("%d\n", strend(s, t2));
    return 0;
}

int strend(char *s, char *t) {
    for(; *s != *t; s++)
        ;
    for(; *s == *t; s++, t++)
        if(*s == '\0')
            return 1;
    return 0;
}