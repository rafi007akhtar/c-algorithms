// Greedy technique to solve the knapsack problem
// Assumption: This program assumes the weights and profits are input in the order of p[i]/w[i]

#include <stdio.h>
#include <stdlib.h>

float *x, *w, *p; // solution array(x[]), weights (w[]), profits(p[])
int n, m; // number of elements in the arrays (n), knapsack size (m)

// inline functions
#define allo (float *)calloc(n,sizeof(float))

// user defined functions
void greedyKnapsack();

int main()
{
	int i;
	
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	
	x = allo;
	w = allo; 
	p = allo;
	
	printf("Enter the weights: ");
	for (i = 0; i < n; i++) scanf("%f", &w[i]);
	
	printf("Enter the profits: ");
	for (i = 0; i < n; i++) scanf("%f", &p[i]);
	
	printf("Enter knapsack capacity: ");
	scanf("%d", &m);
	
	// assuming p[i]/w[i] > p[i+1]/w[i+1] for all i = 0 to n-1:
	greedyKnapsack();
	
	printf("\nThe solution array is:\n");
	for (i = 0; i < n; i++) printf("%.3f ", x[i]);
	
	printf("\nProfit yielded: ");
	float s = 0;
	for (i = 0; i < n; i++) s += p[i]*x[i];
	printf("%.3f\n", s);
	
	return 0;
}

void greedyKnapsack()
{
	int i, temp = m;
	
	for (i = 0; i < n; i++)
	{
		if (w[i] > temp) break;
		x[i] = 1;
		temp -= w[i];
	}
	if (i < n-1) x[i] = (temp*1.0) / (w[i]*1.0);
}