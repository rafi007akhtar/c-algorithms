/*
	Input: An unsorted array "a"
	Output: The sorted array "a" in place using Insertion Sort
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a;
	int i, j, temp, n, key;
	
	printf("Enter number of elements: ");
	scanf("%d", &n);
	a = (int *)malloc(n*sizeof(int));
	
	printf("Enter %d numbers: ", n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > key)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
	
	printf("The sorted array is:\n");
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}