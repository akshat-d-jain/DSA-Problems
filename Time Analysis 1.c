#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
   int arr[10000],arr1[10000],arr2[10000],arr3[10000];
   int i,j,temp,min,key,size=10000;
   //array formation of size 10000
   for(i=0;i<size;i++){
      arr[i]=rand()/10000;
   }
   //copying the array in 3 different array
   for(i=0;i<size;i++){
      arr1[i]=arr[i];
      arr2[i]=arr[i];
      arr3[i]=arr[i];
   }
   clock_t start=clock(); 
   //applying bubble sort
   for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(arr1[j]<arr1[j+1]){
                temp=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=temp;
            }
        }
    } 
   clock_t end=clock();
    double time_taken1=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nTime taken for bubble sort : %f seconds\n", time_taken1); 
  
   
    //clock for selection sort
   clock_t start_s=clock();    // s=selection sort
   //applying selection sort
    for(i=0;i<size;i++){
      //assigning the minimum value to first index    
      min=i;
      for(j=i+1;j<size;j++){
          if(arr2[j]<arr2[min]){
              min=j;
          }
      }
      //swapping after comparison
      temp=arr2[i];
     arr2[i]=arr2[min];
     arr2[min]=temp;
    }
    clock_t end_s=clock();
    double time_taken2=((double)(end_s-start_s))/CLOCKS_PER_SEC;
    printf("\nTime taken for selection sort : %f seconds\n", time_taken2); 
    
    ///applying insertion sort on array3
    //start to count CLOCK
    clock_t start_i=clock();  //i=insertion sort
    //applying insertion sort
     for(i=1;i<size;i++){
       j=i-1;
       key=arr3[i];
       while(arr3[j]>key && j>=0){
          arr3[j+1]=arr3[j];
          j--;
       }
      arr3[j+1]=key;
    }
    clock_t end_i=clock();
    double time_taken3=((double)(end_i-start_i))/CLOCKS_PER_SEC;
    printf("\nTime taken for insertion sort : %f seconds\n", time_taken3); 
    return 0;
}


