/*
 * =====================================================================================
 *
 *  Created:  12/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Modify the program entab and detab (written as exercises in Chapter 1) to
 *  accept a list of tab stops as arguments. Use the default tab settings if there are no 
 *  arguments.
 * =====================================================================================
 */

#include <stdio.h>
#include <ctype.h>
#define MAXLENGTH 100
#define TAB 4
#define TRUE 1
#define FALSE 0

void filltab(int argc, char* argv[], int *tab);
int atoi(char *s);
int compute_n(char* argv[]);
int compute_m(char* argv[]);

int main(int argc, char *argv[]){
    int c, i;
    int tab[MAXLENGTH] = {0};
    filltab(argc, argv, tab);
    i = 0;
    while((c=getchar()) != EOF){
        if(c == '\t'){
            do
                putchar('x');
            while(!tab[++i]);
        }
        else if(c == '\n'){
            i = 0;
            putchar('\n');
        }
        else{ 
            putchar(c);
            i++;
        }
    }
    return 0;

}
   
void filltab(int argc, char* argv[], int *tab){
    int i, inc, pos, n, m;
    if(argc <= 1)
        for(i = 1; i < MAXLENGTH; i++){
            if(i % TAB == 0)
                tab[i] = TRUE;
        }
    else{
        n = compute_n(argv);
        m = compute_m(argv);
        if(n != -1 && m!= -1){
            for(i = m; i < MAXLENGTH; i+=n){
                tab[i] = TRUE;
            }
        }
        else
            printf("error: invalid arguments");
    }
}

int compute_n(char* argv[]){
    if(**++argv == '-')
        return atoi(*argv) * -1;
    else if(**++argv == '-')
        return atoi(*argv) * -1;
    else 
        return -1;
    
}

int compute_m(char* argv[]){
    if(**++argv == '+')
        return atoi(*argv);
    else if(**++argv == '+')
        return atoi(*argv);
    else 
        return -1;
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