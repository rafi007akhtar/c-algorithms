/*
	Input: An unsorted array "a"
	Output: The sorted array "a" in place using Quick Sort
*/

#include <stdio.h>
#include <stdlib.h>

int *a; // global array variable
int partition(int, int);
void quicksort(int, int);

int main()
{
	int i, j, temp, n, p, q, r;
	
	printf("Enter number of elements: ");
	scanf("%d", &n);
	a = (int *)malloc(n*sizeof(int));
	p = 0;
	r = n-1;
	
	printf("Enter %d numbers: ", n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	
	quicksort(p, r);
	
	printf("The sorted array is:\n");
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}

int partition(int start, int pivot)
{
	int x, i, j, temp;
	x = a[pivot]; // pivot element
	i = start - 1;
	for (j = start; j < pivot; j++)
	{
		if (a[j] <= x)
		{
			i++;
			// swap a[j] and a[i]
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i+1];
	a[i+1] = a[pivot];
	a[pivot] = temp;
	
	return i+1;
}

void quicksort(int p, int r)
{
	int pivot, q;
	if (p < r)
	{
		pivot = r; // choose end point as the pivot
		// partition the array from a[p..q] and a[q+1..r]; compute q
		q = partition(p, pivot);
		// perform quick sort on a[p..q-1], and then on a[q+1..r]
		quicksort(p, q-1);
		quicksort(q+1, r);
	}
}