/*
 * =====================================================================================
 *
 *  Created:  31/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a function escape(s,t) that converts characters like newline and tab into 
 *  visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a 
 *  function for the other direction as well, converting escape sequences into the real characters.


 * =====================================================================================
 */

#include <stdio.h>
#define MAXLINE 1000

void escape(char s[], char t[]);
int getLine(char s[],int lim);

int main(){
    int len;
    char s[MAXLINE], t[MAXLINE];
    while((len = getLine(s, MAXLINE)) > 0){
        escape(s, t);
    }
    printf("%s", t);
    return 0;
}

void escape(char s[], char t[]){
    int i, j;
    for(i = 0, j = 0; s[i] != '\0'; i++, j++){
        switch(s[i]){
            case '\t':
                t[j++] = '\\';
                t[j] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j] = 'n';
                break;
            default:
                t[j] = s[i];
                break;
        }
    }
}

int getLine(char s[],int lim){
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF; ++i){
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}
