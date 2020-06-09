/*
 * =====================================================================================
 *
 *  Created:  09/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Rewrite appropriate programs from earlier chapters and exercises with 
 *  pointers instead of array indexing. Good possibilities include getline 
 *  (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4), reverse 
 *  (Chapter 3), and strindex and getop (Chapter 4).
 * 
 * =====================================================================================
 */

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100
#define NUMBER '0'

int getLine(char *s, int lim);
void itoa(int n, char *s);
int atoi(char *s);
void reverse(char *s);
int strindex(char *source, char *searchfor);
int getop(char *s);
char line[MAXLINE];

int main(){
    int len, type;
    char c[MAXLINE], s[MAXLINE], line[MAXLINE];
    char pattern[] = "elo";
    char test[] = "Helo World";
    itoa(-214, c);
    printf("%s\n", c);
    printf("%d\n", atoi(c));
    printf("%d\n", strindex(test, pattern));
    while((type = getop(s)) != EOF){
        printf("%c", type);
    }
    return 0;
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

void itoa(int n, char *s){
    int i, sign;
    unsigned int npositive;
    if((sign = n) < 0)
        npositive = -n;
    else 
        npositive = n;
    i = 0;
   do{
       *(s+i++) = npositive%10 + '0';
   }
   while((npositive/=10) > 0);
   if (sign < 0)
        *(s+i++) = '-'; 
    *(s+i) = '\0';
    reverse(s);
}

void reverse(char *s){
    int c, i, j, len;
    for(i = 0, len = 0; *(s+i) != '\0'; i++, len++)
        ;
    for(i = 0, j = len - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
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

int strindex(char *s, char *t){
    int i, j, k, m;
    m = -1;
    for (i = 0; *(s+i) != '\0'; i++) {
        for (j=i, k=0; *(t+k)!='\0' && *(s+j)== *(t+k); j++, k++);
        if (k > 0 && *(t+k) == '\0')
            m = i;
    }
    return m; 
}

int cur = 0;
int getop(char *s){
    int i, c;
    if(*(line+cur) == '\0'){
        if(getLine(line, MAXLINE) == 0)
            return EOF;
        else
            cur = 0;
    }

    while((*s = c = *(line+cur++)) == ' ' || c == '\t')
        ;
    *(s+1) = '\0';
    if(!isdigit(c) && c != '.' && c!= '-')
        return c;
    i = 0;
    if(isdigit(c) || c == '-')
        while(isdigit(*(s+(++i)) = c = *(line+cur++)))
            ;
    if(c == '.')
        while(isdigit(*(s+(++i)) = c = *(line+cur++)))
            ;
    *(s+i) = '\0';
    if(*s == '-' && *(s+1) == '\0'){
        return '-';
    }
    cur--;
    return NUMBER;
}
// int getop(char s[]){
//     int i, c;
//     if (line[cur] == '\0'){
//         if (getLine(line, MAXLINE) == 0)
//             return EOF;
//         else
//             cur = 0;
//     }
    
//     while((s[0] = c = line[cur++]) == ' ' || c == '\t')
//         ;
//     s[1] = '\0';
//     if(!isdigit(c) && c != '.' && c != '-')
//         return c;
//     i = 0;
//     if(isdigit(c) || c == '-')
//         while(isdigit(s[++i] = c = line[cur++]))
//             ;
//     if (c == '.')
//         while(isdigit(s[++i] = c = line[cur++]))
//             ;
//     s[i] = '\0';
//     if(s[0] == '-' && s[1] == '\0'){
//         return '-';
//     }
//     cur--;
//     return NUMBER;
// }