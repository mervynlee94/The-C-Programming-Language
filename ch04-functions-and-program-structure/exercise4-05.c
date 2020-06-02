/*
 * =====================================================================================
 *
 *  Created:  02/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Add access to library functions like sin, exp, and pow. See <math.h> 
 *  in Appendix B, Section 4.
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MATHFUNC 'M'
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
void push(double);
double pop(void);
void clear(void);
void duplicate(void);
void swap(void);
double top(void);
double atof(char s[]);
void mathfunc(char s[]);
int strlength(char s[]);
int strcomp(char s[], char s2[]);

int main(){
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        //printf("%c", type);
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case MATHFUNC:
                mathfunc(s);
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
            case 'c':
                clear();
                break;
            case 't':
                printf("%.8g\n", top());
                break;
            case 's':
                swap();
                break;
            case 'd':
                duplicate();
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

int getop(char s[]){
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if(islower(c)){
        while((s[++i] = c = getch()) && islower(c))
            ;
        s[i] = '\0';
        if(c != EOF){
            ungetch(c);
        }
        
        if(strlength(s) > 1)
            return MATHFUNC;
        else 
            return c;
    }
    if(!isdigit(c) && c != '.')
        return c;
    
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
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

int strlength(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; ++i)
        ;
    return i;
}

int strcomp(char s[], char s2[]){
    int i;
    for(i = 0; (s[i] == s2[i]) && (s[i] != '\0') && (s2[i] != '\0'); ++i)
        ;
    if(s[i] == '\0')
        return 0;
    return 1;
}

void mathfunc(char s[]){
    double op2;
    if(strcomp(s, "sin") == 0)
        push(sin(pop()));
    else if(strcomp(s, "exp") == 0)
        push(exp(pop()));
    else if(strcomp(s, "pow") == 0){
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
        printf("error: %s is not supported\n", s);
}