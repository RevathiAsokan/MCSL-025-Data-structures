/* Program 8: Creation of a list */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct
{
	int data[10];
	int count;
}list;

void insert(list *, int, int);
void create(list *);
void traverse(list *);
void delete(list *, int);

void insert(list *start, int position, int element)
{
	int temp = start -> count;
	
	while(temp >= position)
	{
		start->data[temp+1] = start->data[temp];
		temp--;
	}
	
	start->data[position] = element;
	start->count++;
}

void create(list *start)
{
	int i=0, flag =1;
	
	printf("\nEnter the values of list(Press -1111 to stop): \n");
	while(flag)
	{
		fflush(stdin);
		scanf("%d",&start->data[i]);
		
		if(start->data[i] == -1111)
			flag = 0;
		else
			i++;
	}
	start->count = i;
}

void traverse(list *start)
{
	int i;
	
	for(i=0;i<start->count;i++)
		printf("%d --> ",start->data[i]);
}

void delete(list *start, int position)
{
	int temp = position;
	
	printf("\nDeleted: %d\n",start->data[position]);
	
	while(temp <= start->count-1)
	{
		start->data[temp] = start->data[temp+1];
		temp++;
	}
	start->count = start->count - 1;
}

void main()
{
	int position, element;
	list l;
	
	create(&l);
	printf("\nThe list entered is : \n");
	fflush(stdin);
	traverse(&l);
	fflush(stdin);
	printf("\nEnter the position to insert : ");
	scanf("%d",&position);
	fflush(stdin);
	printf("\nEnter the value : ");
	scanf("%d",&element);
	insert(&l, position, element);
	printf("\nThe list after insert is : \n");
	traverse(&l);
	printf("\nEnter the position of the data to delete: ");
	scanf("%d",&position);
	fflush(stdin);
	delete(&l, position);
	printf("\nThe list after delete is : \n");
	traverse(&l);
	
	getch();
}
		
