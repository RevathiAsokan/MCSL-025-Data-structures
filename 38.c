#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h>

struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 

struct node* newNode(int key) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->key = key; 
	node->left = node->right = NULL; 
	return (node); 
} 
 
struct node *rightRotate(struct node *x) 
{ 
	struct node *y = x->left; 
	x->left = y->right; 
	y->right = x; 
	return y; 
} 
 
struct node *leftRotate(struct node *x) 
{ 
	struct node *y = x->right; 
	x->right = y->left; 
	y->left = x; 
	return y; 
} 

struct node *splay(struct node *root, int key) 
{ 
	if (root == NULL || root->key == key) 
		return root; 

	if (root->key > key) 
	{ 
		if (root->left == NULL) return root; 

		if (root->left->key > key) 
		{ 
			root->left->left = splay(root->left->left, key); 
			root = rightRotate(root); 
		} 
		else if (root->left->key < key) 
		{ 
			root->left->right = splay(root->left->right, key); 

			if (root->left->right != NULL) 
				root->left = leftRotate(root->left); 
		} 

		return (root->left == NULL)? root: rightRotate(root); 
	} 
	else 
	{ 
		if (root->right == NULL) return root; 
		if (root->right->key > key) 
		{ 
			root->right->left = splay(root->right->left, key); 

			if (root->right->left != NULL) 
				root->right = rightRotate(root->right); 
		} 
		else if (root->right->key < key)
		{ 
			root->right->right = splay(root->right->right, key); 
			root = leftRotate(root); 
		} 
		return (root->right == NULL)? root: leftRotate(root); 
	} 
} 

struct node *insert(struct node *root, int k) 
{ 
	if (root == NULL) return newNode(k); 

	root = splay(root, k); 

	if (root->key == k) return root; 

	struct node *newnode = newNode(k); 

	if (root->key > k) 
	{ 
		newnode->right = root; 
		newnode->left = root->left; 
		root->left = NULL; 
	} 
	else
	{ 
		newnode->left = root; 
		newnode->right = root->right; 
		root->right = NULL; 
	} 

	return newnode;
} 

void preOrder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		printf("%d ", root->key); 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 

void main() 
{ 
	struct node *root = newNode(15); 
	root->left = newNode(25); 
	root->right = newNode(2); 
	root->left->left = newNode(4); 
	root->left->left->left = newNode(3); 
	root->left->left->left->left = newNode(1); 
	root = insert(root, 50); 
	printf("Preorder traversal of the modified Splay tree is \n"); 
	preOrder(root); 
	getch(); 
} 
