/*
 * =====================================================================================
 *
 *  Created:  18/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a program to remove trailing blanks and tabs from each line of input, 
 *  and to delete entirely blank lines.
 * 
 * =====================================================================================
 */

#include <stdio.h>
#define MAXLINE 1000

// named it getLine due to getline is now a POSIX function declared in stdio.h
int getLine(char line[], int maxline);

int main(){
    int len;
    int max;
    int i;
    char line[MAXLINE];

    max = 0;
    while((len = getLine(line, MAXLINE)) > 0){
        int has_nl = 0;
        
        for(i = len-1; (line[i] == ' '
            || line[i] == '\t' || line[i] == '\n'); i--)
            if(line[i] == '\n')
                has_nl = 1;     
        
        if(has_nl)
            line[++i] = '\n';
        line[++i] = '\0';
        printf("%s", line);
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
