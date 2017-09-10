/* This program will contain graph algorithms. More algorithms to be added soon. */

#include <stdio.h>
#include <stdlib.h>

// in-line functions
#define allo (graph *)malloc(sizeof(graph))

// graph ADT
typedef struct graphs
{
	int val, status;
	struct graphs *next;
} graph;

// user-defined functions
void genGraph(graph* adj[], int n); // generate the graph from its adjacency list and size
void display(graph* adj[], int n); // display graph

int main()
{
	int n; // number of nodes
	int i, ch;
	graph *adj[10]; // adjacency list
	
	printf("Enter the number of nodes in the graph (max 10): ");
	scanf("%d", &n);
	if (n > 10)
	{
		printf("You exceeded the limit\n");
		return 0;
	}	
	for (i = 0; i < n; i++) adj[i] = NULL;
	
	genGraph(adj, n);
	printf("The graph is generated\n");
	
	do
	{
		printf("\nMENU \n---- \n1. Display the graph \n-1. Exit \nYour choice: ");
		scanf("%d", &ch);
		if(ch == -1) break;
		
		switch(ch)
		{
			case 1:
				display(adj, n);
				printf("\n");
				break;
			
			default: printf("Wrong choice. Try again\n");
		}
	}while(1);
	
	return 0;
}

void genGraph(graph *adj[], int n)
{
	int i, j, value;
	int nbh; // neighbors of a node
	graph *node, *last;
	
	for (i = 0; i < n; i++)
	{
		last = NULL;
		
		printf("Enter the number of neighbors of node %d: ", i+1);
		scanf("%d", &nbh);
		for (j = 0; j < nbh; j++)
		{
			node = allo;
			node->status = 1;
			
			printf("Enter the value of neighbor %d: ", j+1);
			scanf("%d", &value);
			node->val = value;
			node->next = NULL;
			
			if (adj[i] == NULL) 
				adj[i] = node;
			else 
				last->next = node;
			last = node;
		}
		
		printf("\n");
	}
}

void display(graph *adj[], int n)
{
	graph *ptr;
	int i;
	for (i = 0; i < n; i++)
	{
		ptr = adj[i];
		printf("The neighbors of node %d are: ", i+1);
		while(1)
		{
			printf("%d", ptr->val);
			if (ptr->next == NULL) break;
			printf(", ");
			ptr = ptr->next;
		}
		printf("\n");
	}
}

