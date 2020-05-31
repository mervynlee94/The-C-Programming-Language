/*
 * =====================================================================================
 *
 *  Created:  31/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a function expand(s1,s2) that expands shorthand notations like a-z 
 *  in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters 
 *  of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. 
 *  Arrange that a leading or trailing - is taken literally.

 * =====================================================================================
 */

#include <stdio.h>
#define MAXLINE 1000

int getLine(char s[],int lim);
void expand(char s1[], char s2[]);

int main(){
    int len;
    char s[MAXLINE], t[MAXLINE];
    while((len = getLine(s, MAXLINE)) > 0){
        expand(s, t);
    }
    printf("%s", t);
    return 0;
}

void expand(char s1[], char s2[]){
    int i, j, k;
    for(i=0, j=0; s1[i] != '\0'; i++){
        if(s1[i] == '-' && i != 0){
            for(k = s1[i-1]+1; k < s1[i+1]; k++){
                s2[j++] = k;
            }
        }
        else{
            s2[j++] = s1[i];
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

