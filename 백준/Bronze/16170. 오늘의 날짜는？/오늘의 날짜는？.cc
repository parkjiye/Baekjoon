#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
 
int main()
{
    time_t t = time(NULL);
    struct tm tm = *gmtime(&t);
    printf("%d\n%d\n%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}
