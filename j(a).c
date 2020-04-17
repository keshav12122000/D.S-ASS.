#include<stdio.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = divide(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int divide(int arr[],int high,int low)
{
    int x = arr[high];
    int i = low - 1;

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] < x)
        {
            i++; //increment
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

int main()
{
    int arr[1000];
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("enter no of elements");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    quickSort(arr, 0, n-1);
    printf("array after sorting n");
    printArray(arr, n);
    return 0;
}
