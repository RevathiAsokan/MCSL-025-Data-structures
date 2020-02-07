/*Program 1: Product of two matrices*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	int a[10][10], b[10][10], c[10][10], ar, ac, br, bc, i, j, k;

	printf("\nEnter the order of the matrix A:\n");
	scanf("%d %d",&ar, &ac);

	printf("\nEnter the order of the matrix B:\n");
	scanf("%d %d",&br, &bc);

	if(ac != br)
	{
		printf("\nMultilication cannot be performed...!");
		goto end;
	}

	printf("\nEnter the elements of matrix A: \n");
	for(i=0;i<ar;i++)
		for(j=0;j<ac;j++)
			scanf("%d",&a[i][j]);

	printf("\nEnter the elements of matrix B: \n");
	for(i=0;i<br;i++)
		for(j=0;j<bc;j++)
			scanf("%d",&b[i][j]);

	for(i=0;i<ar;i++)
		for(j=0;j<bc;j++)
		{
			c[i][j]=0;
			for(k=0;k<br;k++)
				c[i][j] += a[i][k] * b[k][j];
		}

	printf("Product of (%d x %d) A matrix and (%d x %d) B matrix is (%d x %d) C matrix: \n",ar,ac,br,bc,ar,bc);
	for(i=0;i<ar;i++)
	{
		for(j=0;j<bc;j++)
		{
			printf("%d\t",c[i][j]);
		}

		printf("\n");
	}
	end:
	getch();
}

