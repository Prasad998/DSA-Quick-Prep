

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
