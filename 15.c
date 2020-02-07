/* to CHECK */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct dq
{
	int info;
	struct dq *left;
	struct dq *right;
}*dqptr;


dqptr p, tp;
dqptr head;
dqptr tail;

dqptr getnode()
{
	p = (dqptr) malloc(sizeof(struct dq));
	return p;
}

void create_list()
{
	int l, x;
	dqptr t;
	
	p=getnode();
	tp = p;
	p->left = getnode();
	p->info = 10;
	p->right = getnode();
	return;
}


int dq_empty(dqptr q)
{
	return q->head == NULL;
}

int eq_front(dqptr q, void *info)
{
	if(d1_empty(q))
		q->head = q->tail = dcons(info, NULL, NULL);
	else
	{
		q->head->left = dcons(info, NULL, NULL);
		q->head->left->right = q->head;
		q->head = q->head->left;
	}
}

int eq_back(dqptr q, void *info)
{
	if(dq_empty(q))
		q->head = q->tail = dcons(info, NULL, NULL)
	else
	{
		q->tail->right = dcons(info, NULL, NULL);
		q->tail->right->left = q->tail;
		q->tail = q->tail->right;
	}
}

int dq_front(dqptr q)
{
	if (dq is not empty)
	{
		dq tp=q->head;
		
		void *info = tp->infop;
		
		q->head = q->head->right;
		
		free(tp);
		
		if(q->head == NULL)
			q->tail == NULL;
		
		return info;
	}
}

int dq_back(dqptr q)
{
	if(q != NULL)
	{
		dq tp = q->tail;
		*info = tp->info;
		q->tail = q->tail->left;
		free(tp);
		if(q->tail == NULL)
			q->head = NULL;
		else
			q->tail->right = NULL;
		
		return info;
	}
}

void main()
{
	int choice, l, x;
	dqptr n;
	dqptr getnode();
	
	printf("\n Enter 1: Start 2: Add at Front 3: Add at Rear 4: Delete at Front 5: Delete at Back");
	
	while(1)
	{
		printf("\n1: Start 2: Add at Front 3: Add at Back 4: Delete at Front 5: Delete at BAck 6: exit");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: create_list();
					break;
			case 2: eq_front();
					break;
			case 3: eq_back();
					break;
			case 4: dq_front();
					break;
			case 5: dq_back();
					break;
			case 6: exit(6);
		}
	}
	getch();
}
		


