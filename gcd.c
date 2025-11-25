#include <stdio.h>
#include <limits.h>

// exercise 1.3 code
typedef struct
{
    int numerator;
    int denominator;
} fraction;

// prototype, too lazy to move simplify
int gcd(int u, int v);

fraction simplify(fraction *f)
{
    int common = gcd(f->numerator, f->denominator);

    f->numerator /= common;
    f->denominator /= common;
}

void binary(int x)
{
    int value = 0;
    if (x == 0)
        return;
    binary(x / 2);
    printf("%d", x % 2);
}

// exercise 1.8
int gcd3(int u, int v, int w)
{
    int t = gcd(u, v);
    w = gcd(t, w); 
    return w;
}

int gcd(int u, int v)
{
    //int count = 0;
    int t;
    while (u > 0)
    {
        if (u < v)
        {
            t = u;
            u = v;
            v = t;
        }
        // exercise 1.6
        //printf("u = %d, v = %d\n", u, v);
        //count++;
        //printf("%d\n", count);
        u = u - v;
    }

    /* exercise 1.2 code
    if (v < 0)
    {
        return u % v;
    }
    */
    //printf("Final count is: %d\n", count);
    return v;
}

int main()
{
    /* fraction f;

    while (scanf("%d/%d", &f.numerator, &f.denominator) != EOF)
    {
        simplify(&f);
        printf("Your fraction reduced is: %d/%d\n", f.numerator, f.denominator);
    }
    */

    // exercise 1.9
    int a = INT_MAX;
    int b = INT_MAX - 1;
    int g = gcd(a, b);
    
    printf("MAXIMUM PAIR WHERE GCD IS %d IS %d/%d", g, a, b);

    //int x, y, z;

    //while (scanf("%d %d %d", &x, &y, &z) != EOF)
    //{
        // exercise 1.2 code
        //if (x > 0 && y > 0 && z > 0)
            //printf("X=%d Y=%d Z=%d GCD=%d\n", x, y, z, gcd3(x, y, z));
    //}
}
