#include <stdio.h>

// Tabulated version to find factorial x.
int fact_tab(int n)
{
    int i, fact[n];
    fact[0] = 1;
    for (i = 1; i < n; i++)
        fact[i] = fact[i-1] * (i+1);
    return fact[n-1];
}

// Memoized version to find factorial x.
// To speed up we store the values
// of calculated states

// initialized to -1
int dp[10];

// return fact x!
int fact_mem(int x)
{
    if (x==0)
        return 1;
    return (dp[x] = x * fact_mem(x-1));

int main(int argc, char *argv[])
{
    dp[0] = -1;
    printf("5! = %d in tabulated method\n", fact_tab(5)); // bottom-up
    printf("5! = %d in memoized method\n", fact_mem(5)); // top-down
    return 0;
}
