/*
 * =====================================================================================
 *
 *  Created:  18/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a program to ``fold'' long input lines into 
 *  two or more shorter lines after the last non-blank character 
 *  that occurs before the n-th column of input. Make sure your
 *  program does something intelligent with very long lines, 
 *  and if there are no blanks or tabs before the specified column.
 * 
 * =====================================================================================
 */

#include <stdio.h>
#define LIMIT 10
#define TAB 8
#define NO_BLANK -1  /*signifies no blank found */

int lastblank(const char arr[], int len);

int main(){
    int c;          
    int i, j;       
    int pos;        /* current position in array */
    int col;        /* current column of output */
    int lbc;        /* last blank character position */
    char line[LIMIT + 1];
    
    pos = col = 0;
    while ((c = getchar()) != EOF) {
        line[pos++] = c;
        if(c == '\t'){
            col = col + TAB - (col % TAB);
        }
        else
            ++col;
        if (col >= LIMIT || c == '\n') {
            line[pos] = '\0';
            if((lbc = lastblank(line, pos)) == NO_BLANK){
                for(i = 0; i < pos; i++){
                    putchar(line[i]);
                }
                col = pos = 0;
            }
            else{
                for(i = 0; i < lbc; i++)
                    putchar(line[i]);
                for(i = 0, j = lbc+1, col = 0; j < pos; ++i, ++j){
                    line[i] = line[j];   
                    if(c == '\t'){
                        col = col + TAB - (col % TAB);
                    }
                    else
                        ++col; 
                }
                pos = i;
            }
            putchar('\n');
        }
    }
       
}

int lastblank(const char arr[], int len){
    int i, lbc = -1;
    for (i = 0; i < len; ++i)
        if (arr[i] == ' ' || arr[i] == '\t' || arr[i] == '\n')
            lbc = i;
    return lbc;
}