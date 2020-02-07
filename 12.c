//16)
#include <stdio.h>  
#include <string.h> 
#include<conio.h> 
#define max 100  

int top,stack[max];  
  
void push(char x)
{   
      if(top == max-1) 
          printf("stack overflow");  
      else  
          stack[++top]=x;  
}  
  
void pop()
{  
      printf("%c",stack[top--]);  
}    
  
void main()  
{  
   char str[20];  
   int len, i;
   
   printf("\nEnter a string: ");
   gets(str);
   
   len = strlen(str);  
  
   for(i=0;i<len;i++)  
        push(str[i]);  
  
   printf("\nReverse string: ");
   for(i=0;i<len;i++)  
		pop();  
  
	getch();
} 