/*
 * =====================================================================================
 *
 *  Created:  31/05/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: Our binary search makes two tests inside the loop, when one would suffice 
 *  (at the price of more tests outside.) Write a version with only one test inside the loop 
 *  and measure the difference in run-time.

 * =====================================================================================
 */

#include <stdio.h>

int binsearch(int x, int v[], int n);
int main(){

    int arr[10] = {2, 3, 5, 6, 8, 11, 14, 17, 21, 24};
    printf("%d", binsearch(21, arr, 10));
    return 0;
}

int binsearch(int x, int v[], int n){
    int low, high, mid;
    low = mid = 0;
    high = n - 1;
    while (low <= high && x!= v[mid]) {
        mid = (low+high)/2; 
        if (x <= v[mid])
            high = mid + 1;
        else
            low = mid + 1;
    }
    if (low <= high)
        return mid;
    return -1; /* no match */ 
}
