#include<stdio.h>
#include<stdlib.h>
 typedef struct node
 {
    int data;
    struct node *left;
     struct node *right;
}Node;

int * create()

{
 int x;

Node *newnode=(Node*)malloc(sizeof(Node));

 printf("Enter the data for the nodes(-1 for no data)");
 scanf("%d", &x);
if(x==-1)
 {
     return NULL;
}
      newnode->data=x;

      printf("Enter the left child data rooted at %d \n",newnode->data);

      newnode->left=create();

      printf("Enter the right child data rooted at %d\n",newnode->data);

      newnode->right=create();

      return newnode;
}
void traverse(Node *t)
{
    if(!t==NULL)
    {
     printf("Left child data is %d ",t->data);
       traverse(t->left);
       t=t->right;
      }
   if(!t==NULL)
      {
       printf("Right child data is %d\n",t->data);
       traverse(t->right);
      }
}
void Inorder(Node *t)
{
    if(t)
    {
    Inorder(t->left);

    printf(" %d",t->data);

    Inorder(t->right);
    }
}
void preorder(struct node* x)
{
     if (x == NULL)
 {
    return;
 }
     printf(" %d ", x->data);
     preorder(x->left);
     preorder(x->right);
}
void postorder(struct node* x)
{
     if (x == NULL)
 {
   return;
 }
     postorder(x->left);
     postorder(x->right);
     printf(" %d ", x->data);
}
int main()

{
Node *root=create();
Node *t=root;
printf("Root child is %d\n ",t->data);
traverse(t);
Inorder(t);
printf(" is the in-order traversal \n\n" );
preorder(t);
printf(" is the pre-order traversal \n\n" );
postorder(t);
printf(" is the post-order traversal \n\n" );
    return 0;
}

