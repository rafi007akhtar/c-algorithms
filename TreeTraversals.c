
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

struct node* newNode(int data)
{
     struct node* node = (struct node*)malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
     return(node);
}

void postorderTraversal(struct node* node)
{
     if (node == NULL)
        return;

     postorderTraversal(node->left);
     postorderTraversal(node->right);
     printf("%d ", node->data);
}

void inorderTraversal(struct node* node)
{
     if (node == NULL)
          return;

     inorderTraversal(node->left);
     printf("%d ", node->data);
     inorderTraversal(node->right);
}

void preorderTraversal(struct node* node)
{
     if (node == NULL)
          return;

     printf("%d ", node->data);
     preorderTraversal(node->left);
     preorderTraversal(node->right);
}

int main()
{
     struct node *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);

     printf("\nPreorder traversal of binary tree is \n");
     preorderTraversal(root);

     printf("\nInorder traversal of binary tree is \n");
     inorderTraversal(root);

     printf("\nPostorder traversal of binary tree is \n");
     postorderTraversal(root);

     getchar();
     return 0;
}
