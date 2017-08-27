#include <stdio.h>
#include <stdlib.h>

/* Inline functions */
#define allo (int *)malloc(n * sizeof(int))

/* User-defined functions */
int lin_search(int*,int,int);

int main()
{
	int *a, n, i, key;
	
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	a = allo;
	printf("Enter %d elements now: ", n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	
	printf("The unsorted array is: ");
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	
	printf("Enter the key: ");
	scanf("%d", &key);
	
	int res = lin_search(a, n, key);
	if (res == -1) printf("Element not found\n");
	else printf("Element found at position %d\n", res);
	
	return 0;
}

int lin_search(int *a, int n, int key)
{
	int i;
	for (i = 0; i < key; i++)
	{
		if (a[i] == key) return i + 1;
	}
	return -1;
}
