#include <stdio.h>
#define PEOPLE 100

int p[PEOPLE];
int k, c, a;

int main()
{   
    k = 3;
    c = 0;
    a = PEOPLE;
    
    //init arr
    for (int i = 0; i < PEOPLE; i++)
        p[i] = 1;
    
    //josephus logic
    for (int i = 0; a > 1; i++)
    {
        if (i == PEOPLE)
            i = 0;
        
        if (p[i] == 1){
            c++;

            if (c == k)
            {
                p[i] = 0; //kill
                a--;
                c = 0;
            }
        }
    }

    //print
    for (int i = 0; i < PEOPLE; i++)
        if (p[i] == 1)
            printf("SURVIVOR OF JOSEPHUS IS: %d!\n", i);
}
