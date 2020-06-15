/*
 * =====================================================================================
 *
 *  Created: 15/06/2020 
 *  Compiler:
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write the program tail, which prints the last n lines of its input. 
 *  By default, n is set to 10, let us say, but it can be changed by an optional 
 *  argument so that tail -n prints the last n lines. The program should behave rationally 
 *  no matter how unreasonable the input or the value of n. Write the program so it 
 *  makes the best use of available storage; lines should be stored as in the sorting 
 *  program of Section 5.6, not in a two-dimensional array of fixed size.
 * 
 * =====================================================================================
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLINES 5000
#define ALLOCSIZE 10000
#define MAXLEN 100

char *lineptr[MAXLINES];
char allocbuf[ALLOCSIZE];
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int n);
int getLine(char *s, int lim);
int atoi(char *s);

int main(int argc, char *argv[]){
    int nlines, n;
    if(argc == 1)
        n = 10;
    else if(argc == 2 && **++argv == '-')
        n = atoi(*argv) * -1;
    else{
        printf("error: invalid args");
        return 1;
    }
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        writelines(lineptr, nlines, n);
        return 0;
    }
    else{
        printf("error: input too big\n");
        return 1;
    }
}

int getLine(char *s, int lim){
    int c, i;
    for(i=0; i<lim-1 && (c=getchar())!= EOF && c!='\n'; ++i){
        *(s+i) = c;
    }
    if(c == '\n'){
        *(s+i) = c;
        ++i;
    }
    *(s+i) = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];
    p = allocbuf;
    char *endoflimit = allocbuf + ALLOCSIZE;
    nlines = 0;
    while((len = getLine(line, MAXLEN)) > 0){
        if(nlines >= maxlines || (p + len > endoflimit)){
            return -1;
        }
        else{
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p+= len;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines, int n){
    int i;
    if(nlines - n < 0)
        n = nlines;
    for(i = nlines - n; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

int atoi(char *s){
    int i, n, sign;
    n = 0;
    for(i = 0; isspace(*(s+i)); i++)
        ;
    sign = (*(s+i) == '-') ? -1 : 1;
    if(*(s+i) == '-' || *(s+i) == '+')
        i++;
    for(; isdigit(*(s+i)) ; ++i)
        n = 10 * n + (*(s+i) - '0');
    return sign * n;
}