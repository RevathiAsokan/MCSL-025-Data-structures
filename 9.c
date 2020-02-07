/* Two singly list, print common elements  */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct linked_list
{
	int data;					//data to be stored
	struct linked_list *next;	//pointer to the address of the next data
}list;

void create(list *);			
void compare(list *, list *);				
void traverse(list *);

void main()
{
	list *head1 = NULL, *head2 = NULL;						//initialize list head to NULL

	printf("\nEnter List 1 elements (press -1111 to stop) : \n");
	head1 = (list *)malloc(sizeof(list));	//allocate space required for the list
	create(head1);

	printf("\nEnter List 2 elements (press -1111 to stop) : \n");
	head2 = (list *)malloc(sizeof(list));	//allocate space required for the list
	create(head2);		
	
	printf("\nTraversing the list 1: \n");
	traverse(head1);
	
	printf("\nTraversing the list 2: \n");
	traverse(head2);
	
	compare(head1, head2);
	
	getch();
}

void create(list *start)
{
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

void compare(list *s1, list *s2)
{
	int flag = 0;
	list *temp=s2;
	
	printf("\nThe common elements are: ");
	while(s1->next != NULL)
	{
		while(s2->next != NULL)
		{
			if(s1->data == s2->data)
			{
				flag=1;
				printf("%d\t",s1->data);
			}
			s2=s2->next;
		}
		s1=s1->next;
		s2=temp;
	}
	
	if (flag==0)
		printf("No common elements");
}
