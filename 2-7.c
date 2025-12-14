#include <stdio.h>
#define LIMIT 100

int a[LIMIT];
char b[LIMIT];
int top = -1;

void push(char c)
{
    for (int i = 0; i < LIMIT; i++)
    {
        if (a[i] == -1)
        {
            a[i] = 1;
            b[i] = c;
            top = i;
            return;
        }
    }
    printf("stack overflow..");
}

void pop()
{
    if (top == -1)
    {
        printf("stack underflow..");
        return;
    }
    a[top] = -1;

    int ntop = -1;
    for (int i = top-1; i >= 0; i --)
    {
        if(a[i] != -1)
        {
            ntop = i;
            break;
        }
    }
    top = ntop;
}

void print_stack(void)
{
    if (top == -1)
    {
        printf("stack is empty.");
        return;
    }

    int count = 1; 
    
    for (int i = top; i >= 0; i--)
    {
        if (a[i] != -1)
        {
            printf("%d: %c\n", count++, b[i]);
        }
    }
    
    if (top != -1)
        //v[top] can be used to action the top.
        printf("top of stack is: a[%d]\n", top);
    else
        printf("stack is empty");
}

int main()
{
    //init a
    for (int i = 0; i < LIMIT; i++)
    {
        a[i] = -1; 
    }
    
    push('E');
    print_stack();
    push('A');
    print_stack();
    push('S');
    print_stack();
    pop();
    print_stack();
    push('Y');
    print_stack();
    pop();
    print_stack();
    pop();
    print_stack();
    push('Q');
    print_stack();
    push('U');
    print_stack();
    push('E');
    print_stack();
    pop();
    print_stack();
    pop();
    print_stack();
    pop();
    print_stack();
    push('S');
    print_stack();
    push('T');
    print_stack();
    pop();
    print_stack();
    pop();
    print_stack();
    pop();
    print_stack();
    push('I');
    print_stack();
    pop();
    print_stack();
    push('O');
    print_stack();
    push('N');
    print_stack();
    pop();
    print_stack();
    pop();
    print_stack();

    return 0;
}
