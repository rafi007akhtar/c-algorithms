/*
PROGRAM
Double Linked List using single Pointer.
So basically one pointer is used to traverse
back and forth in the linked list. This saves space
as we don't need two pointers that is being used normally

INPUT
Enter the numbers. Enter -999 to terminate.
10
5
76
45
87
22
-999

OUTPUT
Cureent no. is 10
Previous nos. are  NULL
Next nos. are 5 76 45 87 22 

Cureent no. is 5
Previous nos. are 10 
Next nos. are 76 45 87 22 

Cureent no. is 76
Previous nos. are 5 10 
Next nos. are 45 87 22 

Cureent no. is 45
Previous nos. are 76 5 10 
Next nos. are 87 22 

Cureent no. is 87
Previous nos. are 45 76 5 10 
Next nos. are 22 

Cureent no. is 22
Previous nos. are 87 45 76 5 10
Next nos. are  NULL
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

void main()
{
    int x;
    NODE *head, *t, *p = NULL, *px, *tx;
    head = (NODE *)malloc(sizeof(NODE));
    t = head;
    printf("Enter the numbers. Enter -999 to terminate.\n");
    scanf("%d", &x);
    while (x != -999)
    {
        t->data = x;
        t->next = (NODE *)malloc(sizeof(NODE));
        t = t->next;
        scanf("%d", &x);
    }
    t->next = NULL;

    t = head;
    p = NULL;

    while (t->next != NULL)
    {
        px = p;
        tx = t;
        printf("\n\nCureent no. is %d", t->data);

        printf("\nPrevious nos. are ");

        if (p == NULL)
        {
            printf(" NULL");
        }
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        p = px;

        printf("\nNext nos. are ");

        while (t->next->next != NULL)
        {
            printf("%d ", t->next->data);
            t = t->next;
        }
        t = tx;

        px = p;
        p = t;
        t = t->next;
        p->next = px;
    }
    if (t->next == NULL)
    {
        printf(" NULL");
    }
}