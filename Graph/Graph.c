#include<stdio.h>
#include<stdlib.h>

typedef struct Graph
{
  int no_of_vertices;
  int** graphchart;
}graph;

void add_edge(graph g)
{
  int i,j;
  printf("Enter the no of vertices:");
  scanf("%d",&g.no_of_vertices);
  g.graphchart = malloc(sizeof(int*)*g.no_of_vertices);
  for(i=0;i<g.no_of_vertices;i++)
    g.graphchart[i] = malloc(sizeof(int)*g.no_of_vertices);
  for(i=0;i<g.no_of_vertices;i++)
  {
    for(j=0;j<g.no_of_vertices;j++)
    {
      printf("Edge between %d and %d ?",i,j);
      scanf("%d",&g.graphchart[i][j]);
    }
  }

  for(i=0;i<g.no_of_vertices;i++)
  {
    for(j=0;j<g.no_of_vertices;j++)
    {
      printf("%d ",g.graphchart[i][j]);
    }
    printf("\n");
  }
}



int main()
{
  graph g;
  add_edge(g);
  return 0;
}