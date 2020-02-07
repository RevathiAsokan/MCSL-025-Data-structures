// 26
#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h>

typedef struct node
{ 
	int key; 
	struct node *left; 
	struct node *right; 
	int height; 
}avl; 

int height(avl *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

avl* newNode(int key) 
{ 
	avl* node = (avl*)malloc(sizeof(avl)); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1;
	return(node); 
} 

avl *rightRotate(avl *y) 
{ 
	avl *x = y->left; 
	avl *T2 = x->right; 

	x->right = y; 
	y->left = T2; 

	y->height = max(height(y->left), height(y->right))+1; 
	x->height = max(height(x->left), height(x->right))+1; 

	return x; 
} 

avl *leftRotate(avl *x) 
{ 
	avl *y = x->right; 
	avl *T2 = y->left; 

	y->left = x; 
	x->right = T2; 

	x->height = max(height(x->left), height(x->right))+1; 
	y->height = max(height(y->left), height(y->right))+1; 

	return y; 
} 

int getBalance(avl *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

avl* insert(avl* node, int key) 
{ 
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else 
		return node; 

	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	int balance = getBalance(node); 

	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 
	return node; 
} 

void preOrder(avl *root) 
{ 
	if(root != NULL) 
	{ 
		printf("%d ", root->key); 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 

void main() 
{ 
avl *root = NULL; 

root = insert(root, 15); 
root = insert(root, 25); 
root = insert(root, 2); 
root = insert(root, 4); 
root = insert(root, 3); 
root = insert(root, 1);
root = insert(root, 50);

printf("Preorder traversal of the constructed AVL tree is \n"); 
preOrder(root); 

getch(); 
} 
