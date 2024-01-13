#include <stdio.h>
#include<stdlib.h>
#include<time.h>
   void merge(int arr1[], int mid, int low, int high,int *comparisonCount)
{
    int i, j, k, B[10000];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
       (*comparisonCount)++;
        if (arr1[i] < arr1[j])
        {
            B[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            B[k] = arr1[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = arr1[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = arr1[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        arr1[i] = B[i];
    }
    
}

void mergeSort(int arr1[], int low, int high,int *comparisonCount){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(arr1, low, mid,comparisonCount);
        mergeSort(arr1, mid+1, high,comparisonCount);
        merge(arr1, mid, low, high,comparisonCount);
    }
}

// function for quick sort
int partition(int A[], int low, int high)
{
 int pivot = A[low];
 int i = low + 1;
 int j = high;
 int temp;
 do
 {
 while (A[i] <= pivot)
 {
 i++;
 }
 while (A[j] > pivot)
 {
 j--;
 }
 if (i < j)
 {
 temp = A[i];
 A[i] = A[j];
 A[j] = temp;
 }
 } while (i < j);
 
 temp = A[low];
 A[low] = A[j];
 A[j] = temp;
 return j;
}
void quickSort(int A[], int low, int high)
{
 int partitionIndex; 
 if (low < high)
 {
 partitionIndex = partition(A, low, high); 
 quickSort(A, low, partitionIndex - 1); 
 quickSort(A, partitionIndex + 1, high); 
 }
}


int main()
{
   int arr[10000],arr1[10000],arr2[10000];
   int i,j,temp,min,key;
   int size=10000;
   int comparisonCount=0;

   //array formation of size 10000
   for(i=0;i<size;i++){
      arr[i]=rand()/10000;
   }
   //copying the array in 3 different array
   for(i=0;i<size;i++){
      arr1[i]=arr[i];
      arr2[i]=arr[i];
   }
   clock_t start=clock(); 
   //applying merge sort
    mergeSort(arr1, 0, size-1, &comparisonCount);
   clock_t end=clock();
    double time_taken1=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nTime taken for merge sort : %f seconds\n", time_taken1); 
    // applying quick sort 
    clock_t start_q=clock(); 
    quickSort(arr2,0,size-1);
    clock_t end_q=clock();
    double time_taken2=((double)(end_q-start_q))/CLOCKS_PER_SEC;
    printf("\nTime taken for quick sort : %f seconds\n", time_taken2);
    return 0;
}