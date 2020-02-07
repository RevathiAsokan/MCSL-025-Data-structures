//Rec 20 and 21 // BINARY SEARCH TREE
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
    struct node *l;
    struct node *r;
}bt;
bt *root = NULL, *temp = NULL, *t1;

void search_node(bt* root, int key);
void insert();
void inorder(bt *t);
void create();
void search(bt *t);
void search_node(bt *tree,int data);

void main()
{
    int ch, num;
     
    printf("\nOPERATIONS ---");
    printf("\n1 - Insert an element into tree\n");
    printf("2 - Inorder Traversal\n");
    printf("3 - Search\n");
    printf("4 - Exit\n");
    
	while(1)
    {
        printf("\nEnter your choice : ");
		scanf("%d", &ch);
        
		switch (ch)
        {
            case 1: insert();
					break;
            case 2: printf("\nIn-order: ");
					inorder(root);
					break;
            case 3: printf("\nEnter node to search: ");
					scanf("%d",&num);
					search_node(root, num);
					break;
			case 4: exit(0);
            default : printf("Invalid Entry...! ");
					   break;    
        }
    }
}

void insert()
{
    create();
	
    if (root == NULL) 
        root = temp;
    else    
        search(root);    
}

void create()
{
    int data;

	printf("Enter data of node : ");
    scanf("%d", &data);

    temp = (bt *)malloc(1*sizeof(bt));
	temp->value = data;
    temp->l = temp->r = NULL;
}

void search(bt *t)
{
	if ((temp->value > t->value) && (t->r != NULL)) /* value more than root node value insert at right */
		search(t->r);
	else if ((temp->value > t->value) && (t->r == NULL))
		t->r = temp;
	else if ((temp->value < t->value) && (t->l != NULL))// value less than root node value insert a left
		search(t->l);
    else if ((temp->value < t->value) && (t->l == NULL))
        t->l = temp;
}

void search_node(bt* root, int key) 
{ 
	if(root!=NULL)
	{
		if (root->value == key) 
			printf("Found");
		else if (root->value < key) 
			search_node(root->r, key); 
		else if(root->value > key)
			search_node(root->l, key); 
	}
	else
	printf("Not found");
} 

void inorder(bt *t)
{
	if (root == NULL)
    {
		printf("No elements in a tree to display");
        return;
    }

    if (t->l != NULL)    
		inorder(t->l);

    printf("%d -> ", t->value);

    if (t->r != NULL)    
		inorder(t->r);
}