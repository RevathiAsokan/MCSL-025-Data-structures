   // Records 20
	#include <stdio.h>
    #include <stdlib.h>
	#include<conio.h>
    typedef struct node 
	{
        int data;
        struct node* left;
        struct node* right;
    }bt;
    
	void inorder(bt* root)
	{
        if(root == NULL) return;
        inorder(root->left);
        printf("%d ->", root->data);
        inorder(root->right);
    }
    
	void preorder(bt* root)
	{
        if(root == NULL) return;
        printf("%d ->", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
	void postorder(bt* root) 
	{
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        printf("%d ->", root->data);
    }
    
	bt* createNode(int value)
	{
        bt* newNode = malloc(sizeof(bt));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
	bt* insertLeft(bt *root, int value) 
	{
        root->left = createNode(value);
        return root->left;
    } 
    
	bt* insertRight(bt *root, int value)
	{
        root->right = createNode(value);
        return root->right;
    }
	
	void deltree(bt * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}
    void main()
	{
		bt* root = createNode(1);
        insertLeft(root, 2);
        insertRight(root, 3);
        
        insertLeft(root->left, 4);
        insertRight(root->left, 5);
        
        printf("\nInorder traversal : \n");
        inorder(root);
        printf("\nPreorder traversal : \n");
        preorder(root);
        printf("\nPostorder traversal : \n");
        postorder(root);
		
		deltree(root);
		printf("\nDeleted tree");
		getch();
    }