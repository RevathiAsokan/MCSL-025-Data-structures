#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	int arr[20], *p, n, i, item;
	
	printf("\nEnter the no. of elements: ");
	scanf("%d",&n);
	
	printf("\nEnter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	printf("\nEnter element to search: ");
	scanf("%d",&item);
	
	p=arr;
	
	for(i=0;i<n;i++)
	{
		if(item == *p)
		{
			printf("\n%d found at position %d\n",item,i+1);
			break;
		}
		p++;
	}
	
	if(i==n)
		printf("\n%d not found",item);
	
	getch();
}