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
    // printf("Left child data is %d ",t->data);
       traverse(t->left);
       t=t->right;
      }
   if(!t==NULL)
      {
      // printf("Right child data is %d\n",t->data);
       traverse(t->right);
      }
}

int countNonleaf(struct node* root)
{
    // Base cases.
    if (root == NULL || (root->left == NULL &&
                         root->right == NULL))
        return 0;

    // If root is Not NULL and its one of its
    // child is also not NULL
    return 1 + countNonleaf(root->left) +
               countNonleaf(root->right);
}



/* Function to get the count of leaf nodes in a binary tree*/

int getLeafCount(struct node* node)
{
  if(node == NULL)
    return 0;
  if(node->left == NULL && node->right==NULL)
    return 1;
  else
    return getLeafCount(node->left)+
           getLeafCount(node->right);
}
int main()

{
Node *root=create();
Node *t=root;
printf("Root child is %d\n ",t->data);
traverse(t);

  /*get leaf count of the above created tree*/
  printf("Leaf count of the tree is %d\n", getLeafCount(root));
     printf("NON Leaf count of the tree is %d",countNonleaf(root));
    return 0;
}

