#include<stdio.h> 
#include<stdlib.h>
#include<conio.h> 

typedef struct linked_list
{ 
	int data; 
	struct linked_list *next; 
}list; 

list *newNode(int);
void insertAtTheBegin(list **, int); 
void bubbleSort(list *); 
void swap(list *, list *); 
void printList(list *); 
void sortedInsert(list**, list*);

void main() 
{ 
	int size, i, val; 

	list *head = NULL; 

	printf("\nEnter number of elements: ");
	scanf("%d",&size);
	printf("\nEnter elements: ");
	for (i = 0; i< size; i++) 
	{
		scanf("%d",&val);
		insertAtTheBegin(&head, val); 
	}
	printf("\n Linked list before sorting "); 
	printList(head); 
	
	bubbleSort(head); 
	
	printf("\n Linked list after sorting "); 
	printList(head); 
	
	printf("\nEnter a number to insert");
	scanf("%d",&val);
	list *new_node = newNode(val);
	sortedInsert(&head, new_node);
	
	printf("\n Linked list after insert"); 
	printList(head); 

	getch(); 
} 

void insertAtTheBegin(list **start, int data) 
{ 
	list *ptr1 = (list*)malloc(sizeof(list)); 
	ptr1->data = data; 
	ptr1->next = *start; 
	*start = ptr1; 
} 

list *newNode(int ndata) 
{ 
	list* node = (list*) malloc(sizeof(list)); 
	node->data = ndata; 
	node->next = NULL; 
	return node; 
} 

void printList(list *start) 
{ 
	list *temp = start; 
	printf("\n"); 
	while (temp!=NULL) 
	{ 
		printf("%d->", temp->data); 
		temp = temp->next; 
	} 
} 

void bubbleSort(list *start) 
{ 
	int swapped, i; 
	list *ptr1; 
	list *lptr = NULL; 

	if (start == NULL) 
		return; 

	do
	{ 
		swapped = 0; 
		ptr1 = start; 

		while (ptr1->next != lptr) 
		{ 
			if (ptr1->data > ptr1->next->data) 
			{ 
				swap(ptr1, ptr1->next); 
				swapped = 1; 
			} 
			ptr1 = ptr1->next; 
		} 
		lptr = ptr1; 
	} 
	while (swapped); 
} 

void swap(list *a, list *b) 
{ 
	int temp = a->data; 
	a->data = b->data; 
	b->data = temp; 
} 

void sortedInsert(list** start, list* new_node) 
{ 
	list* current; 
	if (*start == NULL || (*start)->data >= new_node->data) 
	{ 
		new_node->next = *start; 
		*start = new_node; 
	} 
	else
	{ 
		current = *start; 
		while (current->next!=NULL && 
			current->next->data < new_node->data) 
		{ 
			current = current->next; 
		} 
		new_node->next = current->next; 
		current->next = new_node; 
	} 
} 