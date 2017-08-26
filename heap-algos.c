/* This program is my first on heap sort. More algorithms to come in due time */

#include <stdio.h>
#include <stdlib.h>

// in-line functions
#define left(i) (2*i + 1) // get the index of the left child of a node
#define right(i) (2*i + 2) // get the index of the right child of a node
#define parent(i) ((i - 1)/2) // get the index of the parent of a node

// user-defined functions
int* create_heap(int); // create a heap of specified size
void show_heap(int); // print a heap array
void max_heapify(int,int); // max-heapify the heap using recursion
void max_heapify_alter(int,int); // max-heapify the heap using loop
void min_heapify(int,int); // min-heapify the heap using recursion
void build_max_heap(int); // build the max-heap from bottom up
void heapsort(int); // apply the heapsort process to sort the array

int *h; // create a global heap variable

int main()
{
	int i, n, ch;
	
	// create a heap array
	printf("Enter the size of the heap: ");
	scanf("%d", &n);
	h = create_heap(n);
	printf("Heap created\n");
	
	// enter elements in it
	printf("\nEnter %d elements: ", n);
	for (i = 0; i < n; i++) scanf("%d", &h[i]);
	printf("Heap updated\n");
	
	// enter the menu
	while(1)
	{
		printf("\nEnter what you want\n1. See the heap \n2. Max-Heapify it \n3. Min-Heapify it \n4. Build the entire heap \n5. Apply heapsort on the array \n-1. Exit \nEnter choice: ");
		scanf("%d", &ch);
		if(ch == -1) break;
		switch(ch)
		{
			case 1: 
				printf("The heap is:\n");
				show_heap(n);
				break;
			case 2: 
				printf("Enter the position of i: "); // user assumes 1-indexed
				scanf("%d", &i);
				max_heapify(--i, n);
				printf("Heap changed\n");
				break;
			case 3:
				printf("Enter the position of i: "); // user assumes 1-indexed
				scanf("%d", &i);
				min_heapify(--i, n);
				printf("Heap changed\n");
				break;
			
			case 4:
				build_max_heap(n);
				printf("Heap built\n");
				break;
				
			case 5:
				heapsort(n);
				printf("Heap sorted\n");
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

void max_heapify_alter(int i, int n)
{
	int l, r, max, temp;
	while(1)
	{
		l = left(i);
		r = right(i);
		
		// find the greatest b/w h[i] and its children h[l], h[r]
		if (l <= n && h[l] > h[i])
			max = l;
		else max = i;
		if (r <= n && h[r] > h[max])
			max = r;
		
		// if max happens to be i itself, terminate
		if (max == i) return;
		
		// otherwise, max-heapify away!
		temp = h[i];
		h[i] = h[max];
		h[max] = temp;
		
		// check the subtree now
		i = max;
	}
}

void min_heapify(int i, int n)
{
	int l, r, min, temp;
	
	// compute the indices children - left and right - of the node at index i
	l = left(i);
	r = right(i);
	
	// find the smallest among these, and store its index in min
	if (l < n && h[l] < h [i]) min = l;
	else min = i;
	if (r < n && h[r] < h[min]) min = r;
	
	// max-heapify away!
	if (min != i)
	{
		temp = h[i];
		h[i] = h[min];
		h[min] = temp;
		max_heapify(min, n);
	}
}

void build_max_heap(int n)
{
	int i;
	int non = (n-1)/2; // the index of the last non-leaf node
	// loop over from this index up till the root, and apply the max-heapify process on each node
	for(i = non; i >= 0; i--) max_heapify(i, n);
}

void heapsort(int n)
{
	int i, temp, m;
	// First, make the array a max-heap
	build_max_heap(n);
	
	m = n - 1;
	for (i = m; i > 0; i--)
	{
		// swap a[1] with a[i], thus putting the largest element at the end of the array
		temp = h[0];
		h[0] = h[i];
		h[i] = temp;
		// max-heapify the changed array uptil one before the last child
		max_heapify(0, --n);		
	}
}
