#include <stdio.h>

// exercise 1.5
void binary(int x)
{
    if (x == 0)
        return;
    binary(x / 2);
    printf("%d", x % 2);
}

int main()
{
    int num;
    while (scanf("%d", &num) != EOF)
    {
        binary(num);
        printf("\n");
    }
}
