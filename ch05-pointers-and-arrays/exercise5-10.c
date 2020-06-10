/*
 * =====================================================================================
 *
 *  Created:  11/06/2020
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write the program expr, which evaluates a reverse Polish expression from 
 *  the command line, where each operator or operand is a separate argument. For example,
 *  expr 2 3 4 + * evaluates 2 * (3+4).
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100 /* maximum depth of val stack */

char buf[BUFSIZE];
int bufp = 0;
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* stack */

 int getch(void){
     return (bufp > 0) ? buf[--bufp] : getchar();
 }

 void ungetch(char c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
 }

int getop(char []);
void push(double);
double pop(void);
double atof(char s[]);

/* 
The reason that * is causing issues is that it is a shell wildcard.
You are calling the program from your shell and the argument is passing 
to the shell first, which expands it into a list of all files in the 
current folder. If you use the escape sequence \* instead of * as an
argument while calling your c program, you should get the expected result.

The code supports floating point operations by taking argument as string, 
and push into stack buffer in reverse order
For example:
./a.out 2.34 5.67 \*
*/
int main(int argc, char *argv[]){
    int type, i;
    double op2;
    
    while(--argc){
        ungetch(' ');
        char tmp[MAXOP];
        char s[MAXOP];
        strcpy(tmp, (*++argv));
        for(i = strlen(tmp)-1; i >= 0 ; i--)
            ungetch(tmp[i]);
        switch(getop(s)){
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
    printf("%.8g\n", pop());
    return 0;
}

int getop(char s[]){
    int i, c;
    static int buf = 0;
    if(buf == 0){
        c = getch();
    }
    else{
        c = buf;
        buf = 0;
    }
    while((s[0] = c) == ' ' || c == '\t')
        c = getch();
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;
    if(c == '-' || isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        buf = c;
    if(s[0] == '-' && s[1] == '\0'){
        return '-';
    }
    return NUMBER;
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