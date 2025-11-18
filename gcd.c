#include <stdio.h>

//exercise 1.3 code
typedef struct
{
    int numerator;
    int denominator;
} fraction;

//prototype, too lazy to move simplify
int gcd(int u, int v);

fraction simplify(fraction *f)
{
    int common = gcd(f->numerator, f->denominator);

    f->numerator /= common;
    f->denominator /= common;
}

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
    fraction f;

    while (scanf("%d/%d", &f.numerator, &f.denominator) != EOF)
    {
        simplify(&f);
        printf("Your fraction reduced is: %d/%d\n", f.numerator, f.denominator);
    }

    /* while (scanf("%d %d", &x, &y) != EOF)
    {   
        //exercise 1.2 code
        // if (x>0 && y>0)
        printf("X=%d Y=%d GCD=%d\n", x, y, gcd(x,y))
    }
    */
}
