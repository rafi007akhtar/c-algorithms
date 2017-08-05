/* This program is my first on heap sort. More algorithms to come in due time */

#include <stdio.h>
#include <stdlib.h>

// user-defined functions
int* create_heap(int); // create a heap of specified size
int left(int); // get the index of the left child of a node
int right(int); // get the index of the right child of a node
int parent(int); // get the index of the parent of a node
void show_heap(int); // print a heap array
void max_heapify(int,int); // max-heapify the heap

int *h; // create a global heap variable

int main()
{
	int i, n, ch;
	
	// create a heap array
	printf("Enter the size of the heap: ");
	scanf("%d", &n);
	h = create_heap(n);
	printf("Heap created");
	
	// enter elements in it
	printf("\nEnter %d elements: ", n);
	for (i = 0; i < n; i++) scanf("%d", &h[i]);
	printf("Heap updated\n");
	
	// enter the menu
	while(1)
	{
		printf("\nEnter what you want\n1. See the heap \n2. Max-Heapify it \n-1. Exit \nEnter choice: ");
		scanf("%d", &ch);
		if(ch == -1) break;
		switch(ch)
		{
			case 1: 
				printf("The heap is:\n");
				show_heap(n);
				break;
			case 2: 
				printf("Enter the position of i: ");
				scanf("%d", &i);
				max_heapify(i, n);
				printf("Heap changed\n");
				break;
			default:
				printf("Wrong choice. Try again\n");
				break;
		}
	}
	
	return 0;
}

int* create_heap(int n) 
{
	return (int *)malloc(n * sizeof(int));
}

int left(int i) {return 2*i + 1;}
int right(int i) {return 2*i + 2;}
int parent(int i) 
{
	float par = i/2;
	if (par == (int)par) return (int)par;
	return (int)par + 1;
}

void show_heap(int n)
{
	int i;
	for (i = 0; i < n; i++) printf("%d\n", h[i]);
}

void max_heapify(int i, int n)
{
	int l, r, max, temp;
	
	// compute the indices children - left and right - of the node at index i
	l = left(i);
	r = right(i);
	
	// find the largest among these, and store its index in max
	if (l < n && h[l] > h [i]) max = l;
	else max = i;
	if (r < n && h[r] > h[max]) max = r;
	
	// max-heapify away!
	if (max != i)
	{
		temp = h[i];
		h[i] = h[max];
		h[max] = temp;
		max_heapify(max, n);
	}
}