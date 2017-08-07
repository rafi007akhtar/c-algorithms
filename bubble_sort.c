/*
	Input: An unsorted array "a"
	Output: The sorted array "a" in place using Bubble Sort
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a;
	int i, j, temp, n;
	
	printf("Enter number of elements: ");
	scanf("%d", &n);
	a = (int *)malloc(n*sizeof(int));
	
	printf("Enter %d numbers: ", n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	
	for (i = n-1; i >= 1; i--)
	{
		for (j = 0; j <= i; j++)
		{
			if (a[j] > a[j+1])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
	printf("The sorted array is:\n");
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}