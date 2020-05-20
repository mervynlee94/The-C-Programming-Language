/*
 * =====================================================================================
 *
 *  Created:  20/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a program to check a C program for rudimentary syntax errors 
 *  like unmatched parentheses, brackets and braces. Don't forget about quotes, 
 *  both single and double, escape sequences, and comments. 
 *  (This program is hard if you do it in full generality.)
 * 
 * =====================================================================================
 */

#include <stdio.h>

void inComment();
int inDoubleQuote(int c);
int inSingleQuote(int c);
int inBrace();
int inBracket();

int main(){
    int c;
    int error_found = 0;
    while(!error_found && (c=getchar())!= EOF){
        if(c == '/'){
            if(c == '*')
                inComment();
            else{
                error_found = 1;
                break;
            }
        }
        else if(c == '"')
            error_found = inDoubleQuote(c);
        else if(c == '\'')
            error_found = inSingleQuote(c);
        else if(c == '{')
            error_found = inBrace();
        else if(c == '}')
            error_found = 1;
        else if(c == '(')
            error_found = inBracket();
        else if(c == ')')
            return 1;
        
    }

    printf("Error found: %d", error_found);
    return 0;
}

void inComment(){
    int c, d;
    while((c=getchar()) != EOF && (d=getchar())!= EOF && c!= '*' && d!= '/')
        ;
}

int inDoubleQuote(int c){
    int d;
    while((d=getchar())!= EOF){
        if(d == '\\')
            getchar();
        if(d == c){
            return 1;
        }
    }
    return 0;
}

int inSingleQuote(int c){
    int d;
    
    while((d=getchar())!= EOF){
        if(d == '\\')
            getchar();
        if(d == c){
            return 1;
        }
    }
    return 0;
}

int inBrace(){
    int c, invalid = 0;
    while((c=getchar()) != EOF){
        if(c == '{'){
            invalid = inBrace();
        }
        else if(c == '}'){
            return 0;
        }
        
    }
    return 1;
}

int inBracket(){
    int c, invalid = 0;
     while((c=getchar()) != EOF){
        if(c == '('){
            invalid = inBracket();
        }
        else if(c == ')'){
            return 0;
        }
        
    }
    return 1;
}