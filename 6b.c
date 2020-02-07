/* Program 6: Multiply two sparse matrices FINAL*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20

typedef struct
{
	int row;
	int col;
	int value;
}term;

void readSparse(term b[]);
void fastTranspose(term b[],term newb[]);
void multiply(term a[],term b[],term c[]);
int compare(int colA, int colnewB);
void storeSum(term c[], int *totalD, int row, int column, int *sum);
void printSparse(term b[]);

void main()
{
    term a[MAX],b[MAX],c[MAX];
    readSparse(a);
    readSparse(b);
    multiply(a,b,c);
    printSparse(c);
    getch();
}

void readSparse(term b[])
{
    int i,numTerms, numRows, numCols, prevRow=-1, prevCol=-1;
    printf("\nEnter size of the matrix:");
    scanf("%d%d",&b[0].row,&b[0].col);
    printf("\nEnter no. of non-zero elements:");
    scanf("%d",&b[0].value);

    numRows = b[0].row;
	numCols = b[0].col;
	numTerms = b[0].value;

    printf("\nEnter the triples:\n(row\tcolumn\tvalue) \n");
	printf("%d\t%d\t%d\n",numRows,numCols,numTerms);
	
	
	for(i=1;i<=numTerms;i++)
    {
		scanf("%d%d%d",&b[i].row,&b[i].col,&b[i].value);
		
		if ((b[i].row >= numRows) || (b[i].col >= numCols))
		{
			printf("\nRow number or Column number is greater than its size");
			printf("\nInvalid entry...!");
			getch();
			exit(0);
		}	
		
		if(prevRow >= 0 || prevCol >= 0)
		{
			if((b[i].row <= prevRow) && ((b[i].row == prevRow) && (b[i].col < prevCol)))
			{
				printf("\nTriples entry must be ordered by row and within rows by columns");
				printf("\nInvalid entry...!");
				getch();
				exit(0);
			}

			if(b[i].row == prevRow)
				prevCol = b[i].col;
			else
				prevCol = 0;
		
			prevRow = b[i].row;
		}
		else
		{
			prevCol = b[i].col;
			prevRow = b[i].row;
		}
    }
}

void multiply(term a[],term b[],term c[])
{   
    term newB[MAX];
	int i=0, j=0, row=0, column=0, rowsA, colsA, colsB, totalA, totalB, totalC=0;
	int rowBegin=1, sum = 0;
	
	rowsA = a[0].row;
	colsA = a[0].col;
	colsB = b[0].col;
	totalA = a[0].value;
	totalB = b[0].value;
	row = a[1].row;
	
	if(colsA != b[0].row)
	{
		printf("Incompatible matrices");
		getch();
		exit(1);
	}
	
	fastTranspose(b, newB); /* set boundary condition */
	a[totalA + 1].row = rowsA;
	newB[totalB + 1].row = colsB;
	newB[totalB + 1].col = 0;
	
	for(i=1;i<=totalA;)
	{
		column = newB[1].row;
		
		for(j=1; j<=totalB + 1;)
		{
								/* multiply row of a by column of b */
			if(a[i].row != row)
			{
				storeSum(c, &totalC, row, column, &sum);
				i = rowBegin;
				
				for(; newB[j].row == column; j++);
				
				column = newB[j].row;
			}
			else if(newB[j].row != column)
			{
				storeSum(c, &totalC, row, column, &sum);
				i = rowBegin;
				column = newB[j].row;
			}
			else 
			switch(compare(a[i].col, newB[j].col))
			{
				case -1: i++;
						break;
				case 0: sum += (a[i++].value * newB[j++].value);
						break;
				case 1: j++;
			}
		}
		
		for(; a[i].row == row; i++);
		
		rowBegin = i;
		row = a[i].row;
	}
	
	c[0].row = rowsA;
	c[0].col = colsB;
	c[0].value = totalC;
}


void fastTranspose(term a[],term b[])
{
	int numRows,numCols,numTerms,i,cols,loc;
    int rowTerms[MAX],startPos[MAX];

    numRows=a[0].row;
	numCols=a[0].col;
	numTerms=a[0].value;
	
    b[0].row=numCols;
	b[0].col=numRows;
	b[0].value=numTerms;
	
	if(numTerms > 0)
	{	
		for(i=0;i<numCols;i++)
			rowTerms[i]=0;
    
		for(i=1;i<=numTerms;i++)
			rowTerms[a[i].col]++;
    
		startPos[0]=1;
    
		for(i=1;i<numCols;i++)
			startPos[i]=startPos[i-1]+rowTerms[i-1];

		for(i=1;i<=numTerms;i++)
		{
			loc=startPos[a[i].col]++;
			b[loc].row=a[i].col;
			b[loc].col=a[i].row;
			b[loc].value=a[i].value;
		}
	}
}	


int compare(int colA, int colnewB)
{
	if(colA < colnewB)
		return (-1);
	else if (colA == colnewB)
		return(0);
	else
		return(1);
}

void storeSum(term c[], int *totalC, int row, int column, int *sum)
{
					/* if *sum!=0, then it along with its row and column position is stored as the
						*totalC + 1 entry in C*/
	if(*sum)
		if(*totalC < MAX)
		{
			c[++*totalC].row = row;
			c[*totalC].col = column;
			c[*totalC].value = *sum;
			*sum = 0;
		}
		else
		{
			printf("Number of terms in product exceeds %d",MAX);
			getch();
			exit(1);
		}
}

void printSparse(term b[])
{
    int i,numTerms;
    numTerms=b[0].value;   //no of 3-triples
   
	printf("\nProduct of two sparse matrix is : ");
	printf("\n(row\tcol\tvalue)\n");
    
	for(i=0;i<=numTerms;i++)
        printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].value);
}