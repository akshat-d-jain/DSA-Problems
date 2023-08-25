#include <stdio.h>

void merge(int A[], int mid, int low, int high,int *comparisonCount)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
       (*comparisonCount)++;
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high,int *comparisonCount){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid,comparisonCount);
        mergeSort(A, mid+1, high,comparisonCount);
        merge(A, mid, low, high,comparisonCount);
    }
} 

int main()
{
   int A[] = {9, 1, 4, 14, 11, 15, 6};
   int n = 7;
   int comparisonCount=0;
   printf("\nThe Unsorted Array is :");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
   mergeSort(A, 0, 6, &comparisonCount);
   printf("\nThe Sorted Array is :");
   for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("\nNumber of comparisons: %d\n", comparisonCount);
   return 0;
}



