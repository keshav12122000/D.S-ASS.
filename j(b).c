#include<stdio.h>
void selectionsort(int a[],int size)
{
    int temp,i,j,p;
    for(i=0;i<size-1;i++)
    {
        p=i;
        for(j=i+1;j<size-1;j++)
        {
            if(a[p]>a[j])
            {
                p=j;
            }
            if(p!=i)
            {
                temp=a[p];
                a[p]=a[i];
                a[i]=temp;
            }
        }
    }
}
int main()
{
    int i,j,size;
    scanf("%d",&size);
    int a[size];
    printf("enter numbers");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    selectionsort(a,size);
    printf("ascending order of given numbers is:");
    for(i=0;i<size;i++)
        printf("%d\n",a[i]);
    return 0;
}
