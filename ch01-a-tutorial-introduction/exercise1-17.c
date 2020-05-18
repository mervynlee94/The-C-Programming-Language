/*
 * =====================================================================================
 *
 *  Created:  18/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a program to print all input lines that are longer than 80 characters.
 * =====================================================================================
 */

#include <stdio.h>
#define MAXLINE 1000
#define MINLINE 8

// named it getLine due to getline is now a POSIX function declared in stdio.h
int getLine(char line[], int maxline);

int main(){
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getLine(line, MAXLINE)) > 0){
        if (len > MINLINE){
            printf("%s", line);
        }
    }
    
    return 0;
}

int getLine(char s[],int lim){
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
        s[i] = c;
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
