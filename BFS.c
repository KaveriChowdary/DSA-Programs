#include<stdio.h>
#include<stdlib.h>
void BFS(int);
int graph[10][10];
int visited[10] ,total;
void main()
{
  int i,j;
  printf("enter the total no.of vertices of a graph\n");
  scanf("%d",&total);
  printf("\nenter the adjacency matrix of a graph\n");
  for(i=0;i<total;i++)
  {
  	for(j=0;j<total;j++)
  	{
  		scanf("%d",&graph[i][j]);
	  }
  }
  for(i=0;i<total;i++)
  {
  	visited[i]=0;  //not visited any vertex
  }
  printf("\nBFS traversal is :\n");
  BFS(0);
}
void BFS(int vertex)
{
	int j;
	printf("%d\t",vertex);
	visited[vertex]=1;
	for(j=0;j<total;j++)
	{
		if(!visited[j] && graph[vertex][j]==1)
		{
			BFS(j);
		}
	}
}


