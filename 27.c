#include<stdio.h>
#include<conio.h>
#define INFINITY 99
#define MAX 10
 
void dijkstra(int G[MAX][MAX],int n,int start);
 
void main()
{
	int G[MAX][MAX],i,j,n,u;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	dijkstra(G,n,u);
	
	getch();
}
 
void dijkstra(int G[MAX][MAX],int n,int start)
{
 
	int cost[MAX][MAX],dist[MAX],pred[MAX];
	int visited[MAX],count,minddist,next,i,j;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	for(i=0;i<n;i++)
	{
		dist[i]=cost[start][i];
		pred[i]=start;
		visited[i]=0;
	}
	
	dist[start]=0;
	visited[start]=1;
	count=1;
	
	while(count<n-1)
	{
		minddist=INFINITY;
		
		for(i=0;i<n;i++)
			if(dist[i]<minddist&&!visited[i])
			{
				minddist=dist[i];
				next=i;
			}
			
			visited[next]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(minddist+cost[next][i]<dist[i])
					{
						dist[i]=minddist+cost[next][i];
						pred[i]=next;
					}
		count++;
	}
 
	for(i=0;i<n;i++)
		if(i!=start)
		{
			printf("\nDistance of node %d = %d",i,dist[i]);
			printf("\nPath=%d",i);
			
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=start);
	}
}