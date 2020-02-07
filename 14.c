//18
#include<stdio.h>
#include<conio.h>
#define LEN 10

int dq[LEN];
int front, rear, choice, x, y;

void add_front(int y)
{
	if(front == 0)
	{
		printf("Element can not be added at the front");
		return;
	}
	else
	{
		front  = front - 1;
		dq[front] = y;
		
		if(front == -1) 
			front = 0;
	}
}

int delete_front()
{
	if (front == -1)
		printf("Queue empty");
	else
		return dq[front];
	
	if(front == rear)
		front = rear = -1;
	else
		front = front + 1;
}
	
void add_rear(int y)
{
	if(front == LEN-1)
	{
		printf("Element can not be added at the rear ");
		return;
	}
	else
	{
		rear = rear + 1;
		dq[rear] = y;
		if(rear == -1)
			rear = 0;
	}
}

int delete_rear()
{
	if (rear == -1)
		printf("Deletion is not possible from rear");
	else
	{
		if(front == rear)
			front = rear = -1;
		else
		{
			rear = rear - 1;
			return dq[rear];
		}
	}
}

void main()
{
	int choice, x;
	front = rear = -1;	
	
	do
	{
	printf("\n MENU \n 1. Add Front \n 2. Remove Front \n 3. Add Rear \n 4. Remove Rear");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1: printf("Enter element to be added: ");
				scanf("%d",&x);
				add_front(x);
				break;
		case 2: printf("%d deleted",delete_front());
				break;
		case 3: printf("Enter the element to be added: ");
				scanf("%d",&x);
				add_rear(x);
				break;
		case 4: printf("%d deleted",delete_rear());
				break;
		case 5: printf("Exiting program");
				break;
		default: printf("Invalid Entry..!");
	}
	}while(choice !=5);
	getch();
}