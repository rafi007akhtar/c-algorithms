/*
 * C program to input N numbers and store them in an array.
 * Do a linear search for a given key and report success
 * or failure.
 */
 
 /*
 Example test cases
 1. Enter the number of elements 6
   Enter the elements one by one
   4
   6
   1
   2
   5
   3
   Enter the element to be searched 6
   Element is present in the array at position 2
 
2. Enter the number of elements 3
   Enter the elements one by one
   66
   -3
   31
   Enter the element to be searched 66
   Element is present in the array at position 1
 
3. Enter the number of elements 5
   Enter the elements one by one
   1
   3
   6
   1
   9
   Enter the element to be searched 9
   Element is present in the array at position 5
 */
#include <stdio.h>
 
void main()
{  int num;
 
    int i,  keynum, found = 0;
 
    printf("Enter the number of elements ");
    scanf("%d", &num);
    int array[num];
    printf("Enter the elements one by one \n");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
    }
 
    printf("Enter the element to be searched ");
    scanf("%d", &keynum);
    /*  Linear search begins */
    for (i = 0; i < num ; i++)
    {
        if (keynum == array[i] )
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
        printf("Element is present in the array at position %d",i+1);
    else
        printf("Element is not present in the array\n");
}
