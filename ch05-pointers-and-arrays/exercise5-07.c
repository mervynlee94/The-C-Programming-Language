/*
 * =====================================================================================
 *
 *  Created:  10/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Rewrite readlines to store lines in an array supplied by main, rather than 
 *  calling alloc to maintain storage. How much faster is the program?
 * 
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#define MAXLINES 5000
#define ALLOCSIZE 10000
#define MAXLEN 100

char *lineptr[MAXLINES];
char allocbuf[ALLOCSIZE];
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int getLine(char *s, int lim);
int main(){
    int nlines;
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else{
        printf("error: input too big to sort \n");
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

void writelines(char *lineptr[], int nlines){
    while(nlines--){
        printf("%s\n", *(lineptr++));
    }
}

void qsort(char* v[], int left, int right){
    int i, last;
    void swap(char *v[], int left, int right);
    if(left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for(i = left+1; i <= right; i++)
        if(strcmp(v[i], v[left]) < 0)
            swap(v, i, ++last);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j){
    char *tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}
