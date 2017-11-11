#include <stdio.h>
#include <stdlib.h>

int *x, n, m; // solution array (x)

void nextValue(int k, int graph[n][n]);
void mColoring(int k, int graph[n][n]);

int main()
{
	int i, j;
	printf("Enter the number of colors: ");
	scanf("%d", &m);
	
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	
	x = (int *)malloc(n*sizeof(int));
	for (i = 0; i < n; i++) x[i] = 0;
	int graph[n][n];
	
	printf("Enter the adjacency matrix of the graph:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);
	}
	
	printf("\nThe solution array is:\n");
	mColoring(0, graph);
	
	return 0;
}

void mColoring(int k, int graph[n][n])
{
	int i;
	nextValue(k, graph);
	if (x[k] == 0) return;
	if (k == n-1)
	{
		for (i = 0; i < n; i++) 
			printf("%d ", x[i]);
		printf("\n");
	}
	else mColoring(k+1, graph);	
}

void nextValue(int k, int graph[n][n])
{
	int i;
	
	while(1)
	{
		x[k] = (x[k]+1) % (m+1); // fetch the next color using this formula
		if (x[k] == 0) return; // all colors have been tried
		
		for (i = 0; i < n; i++)
		{
			int con1 = (graph[i][k] != 0); // if (i,k) is an edge
			int con2 = (x[i] == x[k]); // if the adjacent vertices have same color
			if (con1 && con2) break;
		}
		if (i == n) return; // all vertices have beeen colored
	}	
}