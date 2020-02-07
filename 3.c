/*Program 3: To accept two strings, check if string2 is a substring of string1 and display location*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	char str1[50], str2[10];
	int len1, len2, i, j, flag, count=0;

	printf("\nEnter first string: \n");
	gets(str1);
	len1 = strlen(str1);

	printf("\nEnter second string: \n");
	scanf("%s",&str2);
	len2 = strlen(str2);

	for(i=0;i<=len1;i++)
	{
		for(j=i;j<i+len2;j++)
		{
			flag=1;

			if(str1[j] != str2[j-i])
			{
				flag=0;
				break;
			}
		}

		if(flag == 1)
		{
			printf("\nFound at position %d",i+1);
			count++;
		}
	}

	if(count == 0)
		printf("\nNot found");

	getch();
}


