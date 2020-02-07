/*Program 4: To concatenate two strings*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	char str1[20], str2[20];
	static int i=0;
	int j=0;

	printf("\nEnter first string: ");
	scanf("%s",&str1);

	printf("\nEnter second string: ");
	scanf("%s",&str2);


	while(str1[i]!='\0')
	i++;

	while(str2[j]!='\0')
	{
		str1[i] = str2[j];
		j++;
		i++;
	}

	str1[i] = '\0';

	printf("\nConcatenated string is %s",str1);

	getch();
}