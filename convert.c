#include <stdio.h>
//exercise 1.4 code
int convert()
{   
    int c;
    int value = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            break;

        int digit = c - '0';
        value = value * 10 + digit;
    }
    return value;
}

int main()
{
    printf("Your integer is: %d", convert());
}
