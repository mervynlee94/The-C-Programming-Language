/*
 * =====================================================================================
 *
 *  Created:  01/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Extend atof to handle scientific notation of the form 123.45e-6
 *  where a floating-point number may be followed by e or E and an optionally signed exponent.
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000 /* maximum input line length */
 
int main(){
    double sum, atof(char s[]);
    char line[MAXLINE];
    int getLine(char line[], int max);
    sum = 0;
    while (getLine(line, MAXLINE) > 0)
       printf("\t%g\n", sum += atof(line));
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
double atof(char s[]){
    double val, power;
    int i, sign, esign, exp, tenth;
    for(i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i]== '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if(s[i] == 'E' || s[i] == 'e')
        i++;
    esign = s[i++];
    for(exp = 0; isdigit(s[i]); i++)
        exp = 10 * exp + (s[i] - '0');
    tenth = 1;
    while(exp--){
        tenth *= 10;
    }
    return (esign == '-') ? sign * (val / power) / tenth : sign * (val / power) * tenth;
}