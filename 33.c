#include<stdio.h>
#include<conio.h>

void quicksort(int a[],int first,int last)
{
   int i, j, pivot, temp;

   if(first<last)
   {
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(a[i]<=a[pivot]&&i<last)
            i++;
         while(a[j]>a[pivot])
            j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }

      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quicksort(a,first,j-1);
      quicksort(a,j+1,last);

   }
}

void main(){
   int i, count, arr[25];

   printf("Enter no. of elements: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&arr[i]);

   quicksort(arr,0,count-1);

   printf("Sorted array after Quick Sort: ");
   for(i=0;i<count;i++)
      printf(" %d",arr[i]);

   getch();
}