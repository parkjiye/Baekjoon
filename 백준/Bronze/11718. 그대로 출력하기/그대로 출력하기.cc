#include <stdio.h>

char string;

int main()
{
    while (scanf("%c", &string) != EOF)
    {
        printf("%c", string);
    }
    return 0;
}