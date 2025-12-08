#include <stdio.h>
#define n 10
//exercise 2.1
int gcd(int u, int v)
{
    int t;
    while (u > 0)
    {
        if (u < v)
        {
            t = u;
            u = v;
            v = t;
        }
        u = u - v;
    }
    return v;
}

int main()
{
    int i, j;
    int x[n][n];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (gcd(i, j) == 1)
                x[i][j] = 1;
            else
                x[i][j] = 0; //or break? return?

            printf("x[i][j] = %d", x[i][j]); printf("\n");
        }
        printf("\n");
    }
    return 0;
}
