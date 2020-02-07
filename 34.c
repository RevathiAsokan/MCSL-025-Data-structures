#include<stdio.h>
#include <conio.h>
void Adjust(int heap[],int i)  
{
	int j, temp, num, ref = 1;
	num=heap[0];

	while(2*i<=num && ref==1)
	{
		j=2*i;   
		
		if(j+1<=num && heap[j+1] > heap[j])
			j=j+1;	

		if( heap[j] < heap[i])
			ref=0;	
		else
		{
			temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
			i=j;
		}
	}
}

void Make_Heap(int heap[])
{
	int i, n;
	
	n=heap[0];

	for(i=n/2;i>=1;i--)
	Adjust(heap,i);
}

void main()
{
	int arr[30];
	int n, i, last, temp;

	printf("\nEnter no. of elements :");
	scanf("%d",&n);
	
	printf("\nEnter array elements :"); 
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i]);

	arr[0]=n;

	Make_Heap(arr);
	while(arr[0] > 1)
	{
		last=arr[0];
		temp=arr[1];
		arr[1]=arr[last];
		arr[last]=temp;
		arr[0]--;
		Adjust(arr,1);
	}	

	printf("\nSorted Array after Heap Sort :");
	for(i=1;i<=n;i++)
	printf("%d ",arr[i]);
	getch();
}