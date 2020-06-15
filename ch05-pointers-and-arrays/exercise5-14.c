/*
 * =====================================================================================
 *
 *  Created:  15/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Modify the sort program to handle a -r flag, which indicates sorting in 
 *  reverse (decreasing) order. Be sure that -r works with -n.
 * 
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000
#define ALLOCSIZE 10000
#define MAXLEN 100

char *lineptr[MAXLINES];
char allocbuf[ALLOCSIZE];
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void myqsort(void *lineptr[], int left, int right,
            int (*comp)(void *, void *));
int numcmp(const char *, const char *);
int mystrcmp(const char *, const char *);
int getLine(char *s, int lim);
static char reverse = 0;
static char numeric = 0;
int main(int argc, char *argv[]){
    int nlines, c;
    while(argc-- > 1 && (*++argv)[0] == '-'){
        if((c = (*argv)[1])){
            switch(c){
                 case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 2;
                    break;
                default:
                    printf("error: illegal flag");
                    break;
            }
        }
    }
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        myqsort((void**)lineptr, 0, nlines-1, 
            (int (*)(void *, void*)) (numeric ? numcmp: mystrcmp));
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
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
    
}

void myqsort(void* v[], int left, int right,
            int (*comp)(void *, void *)){
    int i, last;
    void swap(void *v[], int left, int right);
    if(left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for(i = left+1; i <= right; i++)
        if((*comp)(v[i], v[left]) < 0)
            swap(v, i, ++last);
    swap(v, left, last);
    myqsort(v, left, last-1, comp);
    myqsort(v, last+1, right, comp);
}

void swap(void *v[], int i, int j){
    void *tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

int numcmp(const char *s1, const char *s2){
    char const *p1 = reverse ? s2 : s1;
    char const *p2 = reverse ? s1 : s2;
    double v1, v2;
    v1 = atof(p1);
    v2 = atof(p2);
    if(v1 < v2)
        return -1;
    else if(v1 > v2)
        return 1;
    else
        return 0;
}

int mystrcmp(const char *s1, const char *s2){
    char const *p1 = reverse ? s2 : s1;
    char const *p2 = reverse ? s1 : s2;
    return strcmp(p1, p2);
}