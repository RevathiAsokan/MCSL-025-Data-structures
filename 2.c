/*Program 2: To accept 10 strings as input and print them in lexicographic order*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	char str[10][15], temp[15];
	int i,j;

	printf("\nEnter ten strings: \n");
	for(i=0;i<10;i++)
		scanf("%s",&str[i]);

	for(i=0;i<10;i++)
		for(j=i+1;j<11;j++)
		{
			if(strcmp(str[i],str[j]) > 0)
			{
				strcpy(temp,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],temp);
			}
		}

	printf("\nStrings entered in lexicographic order is: \n");

	for(i=0;i<10;i++)
		printf("%s\n",str[i]);

	getch();
}