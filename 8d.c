 /*C Program to Implement Circular Doubly Linked List                 */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
 
typedef struct node
{
    int val;
    struct node *next;
    struct node *prev;    
}cdlist;
 
cdlist* create_node(int);
void add_node();
void delete_node_position();
void display_from_beg();
void display_in_rev();
 
cdlist *new, *ptr, *prev;
cdlist *first = NULL, *last = NULL;
int number = 0;
 
void main()
{
	add_node();
	display_from_beg();
	display_in_rev();
	
	delete_node_position();
	display_from_beg();
	display_in_rev();
	
	getch();
}
/*
 *MEMORY ALLOCATED FOR NODE DYNAMICALLY
 */
cdlist *create_node(int info)
{
    number++;
    new = (cdlist *)malloc(sizeof(cdlist));
    new->val = info;
    new->next = NULL;
    new->prev = NULL;
    return new;
}
/*
 *ADDS NEW NODE
 */
void add_node()
{
 
    int info;
 
    printf("\nEnter elements (-1111 to stop): ");
    scanf("%d", &info);
	
	if(info !=-1111)
	{
		new = create_node(info);
 
		if (first == last && first == NULL)
		{
 
			first = last = new;
			first->next = last->next = NULL;
			first->prev = last->prev = NULL;
		}
		else
		{
			last->next = new;
			new->prev = last;
			last = new;
			last->next = first;
			first->prev = last;
		}
		
		add_node();
	}
}

void delete_node_position()
{    
    int pos, count = 0, i;
    cdlist *temp, *prevnode;
 
    printf("\nEnter the position of node to delete:");
    scanf("%d", &pos);
 
    if (first == last && first == NULL)
        printf("\nEMPTY LIST");
    else
    {
        if (number < pos)
            printf("\nError: Exceeding the linkedlist length");
 
        else
        {
            for (ptr = first,i = 1;i <= number;i++)
            {
                prevnode = ptr;
                ptr = ptr->next;
                if (pos == 1)
                {    
                    number--;
                    last->next = prevnode->next;
                    ptr->prev = prevnode->prev;
                    first = ptr;
                    printf("Node %d deleted", prevnode->val);
                    free(prevnode);
                    break;        
                }
                else if (i == pos - 1)
                {    
                    number--;
                    prevnode->next = ptr->next;
                    ptr->next->prev = prevnode;
                    printf("Node %d deleted", ptr->val);
                    free(ptr);
                    break;
                }
            }
        }
    }
}


void display_from_beg()
{
    int i;
    if (first == last && first == NULL)
        printf("\nEmpty list");
    else
    {    
        printf("\nTraversing from beginning: \n");
		for (ptr = first, i = 0;i < number;i++,ptr = ptr->next)
            printf("%d-->", ptr->val);
    }
}

void display_in_rev()
{
    int i;        
    if (first == last && first == NULL)
        printf("\nEmpty list");
    else
    {
        printf("\nTraversing from reverse: \n");
		for (ptr = last, i = 0;i < number;i++,ptr = ptr->prev)
        {
            printf("%d<--", ptr->val);
        }
    }
}