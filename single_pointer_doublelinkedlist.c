//Double Linked List using single Pointer
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