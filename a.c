#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;          // Data
    struct node *next; // Address
} * head;//globally


void create(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("Unable to allocate memory. Exiting from app.");
    }
    /* Input head node data from user */
    printf("Enter data of first node: ");
    scanf("%d", &data);

    head->data = data; // Link data field with data
    head->next = NULL; // Link address field to NULL

    temp = head;

    // Create n nodes and add to the list
    for (i = 2; i <= n; i++)
    {
        newNode = malloc(sizeof(struct node));

        /* If memory is not allocated for newNode */
        if (newNode == NULL)
        {
            printf("Unable to allocate memory. Exiting from app.");
            exit(0);
        }

        printf("Enter data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // The newNode should point to nothing

        temp->next = newNode; // Link previous node i.e. temp to the newNode
        temp = temp->next;
    }

}
void print()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);

        temp = temp->next;  // Move to next node
    }

    printf("\n");
}

void deletion(int key)
{
    struct node *prev, *cur;

    /* Check if head node contains key */
    while (head != NULL && head->data == key)
    {
        // Get reference of head node
        prev = head;

        // Adjust head node link
        head = head->next;

        // Delete prev since it contains reference to head node
        free(prev);

        // No need to delete further
        return;
    }

    prev = NULL;
    cur  = head;

    while (cur != NULL)
    {
        if (cur->data == key)
        {
            if (prev != NULL)
                prev->next = cur->next;

            free(cur);//free the current node
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}
int main()
{
    int n, key;
    printf("Enter number of nodes u want to create: ");
    scanf("%d", &n);
    create(n);

    printf("\nData in list before deletion\n");
    print();

    printf("\nEnter element to delete: ");
    scanf("%d", &key);
    deletion(key);

    printf("\nData in list after deletion\n");
    print();

    return 0;
}

