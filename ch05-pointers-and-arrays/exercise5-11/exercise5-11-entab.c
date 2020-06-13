/*
 * =====================================================================================
 *
 *  Created:  13/06/2020 
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

int main(int argc, char *argv[]){
    int c, i, space_num;
    int tab[MAXLENGTH] = {0};
    filltab(argc, argv, tab);
    i = 0, space_num = 0;
    while((c=getchar()) != EOF){
        if(c == ' '){
            ++space_num;
            ++i;
            while((c=getchar()) == ' '){
                ++space_num;
                ++i;
                if(tab[i] && (space_num % TAB != 0)){
                    
                    while(space_num){
                        putchar(' ');
                        space_num--;
                    }
                }
                else if(space_num!= 0 && space_num % TAB == 0){
                    putchar('\t');
                    space_num = 0;
                }
            }
            while(space_num){
                putchar('_');
                space_num--;
            }
        }
        if(c == '\n'){
            putchar(c);
            i = 0;
            space_num = 0;
        }
        else{
            putchar(c);
            ++i;
            space_num = 0;
        }
    }
    return 0;
}
   
void filltab(int argc, char* argv[], int *tab){
    int i, inc, pos;
    if(argc <= 1)
        for(i = 1; i < MAXLENGTH; i++){
            if(i % TAB == 0)
                tab[i] = TRUE;
        }
    else{
        while(--argc && i < MAXLENGTH){
            pos = atoi(*++argv);
            printf("pos: %d\n", pos);
            tab[pos] = TRUE;
        }
    }
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