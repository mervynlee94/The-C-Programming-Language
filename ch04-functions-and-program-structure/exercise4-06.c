/*
 * =====================================================================================
 *
 *  Created:  03/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Add commands for handling variables. (It's easy to provide twenty-six 
 *  variables with single-letter names.) Add a variable for the most recently printed value
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

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

 void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
 }

int getop(char []);
double pop(void);
void push(double);
double atof(char s[]);

/*
The postfix notation for assigning to variables is like this 10 A =
10 A = -15 B = A B +
*/
int main(){
    int type, var;
    double op2, v, variable[26];
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        //printf("%c", type);
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
            case '\n':
                v = pop();

                printf("\t%.8g\n", v);
                break;
            case '=':
                pop();
                if(var >= 'A' && var <= 'Z')
                    variable[var-'A'] = pop();
                else 
                    printf("error: no variable found\n");
                break;
            default:
                if(type >= 'A' && type <= 'Z')
                    push(variable[type-'A']);
                else if( s[0] == 'v')
                    push(v);
                else
                    printf("error: unknown command %s.\n", s);
                break;
        }
        var = type;
    }
    return 0;
}

int getop(char s[]){
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
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
        ungetch(c);
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

double top(void){
    if(sp > 0){
        return val[sp-1];
    }
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
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

void duplicate(void){
    push(top());
}

void swap(void){
    double tmp;
    if (sp < 2)
        printf("error: can't swap, not enough items");
    else{
        tmp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = tmp; 
    }
}

void clear(void){
    sp = 0;
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
