Insertion, Bubble, Selection Sort

#include<bits/stdc++.h>

using namespace std;
void selection_sort(int arr[], int n) {
  // selection sort
  for(int i = 0 ; i <n-1 ; i++)
  {
      int mini = i ; 
      for(int  j=1 ;j<n ;j++)
      {
          if(arr[j]<arr[mini]) mini = j ; 
      }
      swap(arr[mini], arr[i]);
  }

===========================================================================
void insertion_sort(int arr[], int n)
{
    for(int i = 0 ; i<n;i++)
    {
        int j = i ; 
        while(j>0  and arr[j-1]>arr[j])
        {
            swap(arr[j], arr[j-1]) ;
            j-- ; 
        }
    }


===========================================================================
void bubble_sort(int arr[], int n) {
    // bubble sort
    for (int i = 0 ; i<n-1;i++) {
        int didSwap = 0;
        for (int j = 0; j <n-i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;
        }
    }


  =  =  =  =  =  =  =  =  =  =  =  =  =  = BOILER PLATE CODE  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =

  cout << "After bubble_sort: " << "\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";

}
int main() {
  int arr[] = {13,46,24,52,20,9};
  int n = sizeof(arr) / sizeof(arr[0]);
   cout << "Before bubble_sort : " << "\n";
   for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  bubble_sort(arr, n);
  return 0;
}


===========================================================================

QUICK SORT 

#include <bits/stdc++.h> 

int partition(vector<int>&arr, int low, int high)
{
    int pivot =  arr[low] ; 
    int i = low ; 
    int j = high ; 
    while(i<j)
    {
        while(arr[i]<=pivot && i<=high-1)
        {
            i++ ; 
        }
        while(arr[j]>pivot && j>=low+1)
        {
            j-- ; 
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
   }

   swap(arr[j], arr[low]);
   return j ;
}

void qsort(vector<int>&arr ,int low, int high)
{
    if(low<high)
    {
    int pivot =  partition(arr, low,high) ; 
    qsort(arr,low ,pivot-1) ; 
    qsort(arr, pivot+1 , high) ;
    }
}
vector<int> quickSort(vector<int> arr)
{
    // Write your code here.

    qsort(arr, 0, arr.size()-1) ; 

    return arr  ;
}

