#include <stdio.h>
#include <stdlib.h>

// create bool datatype
enum bool {false, true}; 
typedef enum bool bool;

// inline functions
#define write(a, n)  // print out an array 'a' of length n; 'i' needs to be initialized in the function

// user-defined functions
bool place(int k, int i); // returns true (1) if a queen can be placed on kth row and ith column; false (0) otherwise
void nqueens(int k, int n); // print the backtracking soln to this NQueens problem

int *x; // solution to the backtracking problem (NQueens)

int main()
{
	int n, loop;
	printf("Enter the value of N: ");
	scanf("%d", &n);
	
	x = (int *)malloc(n * sizeof(int));
	printf("The solution is:\n");
	nqueens(0, n);
	
	return 0;
}

bool place(int k, int i)
{
	int j;
	for (j = 0;  j < k; j++)
	{
		// column check
		if (x[j] == i) return false;
		
		// diagonal check: difference in ordinates should not equal difference in abscissae
		if (abs(x[j]-i) == abs(j-k)) return false;
	}
	return true;
}

void nqueens(int k, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		if (place(k, i)) // if kth row can be placed on ith column
		{
			//printf("True for (%d, %d)\n", k, i);
			x[k] = i;
			if (k == n-1)
			{
				for (j = 0; j < n; j++) 
					printf("%d ", x[j]);
				exit(0);
				printf("\n");
			}
			else nqueens(k+1, n);
		}
	}
}