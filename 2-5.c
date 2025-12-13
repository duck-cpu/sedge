#include <stdio.h>
#include <stdlib.h>

struct node
{
    char value;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void print_list(struct node *head, struct node *tail)
{
    struct node *current = head;
    struct node *currentrev = tail;
    printf("Linked List: ");
    while(current != NULL)
    {
        printf("%c -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
    printf("Reversed Linked List: ");
    while(currentrev != NULL)
    {
        printf("%c -> ", currentrev->value);
        currentrev = currentrev->prev;
    }
    printf("NULL\n");
}

void init_list()
{
    head = malloc(sizeof *head);
    tail = malloc(sizeof *tail);
    
    head->value = 'A'; tail ->value = 'L';
    head->next = tail; tail->next = NULL;
    head->prev = NULL; tail->prev = head;
}

void insert_after(struct node *prev_node, char new_value)
{
    if (prev_node == NULL)
    {
        printf("node cannot be null.");
        return;
    }
    struct node *new_node = malloc(sizeof *new_node);
    new_node->value = new_value;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    prev_node->next = new_node;
    prev_node->prev = new_node->prev->prev;
}

void append(char value)
{
    struct node *new_node = malloc(sizeof *new_node);
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = tail;

    if (tail != NULL)
        tail->next = new_node;
    else
        head = new_node;
    tail = new_node; 
}

void movenexttofront(struct node *t)
{
    if (t->next == NULL)
        return;
    struct node *x = t->next;
    t->next = x->next;
    x->next = head;
    head = x;
}

void exchange(struct node *u, struct node *v)
{   
    struct node *a = u->next;
    struct node *b = v->next;
    
    //a is right before b
    if (a == v)
    {
        struct node *b_next = b->next;
        u->next = b;
        v->next = b_next;
        b->next = v;
    }
    
    //b is right before a
    else if (b == u)
    {
        struct node *a_next = a->next;
        v->next = a;
        u->next = a_next;
        a->next = u;
    }

    //non adjacent
    else
    {
        struct node *a_next = a->next;
        struct node *b_next = b->next;

        u->next = b;
        v->next = a;
        a->next = b_next;
        b->next = a_next;
    }
}

void delete_node(struct node *t)
{
    //struct node *temp = t;
    if (t == NULL)
        return;

    if (t->prev != NULL)
        t->prev->next = t->next;
    else
        head = t->next;

    if (t->next != NULL)
        t->next->prev = t->prev;
    else
        tail = t->prev;

    free(t);
}

int main()
{
    init_list();
    append('I');
    append('S');
    append('T');
    append('Y');
    append('S');
    //exchange(head, head->next);
    delete_node(tail);
    print_list(head, tail);
    return 0;
}
