/* Program 6: Multiply two sparse matrices without using structures - DONT DELETE */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20

void read_sparse(int b[MAX][3]);
void fast_transpose(int a[MAX][3],int b[MAX][3]);
void multiply(int a[MAX][3],int b[MAX][3],int c[MAX][3]);
void print_sparse(int b[MAX][3]);

void main()
{
    int a[MAX][3],b[MAX][3],c[MAX][3];
    read_sparse(a);
    read_sparse(b);
    multiply(a,b,c);
    print_sparse(c);
    getch();
}

void read_sparse(int b[MAX][3])
{
    int i,t;
    printf("\nEnter size of the matrix:");
    scanf("%d%d",&b[0][0],&b[0][1]);
    printf("\nEnter no. of non-zero elements:");
    scanf("%d",&t);

    b[0][2]=t;

    printf("\n Enter the triples:\n(row\tcolumn\tvalue) \n");
	for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
    }
}

void fast_transpose(int a[MAX][3],int b[MAX][3])
{
    int m,n,t,i,col,loc;
    int total[MAX],index[MAX];

    m=a[0][0];
	n=a[0][1];
	t=a[0][2];
    b[0][0]=n;
	b[0][1]=m;
	b[0][2]=t;
    
	for(i=0;i<n;i++)
        total[i]=0;
    for(i=1;i<=t;i++)
    {
        col=a[i][1];
        total[col]++;
    }
    
	index[0]=1;
    
	for(i=1;i<n;i++)
        index[i]=index[i-1]+total[i-1];

    for(i=1;i<=t;i++)
    {
        col=a[i][1];
        loc=index[col];
        index[col]++;
        b[loc][0]=a[i][1];
        b[loc][1]=a[i][0];
        b[loc][2]=a[i][2];
    }
} 

void multiply(int a[MAX][3],int b[MAX][3],int c[MAX][3])
{   
	int newb[MAX][3];
    int i,j,k,ar,bc,i1,sum,t1,t2;
    
	t1=a[0][2];
	t2=b[0][2];
    
	if(a[0][1]!=b[0][0])
    {
        printf("\n can not multiply");
        exit(0);
    }
    
	fast_transpose(b,newb);   /* a in row major form and b in column
    major form ,as for multiplication,dot product of a row of a
    with column of b is taken  */
    k=1;       //index for c
    i=1;
    
	while(i<=t1)
    {
        i1=i;
        j=1;
        while(j<=t2)
        {
            ar=a[i][0];
            bc=newb[j][0];
            sum=0;

        while(i<=t1 && j<=t2 && ar==a[i][0] && bc==newb[j][0])
        {
            if(a[i][1]==newb[j][1])
                {
                sum=sum+a[i][2]*newb[j][2];
                i++;j++;
                }
            else
                if(a[i][1]<newb[j][1])
                    i++;
                else
                    j++;
        }
        if(sum!=0)
        {
            c[k][0]=ar;
            c[k][1]=bc;
            c[k][2]=sum;
            k++;
        }
        if(j<=t2)
            i=i1;
        while(bc==newb[j][0] && j<=t2)
            j++;
    }
    while(ar==a[i][0] && i<=t1)
        i++;
    }
    c[0][0]=a[0][0];
    c[0][1]=newb[0][0];
    c[0][2]=k-1;
}

void print_sparse(int b[MAX][3])
{
    int i,n;
    n=b[0][2];   //no of 3-triples
    
	printf("\nrows = %d\tcolumns = %d",b[0][0],b[0][1]);
    printf("\n");
    
	for(i=0;i<=n;i++)
        printf("%d\t%d\t%d\n",b[i][0],b[i][1],b[i][2]);
}