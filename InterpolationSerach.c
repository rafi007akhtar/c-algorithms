#include<stdio.h>
#include<conio.h>

int interpolationSearch(int arr[], int n, int x) {

    int lo = 0, hi = (n - 1);

    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        if (lo == hi) {
            if (arr[lo] == x) return lo;
            return -1;
        }

        int pos = lo + (((double)(hi-lo) / (arr[hi]-arr[lo]))*(x - arr[lo]));

        if (arr[pos] == x)
            return pos;
        else if (arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}


int main()
{
    int arr[] =  {5, 8, 11, 16, 20, 25, 29, 30, 40, 42, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 20;
    int index = interpolationSearch(arr, n, x);
    if (index != -1)
        printf("Element is found at index %d", index);
    else
        printf("Element is not found.");
    return 0;
}
