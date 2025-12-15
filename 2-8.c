#include <stdio.h>
#define LIMIT 100

int a[LIMIT];
char b[LIMIT];
char get[LIMIT];
int get_count = 0;

int dequeue(char *out)
{
    int i;
    
    for (i = 0; i < LIMIT; i++)
    {
        if (a[i] == 1)
        {
            *out = b[i];
            
            if (get_count < LIMIT)
                get[get_count++] = *out;

            break;
        }
    }

    if (i == LIMIT)
        return 0;
    
    for (i = 0; i < LIMIT - 1; i++)
    {
        a[i] = a[i + 1];
        b[i] = b[i + 1]; 
    }

    a[LIMIT - 1] = 0;
    b[LIMIT - 1] = 0;

    return 1;
}

void enqueue(char v)
{   
    for (int i = 0; i < LIMIT; i++)
    {
        if (a[i] == 0)
        {
            a[i] = 1;
            b[i] = v;
            return;
        }
    }
}

void print_queue()
{
    int count = 0;
    for (int i = 0; i < LIMIT; i++)
    {
        if (a[i] == 1)
            printf("%d: %c\n", count++, b[i]);
    }
}

void print_get()
{
    for (int i = 0; i < get_count; i++)
        printf("received: %c\n", get[i]);
}

int main()
{
    char x;
    //init a
    for (int i = 0; i < LIMIT; i++)
    {
        a[i] = 0;
        b[i] = 0;
        get[i] = 0;
    }

    enqueue('E');
    enqueue('A');
    enqueue('S');
    dequeue(&x);
    enqueue('Y');
    dequeue(&x);
    dequeue(&x);
    enqueue('Q');
    enqueue('U');
    enqueue('E');
    dequeue(&x);
    dequeue(&x);
    dequeue(&x);
    enqueue('S');
    enqueue('T');
    dequeue(&x);
    dequeue(&x);
    dequeue(&x);
    enqueue('I');
    dequeue(&x);
    enqueue('O');
    enqueue('N');
    dequeue(&x);
    dequeue(&x);
    print_queue();
    print_get();
}
