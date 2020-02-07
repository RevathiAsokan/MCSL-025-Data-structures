//19

 /* C program to implement queues using two stacks */
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

typedef struct nodes
{
    int data;
    struct nodes *next;
}node;

void push(node** top, int data);
int pop(node** top);

typedef struct queue
{
    node *s1;
    node *s2;
}qu;

void enqueue(qu *q, int x)
{
    push(&q->s1, x);
}

void dequeue(qu *q)
{
    int x;
    if (q->s1 == NULL && q->s2 == NULL) 
	{
        printf("Empty Queue");
        return;
    }
    if (q->s2 == NULL) 
	{
        while (q->s1 != NULL) 
		{
        x = pop(&q->s1);
        push(&q->s2, x);
        }
    }
    x = pop(&q->s2);
    printf("%d\n", x);
}

void push(node** top, int data)
{
    node* newnode = (node*) malloc(sizeof(node));
        if (newnode == NULL) 
		{
            printf("Stack overflow \n");
            return;
        }
    newnode->data = data;
    newnode->next = (*top);
    (*top) = newnode;
}

int pop(node** top)
{
    int buff;
    node *t;
    if (*top == NULL) 
	{
        printf("Stack underflow \n");
        return 0;
    }
    else 
	{
        t = *top;
        buff = t->data;
        *top = t->next;
        free(t);
        return buff;
    }
}

void display(node *top1,node *top2)
{
    printf("\nQueue: ");
	while (top1 != NULL) 
	{
        printf("%d\t", top1->data);
        top1 = top1->next;
    }
    while (top2 != NULL) 
	{
        printf("%d\t", top2->data);
        top2 = top2->next;
    }
}

void main()
{
    qu *q = (qu*)malloc(sizeof(qu));
    int f = 0, a;
    char ch = 'y';
    q->s1 = NULL;
    q->s2 = NULL;
    while (ch == 'y'||ch == 'Y') 
	{
        printf("Enter ur choice\n1.Add\n2.Remove\n3.Display\n4.Exit\n");
        scanf("%d", &f);
        switch(f) 
		{
            case 1 : printf("Enter an element to add: ");
                     scanf("%d", &a);
                     enqueue(q, a);
                     break;
            case 2 : dequeue(q);
                     break;
            case 3 : display(q->s1, q->s2);
                     break;
            case 4 : exit(1);
                     break;
            default : printf("Invalid entry...!\n");
        }
	}
	getch();
}