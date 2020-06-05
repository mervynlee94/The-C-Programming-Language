/*
 * =====================================================================================
 *
 *  Created:  04/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: An alternate organization uses getline to read an entire input line; 
 *  this makes getch and ungetch unnecessary. Revise the calculator to use this approach.
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100
#define MAXVAL 100
#define NUMBER '0'

int cur = 0;
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* stack */
int getLine(char s[], int lim);
double pop(void);
void push(double);
double atof(char s[]);
int getop(char s[]);
char line[MAXLINE];

int main(){
    
    int i;
    int type;
    double op2;
    char s[MAXLINE];

    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else 
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if(op2 != 0.0)
                    push((int)pop() % (int)op2);
                else 
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    
    return 0;
}

int getLine(char s[], int lim){
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c; 
    if (c == '\n')
        s[i++] = c; s[i] = '\0';
    return i; 
}

void push(double f){
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
   
}


double pop(void){
    if(sp > 0){
        return val[--sp];
    }
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
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


int getop(char s[]){
    int i, c;
    if (line[cur] == '\0'){
        if (getLine(line, MAXLINE) == 0)
            return EOF;
        else
            cur = 0;
    }
    
    while((s[0] = c = line[cur++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;
    if(isdigit(c) || c == '-')
        while(isdigit(s[++i] = c = line[cur++]))
            ;
    if (c == '.')
        while(isdigit(s[++i] = c = line[cur++]))
            ;
    s[i] = '\0';
    if(s[0] == '-' && s[1] == '\0'){
        return '-';
    }
    cur--;
    return NUMBER;
}