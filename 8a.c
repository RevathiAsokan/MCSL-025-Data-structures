/* Program 8a: Creation of a singly linked list */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct linked_list
{
	int data;					//data to be stored
	struct linked_list *next;	//pointer to the address of the next data
}list;

void create(list *);			
int count(list *);				
void traverse(list *);
list *insertList(list *);
list *deleteList(list *);
list *find(list *, int);

void main()
{
	list *head = NULL;						//initialize list head to NULL

	head = (list *)malloc(sizeof(list));	//allocate space required for the list
	create(head);							
	
	printf("\nTraversing the list \n");
	traverse(head);
	
	printf("\n\nNumber of elements in the list: %d\n",count(head));
	
	head = insertList(head);
	printf("\n\nTraversing the list\n");
	traverse(head);
	
	printf("\n\nNumber of elements in the list: %d\n",count(head));

	head = deleteList(head);
	printf("\n\nTraversing the list\n");
	traverse(head);
	
	printf("\n\nNumber of elements in the list: %d\n",count(head));

	getch();
}

void create(list *start)
{
	printf("\nEnter the element (press -1111 to stop) : ");
	scanf("%d",&start->data);
	
	if(start->data == -1111)
		start->next = NULL;
	else
	{
		start->next = (list *)malloc(sizeof(list));
		create(start->next);
	}
}

void traverse(list *start)
{
	if(start->next != NULL)
	{
		printf("%d-->",start->data);
		traverse(start->next);
	}
}

int count(list *start)
{
	if(start->next == NULL)
		return 0;
	else	
		return(1 + count(start->next));
}

list *insertList(list *start)
{
	list *n, *f;
	int key, ele;
	
	printf("\nEnter value of new element: ");
	scanf("%d",&ele);
	
	if(start->next != NULL)
	{
		printf("\nEnter value of key element: ");
		scanf("%d",&key);
	}
	else
		key = -1111;
	
	if(start->data == key)
	{
		n = (list *)malloc(sizeof(list));
		n->data = ele;
		n->next = start;
		start = n;
	}
	else
	{
		f = find(start, key);
		
		if(f == NULL)
			printf("\nKey not found \n");
		else
		{
			n=(list*)malloc(sizeof(list));
			n->data = ele;
			n->next = f->next;
			f->next = n;		
		}
	}
	return(start);
}

list *deleteList(list *start)
{
	int key;
	list *f, *temp;
	
	printf("\nEnter the value of element to be deleted: ");
	scanf("%d",&key);
	
	if(start->data == key)
	{
		temp = start->next;
		free(start);
		start = temp;
	}
	else
	{
		f =find(start, key);
		
		if(f==NULL)
			printf("\nKey not found..!");
		else
		{
			temp = f->next->next;
			free(f->next);
			f->next = temp;
		}
	}
	return(start);
}

list *find(list *start, int key)
{
	if(start->next->data == key)
		return(start);
	
	if(start->next->next == NULL)
		return(NULL);
	else
		find(start->next, key);
}