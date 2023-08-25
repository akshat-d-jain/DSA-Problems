#include <stdio.h>

int main()
{
    int a[100],i,j,c,size,key;
    printf("Enter the size of array:");
    scanf("%d",&size);
    printf("Enter the array elements:");
    for(i=0;i<size;i++){
       scanf("%d",&a[i]);
    }
    for(i=1;i<size;i++){
       j=i-1;
       key=a[i];
       while(a[j]>key && j>=0){
          a[j+1]=a[j];
          j--;
       }
      a[j+1]=key;
    }
    for(i=0;i<size;i++){
       printf(" %d",a[i]);
    }

    return 0;
}

