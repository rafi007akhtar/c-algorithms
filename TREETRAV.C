/*
input the data
output will be the data arranged according to the traversals
*/

#include<stdio.h>
#include<conio.h>
struct node
{ struct node* left; int data; struct node* right; };

struct node* create(int data)
{
struct node* newNode=(struct node*)malloc(sizeof(struct node));
newNode->data = data;
newNode->left='\0';
newNode->right = '\0';
return newNode;
}

struct node* insert(struct node* t, int data)
{
if(t=='\0') return create(data);
if(data < t->data)
	t->left = insert(t->left, data);
else if(data > t->data)
	t->right = insert(t->right, data);
return t;
}

void inorder(struct node* t)
{
if(t=='\0') return;
inorder(t->left);
printf("%d ",t->data);
inorder(t->right);
}

void preorder(struct node* t)
{
if(t=='\0') return;
printf("%d ",t->data);
preorder(t->left);
preorder(t->right);
}

void postorder(struct node* t)
{
if(t=='\0') return;
postorder(t->left);
postorder(t->right);
printf("%d ",t->data);
}

void main()
{
struct node *root='\0';
int n,i,val;
clrscr();
printf("Enter the number of elements :: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	scanf("%d",&val);
	if(i==0)
		root = insert(root,val);
	else
		insert(root,val);
}
printf("Inorder\n");
inorder(root);
printf("\nPreorder\n");
preorder(root);
printf("\nPostorder\n");
postorder(root);
getch();
}