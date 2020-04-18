
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define CAPACITY 100    

typedef struct node
{
    int data;
    struct node * next;
} Queue; 

unsigned int size = 0;

int enqueue(Queue ** rear, Queue ** front, int data);
int dequeue(Queue ** front);
int getRear(Queue * rear);
int getFront(Queue * front);
int isEmpty();
int isFull();


int main()
{
    int ch, data;
    Queue *rear, *front;

    rear  = NULL;
    front = NULL;
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Size\n");
        printf("0. Exit\n");
        printf("*******************************************\n");
        printf("Select an option: ");

        scanf("%d", &ch);
        switch (ch)
{
    case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);

                
                if (enqueue(&rear, &front, data))
                    printf("Element added to queue.");
                else
                    printf("Queue is full.");

                break;

case 2:
                data = dequeue(&front);
                if (data == INT_MIN)
                    printf("Queue is empty.");
                else
                    printf("Data => %d", data);

                break;

case 3:

                // isEmpty() function returns 1 if queue is emtpy
                // otherwise returns 0
                if (isEmpty())
                    printf("Queue is empty.");
                else
                    printf("Queue size => %d", size);

                break;

case 4:
             

                data = getFront(front);

                if (data == INT_MIN)
                    printf("Queue is empty.");
                else
                    printf("Front => %d", data);

                break;
 case 5:
                data = getRear(rear);

                if (data == INT_MIN)
                    printf("Queue is empty.");
                else
                    printf("Rear => %d", data);

                break;

          

        }
        printf("\n\n");
    }
}
int enqueue(Queue ** rear, Queue ** front, int data)
{
    Queue * newNode = NULL;
    // Check queue out of capacity error
    if (isFull())
    {
        return 0;
    }
    newNode = (Queue *) malloc (sizeof(Queue));
    newNode->data = data;
    newNode->next = NULL;

    // Link new node with existing last node
    if ( (*rear) )
    {
        (*rear)->next = newNode;
    }
    *rear = newNode;
    if ( !( *front) )
    {
        *front = *rear;
    }
    size++;

    return 1;
}
int dequeue(Queue ** front)
{
    Queue *Deq = NULL;
    int data = INT_MIN;

    // Queue empty error
    if (isEmpty())
    {
        return INT_MIN;
    }

    Deq = *front;
    data = Deq->data;

    // Move front ahead
    *front = (*front)->next;

    // Decrement size
    size--;

    free(Deq);

    return data;
}

int isEmpty()
{
    return (size <= 0);
}
int isFull()
{
    return (size > CAPACITY);
}

int getFront(Queue * front)
{
    return (isEmpty())
            ? INT_MIN
            : front->data;
}
int getRear(Queue * rear)
{
    return (isEmpty())
            ? INT_MIN
            : rear->data;
}
