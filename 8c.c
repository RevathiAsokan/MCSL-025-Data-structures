/* Circular linked list*/ 

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct linked_list
{
	int data;
	struct linked_list *next;
}clist;

clist *head, *s;

void create(clist *);
void traverse(clist *);
clist *find(clist *, int);
clist *delete(clist *);


void main()
{
	head = (clist *)malloc(sizeof(clist));
	s = head;
	
	create(head);
	printf("\nTraversing the list: ");
	traverse(head);
	
	head = delete(head);
	printf("\nTraversing the list: ");
	traverse(head);

	getch();
}
	
void create(clist *start)
{
	int ele;
	printf("Enter the elements (-1111 to stop): ");
	scanf("%d",&ele);
	
	if(ele == -1111)
		start->next = s;
	else
	{	start->data = ele;
		start->next = (clist *)malloc(sizeof(clist));
		create(start->next);
	}
}

void traverse(clist *start)
{
	if(start->next != s)
	{
		printf("%d-->",start->data);
		traverse(start->next);
	}
}

clist *find(clist *start, int key)
{
	if(start->next->data == key)
		return(start);
	
	if(start->next->next == NULL)
		return(NULL);
	else
		find(start->next, key);
}

clist *delete(clist *start)
{
	int key;
	clist *f, *temp;
	
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
		f = find(start, key);
		
		if(f==NULL)
			printf("\nKey not found");
		else
		{
			temp = f->next->next;
			free(f->next);
			f->next = temp;
		}
	}
	return(start);
}