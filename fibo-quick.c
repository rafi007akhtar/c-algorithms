/* Compute F(n) using Recursive-Square algorithm, where F(n) is the nth Fibonacci number defined as
* F(0) = 0
* F(1) = 1
* F(n) = F(n-1) + F(n-2)
*/

#include <stdio.h>

// User-defined functions
int fibo(int);
int mat[2][2] = {{1, 1}, {0, 1}};

int main()
{
	int n, f;
	printf("Enter n: ");
	scanf("%d", &n);
	
	f = fibo(n);
	printf("%dth Fibonacci number = %d", n, f);
	
	return 0;
}

int fibo(int n)
{
	int i, j, k, sum = 0;
	int pow[2][2];

	while (n > 0)
	{
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 2; j++)
			{
				// c[i, j] = sum(a[i,k] * b[k,j]) from k = 0 to n - 1
				for (k = 0; k < 2; k++) sum += mat[i][k] + mat[k][j];
				mat[i][j] = sum;
				sum = 0;
			}
		}
		n--;
	}
	
	return mat[0][1];
}

