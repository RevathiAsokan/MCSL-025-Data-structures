/*Doubly linked list*/

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

typedef struct doubly_linked_list
{
	int data;
	struct doubly_linked_list *right;
	struct doubly_linked_list *left;
}dlist;

void create(dlist *);
void traverse(dlist *);
void deletion_specified(dlist *);  

void main()
{
	dlist *start;
	int num;
	
	start = (dlist *)malloc(sizeof(dlist));
	start->left = NULL;
	start->right= NULL;
	
	create(start);
	printf("\nTraversing the list: " );
	traverse(start);

	deletion_specified(start);	
	printf("\nTraversing the list: " );
	traverse(start);
	
	getch();
}

void create(dlist *start)
{
	printf("\nEnter list (-1111 to stop): ");
	scanf("%d",&start->data);
	
	if(start->data != -1111)
	{
		start->right = (dlist *)malloc(sizeof(dlist));
		start->right->left = start;
		start->right->right = NULL;
		create(start->right);
	}
	else
		start->right = NULL;
}

void traverse(dlist *start) 
{ 
    dlist *last; 
    printf("\nTraversal in forward direction \n"); 
    while (start->right != NULL) 
	{ 
        printf("%d-->", start->data); 
        last = start; 
        start = start->right; 
    } 
  
    printf("\nTraversal in reverse direction \n"); 
    while (last != NULL) 
	{ 
        printf("%d<--", last->data); 
        last = last->left; 
    } 
}

void deletion_specified(dlist *ptr)  
{  
    dlist *temp;  
    int val; 
	
    printf("\n\nEnter the data after which the node is to be deleted : ");  
    scanf("%d", &val);    
    
	while(ptr->data != val)  
		ptr = ptr->right;  
    
	if(ptr->right == NULL)  
        printf("\nNode not found\n");  
    else if(ptr->right->right == NULL)  
        ptr->right = NULL;  
    else  
    {   
        temp = ptr->right;  
        ptr->right = temp->right;  
        temp->right->left = ptr;  
        free(temp);  
        printf("\nNode deleted");  
    }     
}