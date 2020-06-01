/*
 * =====================================================================================
 *
 *  Created:  01/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write the function strindex(s,t) which returns the position of the rightmost 
 *  occurrence of t in s, or -1 if there is none.

 * =====================================================================================
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getLine(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */ 
int main(){
    char line[MAXLINE]; int found = 0;
    while (getLine(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++; 
        }
        return found;
   }
/* getLine: get line into s, return length */ 
int getLine(char s[], int lim){
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c; 
    if (c == '\n')
        s[i++] = c; s[i] = '\0';
    return i; 
}
/* strindex: return index of t in s, -1 if none */ 
int strindex(char s[], char t[]){
    int i, j, k, m;
    m = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++);
        if (k > 0 && t[k] == '\0')
            m = i;
    }
    return m; 
}