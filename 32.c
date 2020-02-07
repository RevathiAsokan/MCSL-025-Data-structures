#include <stdio.h> 
#include<conio.h>
#include<stdlib.h>

int binarySearch(int arr[], int l, int r, int *x) 
{ 
if (r >= l) 
{ 
		int mid = l + (r - l)/2; 

		if (arr[mid] == *x) return mid; 

		if (arr[mid] > *x) return binarySearch(arr, l, mid-1, x); 

		return binarySearch(arr, mid+1, r, x); 
} 
return -1; 
} 

void main() 
{ 
int arr[10], n, i, result, item;
int *p;

printf("\nEnter no. of elements: ");
scanf("%d",&n);

printf("\nEnter array elements: ");
for(i=0;i<n;i++)
	scanf("%d",&arr[i]);

printf("\nEnter search element: ");
scanf("%d",&item);

p = &item;
result = binarySearch(arr, 0, n-1, p); 
(result == -1)? printf("%d not found",item) 
				: printf("%d is present at position %d", item, result+1); 
getch();
} 
