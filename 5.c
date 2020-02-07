/*Program 5: Student data*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct student
{
	int roll_num;
	char sname[15];
	int marks;
}std;

void main()
{
	std s[100], temp;
	int i, j, n;
	
	printf("Enter the number of students: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\n\nEnter the details of student %d out of %d",i+1,n);
		printf("\nEnter enrollment number: ");
		scanf("%d",&s[i].roll_num);
		fflush(stdin);
		printf("\nEnter name: ");
		scanf("%s",&s[i].sname);
		fflush(stdin);
		printf("\nEnter aggregate marks: ");
		scanf("%d",&s[i].marks);
		fflush(stdin);
	}
	
	printf("\n-------------------------------------------------------------\n");
	printf("\nRoll_num\tStudent Name\tAggregate Marks\t\tRank\n");
    printf("\n-------------------------------------------------------------\n");

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-1-i);j++)
        {
            if(s[j].marks < s[j+1].marks)
            {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            } 
        }		
    }

	for(i=0;i<n;i++)
	{

		printf("%d\t\t%s\t\t%d\t\t\t%d\n",s[i].roll_num,s[i].sname,s[i].marks,i+1);
	}
	
	getch();
}