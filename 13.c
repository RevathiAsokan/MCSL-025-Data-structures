//17)
#include <stdio.h>
#include<conio.h>

#define max 10
 
int top1, top2, sarr[max];
 
void push();
void pop();
void display();
 
void main()
{
	int ch;
	top1=-1,top2=max;
	
	do
	{
		printf("\n 1:push\n 2:pop\n 3:display\n 4:exit\n choice:");
		scanf("%d", &ch);

		switch (ch)
		{
			case 1:push();
					break;
			case 2:pop();
					break;
			case 3:display();
					break;
			case 4:printf("exiting from program\n");
					break;
			default:printf("wrong choice\n");
					break;
		}
	}while(ch!=4);
	
	getch();
}

void push()
{
	int x,ch;
		
	if(top1==top2-1)
	{
		printf("stack overflow \n");
		return;
	}

	printf("enter a no \n");
	scanf("%d",&x);
	printf("\n press 1 to push in stack1 or press 2 for stack2:");
	scanf("%d",&ch);
	
	if(ch==1)
	sarr[++top1]=x;
	else
	sarr[--top2]=x;
	printf("\n %d element is successfully pushed \n",x);
	return;
}
 
void pop()
{
	int y,ch;
	printf("\n press 1 to pop from stack1 or press 2 for stack2");
	scanf("%d",&ch);

	if(ch==1)
	{
		if(top1==-1)
		{
			printf("stack underflow\n");
			return;
		}
		y=sarr[top1];
		sarr[top1--]=0;
	}
	else
	{
		if(top2==max)
		{
			printf("stack underflow\n");
			return;
		}
		y=sarr[top2];
		sarr[top2++]=0;
	}
	printf("\n%d element is successfully poped from stack \n", y);
	return;
}
 
void display()
{
	int i;
	if (top1 == -1)
	{
		printf("stack 1 is empty \n");
	}
	else
	{
		printf("elements of Stack 1 are : \n");
		for (i = 0; i <= top1; i++)
		{
			printf("%d\n",sarr[i]);
		}
	}
	if (top2 == max)
	{
		printf("stack 2 is empty \n");
	}
	else
	{
		printf("elements of Stack 2 are : \n");
		for (i = max-1; i >= top2; i--)
		{
			printf("%d\n",sarr[i]);
		}
	}
	return ;
}