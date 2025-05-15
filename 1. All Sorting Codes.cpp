Insertion, Bubble, Selection Sort

#include<bits/stdc++.h>

using namespace std;
void selection_sort(int arr[], int n) {
  // selection sort
  for(int i = 0 ; i <n-1 ; i++)
  {
      int mini = i ; 
      for(int  j=i+1 ;j<n ;j++)
      {
          if(arr[j]<arr[mini]) mini = j ; 
      }
      swap(arr[mini], arr[i]);
  }
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
}

===========================================================================
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int didSwap = 0;
        for (int j = 0; j < n - i - 1; j++) {  // corrected bound
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;  // optimization: stop if already sorted
        }
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


===========================================================================

MERGE SORT 


void merge(vector<int>&arr, int low, int mid, int high)
{
    vector<int> temp ;
    int left =  low ; 
    int right =  mid+ 1 ;
    while(left <=mid && right <=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++ ; 
        }
        else{
            temp.push_back(arr[right]);
            right++ ; 
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left] );
        left++ ; 
    }
    while(right<=high)
    {
        temp.push_back(arr[right]) ; 
        right++ ; 
    }

    for(int i =low; i <=high ; i++)
    {
        arr[i] =  temp[i- low] ; 
    }
}

void msort(vector<int>&arr, int low, int high)
{
    if(low == high) return ;
    int mid = (low+ high)/2  ;
    msort(arr, low,mid)  ;
    msort(arr, mid+1, high)  ; 
    merge(arr,low,mid,high) ;
}
void mergeSort(vector < int > & arr, int n) {
    // Write your code here.

    msort(arr,0,n-1) ; 
}

===========================================================================

BINARY SEARCH

class Solution {

public:
    int search(vector<int>& nums, int target) {
        int start = 0 ;
        int end  = nums.size() -1 ; 
         while(start<=end)
        {
            int mid =  start + (end-start)/2 ; 
            
            if(target ==nums[mid])
            {
                return mid ; 
            }
            else if(target >= nums[mid])
            {
                start = mid+ 1 ; 
            }
            else{
                end = mid-1  ;  
            }
        }
        return -1 ; 
    }
};

===========================================================================

KADANEs ALGORITHM

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }
        
        if (sum < 0) {   // If sum < 0: discard the sum calculated
            sum = 0;
        }
    }
    // To consider the sum of the empty subarray, uncomment the following check:
    //if (maxi < 0) maxi = 0;
    return maxi;
}

===========================================================================

//Logic -- 
// This creates a boolean array prime of size n+1, initialized to true..
//   Here we Assume that all numbers are prime 
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

// here we traverse from 2 to √N  -- to find if the primes marked true are actually true.
      for (int p = 2; p * p <= n; p++) {
        
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

Prime Number in O(logn) time.
  
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)      // i= p*p ->mhnje I ek perfect square pahije konacha tari      //important loop ahe.
                prime[i] = false;
        }
    }
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}



TopoSort Algorithm
DFS + Stack → Reverse Stack = Topo Sort         means...
Visit → Recurse → Push → Print Stack

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int nbr : adj[node]) {
        if (!visited[nbr])
            dfs(nbr, adj, visited, st);
    }
    st.push(node);
}

void topoSort(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i, adj, visited, st);
    }

    // Print topological order
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}




// CODE  Skeleton
// void dfs(int node) {
//     visited[node] = true;
//     for (nbr : adj[node])
//         if (!visited[nbr])
//             dfs(nbr);
//     st.push(node);  // after visiting neighbors
// }

// for (all nodes)
//     if not visited → dfs(node)

// print stack (reversed order)


