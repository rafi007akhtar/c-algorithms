// This is a faulty merge-sort program
// Please do not refer to this
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int *, int, int, int);
void mergeSort(int*, int, int);

int main()
{
	int *a, n, i;
	
	printf("Enter number of elements: ");
	scanf("%d", &n);
	a = (int *)malloc(n*sizeof(int));
	
	printf("Enter elements in the array: ");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("The array is:\n");
	for(i=0; i<n; i++)
		printf("%d\t", a[i]);
		
	mergeSort(a, 0, n);
	
	printf("\nSorted array:\n");
	for(i=0; i<n; i++)
		printf("%d\t", a[i]);
		
	getch();
	return 0;
}

void merge(int *a, int p, int q, int n)
{
	int i, j, k;
	int *l, *r;
	//p = 0;
	//q = n/2 + 1;
	l = (int *)malloc((q)*sizeof(int));
	r = (int *)malloc((q)*sizeof(int));
	
	for(i=p; i<q-1; i++)
	{
		l[i] = a[i];
		r[i] = a[i+q-1];
	}
	l[q-1] = r[q-1] = INT_MAX;
	
	printf("\nLeft sub array:\n");
	for(i=0; i<q; i++)
		printf("%d\t", l[i]);
	printf("\nRight sub array:\n");
	for(i=0; i<q; i++)
		printf("%d\t", r[i]);
	
	i = j = k = 0;	
	do
	{
		if(l[i] <= r[j])
		{
			a[k] = l[i];
			i++;
		}	
		else
		{
			a[k] = r[j];
			j++;
		}
		k++;
	}while(k<=n);

}

void mergeSort(int *a, int p, int n)
{
	int q;
	if (p<n-1)
	{
		q = (p+n)/2;
		//printf("No problems till here");
		mergeSort(a,p,q);
		mergeSort(a, q+1, n-1);
		merge(a,p,q,n);
	}
}
