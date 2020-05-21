/*
 * =====================================================================================
 *
 *  Created:  22/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Write a function htoi(s), which converts a string of hexadecimal digits 
 *  (including an optional 0x or 0X) into its equivalent integer value. The allowable 
 *  digits are 0 through 9, a through f, and A through F.
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main(void) {
	int res;
	res = htoi("3AAAEF");
	printf("%d", res);
	return 0;
}

int htoi(char s[]){
    int i = 0, n;
    n = 0;
    if(s[0] == '0' && (s[1] == 'X' || s[1] == 'x')){
        i = 2;
    }
    for (; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F')  
        || (s[i] >= 'a' && s[i] <= 'f'); ++i){
        if(isdigit(s[i])){
            n = n * 16 + (s[i] - '0');
        }
        else if(isupper(s[i])){
            n = n * 16 + (s[i] - 55);
        }
        else{
            n = n * 16 + (s[i] - 87);
        }
    }
    return n;
 }