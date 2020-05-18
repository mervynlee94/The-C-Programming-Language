/*
 * =====================================================================================
 *
 *  Created:  18/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description:Write a function reverse(s) that reverses the character string s. 
 *  Use it to write a program that reverses its input a line at a time.
 * 
 * =====================================================================================
 */

#include <stdio.h>
#define MAXLINE 1000

// named it getLine due to getline is now a POSIX function declared in stdio.h
int getLine(char line[], int maxline);
void reverse(char line[]);

int main(){
    int len;
    int max;
    int i;
    char line[MAXLINE];

    max = 0;
    while((len = getLine(line, MAXLINE)) > 0){
        reverse(line);
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

// hello\n -> olleh\n
void reverse(char line[]){
    int i, j;
    char temp;
    for(j = 0 ; line[j] != '\0'; ++j){
        ;
    }
    --j;
    if(line[j] == '\n'){
        --j;
    }
    for(i = 0; i < j; i++){
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
        --j;
    }
    
}