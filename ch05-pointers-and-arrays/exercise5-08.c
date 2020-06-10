/*
 * =====================================================================================
 *
 *  Created:  10/06/2020 
 *  Compiler:  
 *      Apple clang version 11.0.3 (clang-1103.0.32.29)
 *      Target: x86_64-apple-darwin19.4.0
 *      Thread model: posix
 *  Description: There is no error checking in day_of_year or month_day. Remedy this defect.
 * 
 * =====================================================================================
 */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(){
    int day, m, d;
    day = day_of_year(2020, 2, 29);
    printf("%d\n", day);
    month_day(2020, 366, &m, &d);
    printf("%d  %d\n", m, d);
    return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day){
    int i, leap;
    if((year >= 0) && (month >= 1) && (month <= 12) && (day >= 1) && (day <= 31)){
        leap = year%4 == 0 && year%100 != 0 || year%400==0;
        if(leap && month == 2 && day > 29){
            printf("Febuary in leap year out of range\n");
            return -1;
        }
        if(!leap && month == 2 && day > 28){
            printf("Febuary in non-leap year out of range\n");
            return -1;
        }
        
        for(i = 1; i < month; i++)
            day += daytab[leap][i];
        return day;
    }
    else{
        printf("error: year/month/day out of range\n");
        return -1;
    }
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday){
    int i, leap;
    if(year >= 0 && yearday <= 366){
        leap = year%4 == 0 && year%100 != 0 || year%400==0;
        if(!leap && yearday > 365){
            printf("error: yearday out of range\n");
            *pmonth = -1;
            *pday = -1;
            return;
        }

        for(i = 1; yearday > daytab[leap][i]; i++)
            yearday -= daytab[leap][i];
        *pmonth = i;
        *pday = yearday;
    }
    else{
        printf("error: year/yearday out of range\n");
        *pmonth = -1;
        *pday = -1;
        return;
    }
}