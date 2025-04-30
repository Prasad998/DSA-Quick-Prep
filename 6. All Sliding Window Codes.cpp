
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long int sum=0;
        int i=0;
        int j=0;
        long int maxi=INT_MIN;
        
        while(j<N)
        {
            // Sum karna hai apneko
            sum=sum+Arr[j];
            // K size tak window banne do...
            if(j-i+1<K)
            {
                j++;
            }
            else if(j-i+1==K)            // K size ka window banne ke baad slide marte raho
            {
                maxi = max(maxi, sum);
                sum=sum-Arr[i];  // pehle ka udaao
                 
                i++; j++; // Window slide karo 
            }
        }
        return maxi;
    }
};
// CAN BE BETTER CODED AS ----------------------

class Solution{   
public:
   long maximumSumSubarray(vector<int> &Arr,int K){
        int N = Arr.size() ; 
        long sum = 0, maxi = INT_MIN;
        int i = 0, j = 0;
        while(j < N){
            sum += Arr[j];
            if(j - i + 1 < K) j++ ; 
            
            else if(j - i + 1 == K){
                if(sum > maxi) maxi = sum;
                sum -= Arr[i];
                i++; 
                j++;
            }
        }
        return maxi;
    }
};
