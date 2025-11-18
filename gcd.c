#include <stdio.h>

int gcd(int u, int v)
{
    int t;
    while  (u > 0)
    {
        if (u < v)
        {
            t = u;
            u = v;
            v = t;
        }
        u = u-v;
    }

    //exercise 1.2 code 
    if (v < 0)
    {
        return u % v;
    }
    return v;
}

int main()
{
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF)
    {   
        //exercise 1.2 code
        // if (x>0 && y>0)
        printf("X=%d Y=%d GCD=%d\n", x, y, gcd(x,y));
    }
}
