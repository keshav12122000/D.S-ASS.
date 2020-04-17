#include <stdio.h>
int b[10];
int a[100];
void mergesort(int low,int high,int mid )
{
   int x,y,i;

   for(x = low, y = mid + 1, i = low; x <= mid && y <= high; i++) {
      if(a[x] <= a[y])
         b[i] = a[x++];
      else
         b[i] = a[y++];
   }
while(y <= high)
      b[i++] = a[y++];
   while(x<= mid)
      b[i++] = a[x++];
   for(i = low; i <= high; i++)
      a[i] = b[i];
}
void sorting(int low, int high)
{
   int mid;
   if(low < high)
  {
      mid = (low + high) / 2;
      sorting(low, mid);
      sorting(mid+1, high);
      mergesort(low, mid, high);
   }
   else
    {
      return;
    }
}

int main()
 {
   int size;
   printf("Enter no of elements :");
   scanf("%d",&size);
   printf("Enter elements:\n");
   for(int i = 0; i <= size-1; i++)
      scanf("%d",&a[i]);
   sort(0, size-1);
    for(int j = 0; j <= size-1; j++)
      printf("%d ", a[j]);
}
