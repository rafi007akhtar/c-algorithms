/* 
Representation of the following graph.
G(V) = {0, 1, 2, 3, 4} 
ADJACENCY LIST
---------------
0 -> 1 -> 4
1 -> 0 -> 2 -> 3 -> 4
2 -> 1 -> 3
3 -> 1 -> 2 -> 4
4 -> 0 -> 1 -> 3

The problem info and its program can also be found at:
http://www.geeksforgeeks.org/graph-and-its-representations/
*/

#include <stdio.h>
#include <stdlib.h>

// inline functions
#define allo(x, n) (x*)malloc(n*sizeof(x))

// create a structure for adjacency node
typedef struct node
{
	int dest; 
	struct node* next;
} node;

// create a structure for adjacency list
typedef struct list
{
	node* head; // pointer to the head node of the list
} list;

// create a structure for graph vertex; a graph is an array of adjacency lists
typedef struct graph
{
	int v; // number of vertices in the graph
	struct list* arr;
} graph;

// user-defined function prototypes
node* createNode(int dest); // create a new node
graph* createGraph(int v); // create a graph of v vertices
void addEdge(graph* g, int src, int dest); // add an edge from src to dest to the undirected graph g
void printGraph(graph* g); // print adjacency list rep of the graph

int main()
{
	// At first, create a graph of 5 vertices
	graph *g = createGraph(5);
	
	// Now, add the required vertices
	addEdge(g, 0, 1);
	addEdge(g, 0, 4);
	addEdge(g, 1, 4);
	addEdge(g, 1, 2);
	addEdge(g, 1, 3);
	addEdge(g, 2, 3);
	addEdge(g, 3, 4);
	
	// Finally, print the graph
	printGraph(g);
	
	return 0;
}

// define all the user-defined functions

node* createNode(int dest)
{
	node* newNode = allo(node, 1);
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

graph* createGraph(int v)
{
	int i;
	
	graph *g = allo(graph, 1);
	g->v = v;
	// create an array of adjacency lists of size v
	g->arr = allo(list, v);
	
	// initialize each of these lists as empty making its head null
	for (i = 0; i < v; i++)
		g->arr[i].head = NULL;
	
	return g;
}

void addEdge(graph *g, int src, int dest)
{
	node* newNode;
	
	// create a link from dest to src
	newNode= createNode(dest);
	newNode->next = g->arr[src].head;
	g->arr[src].head = newNode;
	
	// create a link from src to dest (since this is undirected graph)
	newNode = createNode(src);
	newNode->next = g->arr[dest].head;
	g->arr[dest].head = newNode;
}

void printGraph(graph* g)
{
	int v;
	printf("ADJACENCY LIST OF THE GRAPH\n--------------------\n");
	for (v = 0; v < g->v; v++)
	{
		node *travel = g->arr[v].head;
		printf("%d ", v);
		while (travel)
		{
			printf("-> %d ", travel->dest);
			travel = travel->next;
		}
		printf("\n");
	}
}