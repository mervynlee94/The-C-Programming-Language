/*
 * =====================================================================================
 *
 *  Created:  17/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Revise the main routine of the longest-line program so it will correctly 
 *  print the length of arbitrary long input lines, and as much as possible of the text.
 * =====================================================================================
 */

#include <stdio.h>
#define MAXLINE 10

// named it getLine due to getline is now a POSIX function declared in stdio.h
int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getLine(line, MAXLINE)) > 0){
        if (len > max){
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("%d", max);
    return 0;
}

int getLine(char s[], int lim){
    int c, i;
    for(i = 0 ; i < lim-1 && (c=getchar()) != EOF && c!= '\n'; ++i)
        s[i]=c;
    if(i == (lim-1)){
        s[i] = '\0';
        while((c=getchar()) != EOF && c !='\n')
            ++i;
    }
    else{
        if(c == '\n'){
            s[i] = c;
            ++i;
        }
        s[i] = '\0';
    }
    return i;
}

void copy(char to[], char from[]){
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}