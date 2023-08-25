#include <stdio.h>

int main()
{
    int a[100],size,i,j,temp;
    printf("Enter the size of array:");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {  printf("Enter the element %d:",i);
       scanf("%d",&a[i]);
    }
   for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (a[j] > a[j+ 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("The array elements are :");
    for(i=0;i<size;i++)
    {
       printf(" %d",a[i]);
    }
    return 0;
}


