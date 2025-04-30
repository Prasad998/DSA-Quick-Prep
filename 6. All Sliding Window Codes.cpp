

class Solution{   
public:
   long maximumSumSubarray(vector<int> &Arr,int K){
        int N = Arr.size() ; 
        long sum = 0, maxi = INT_MIN;
        int i = 0, j = 0;


        while(j < N){
            sum += Arr[j];
            if(j - i + 1 < K) j++ ;       // K size ka window banne do, tab tak add krte raho.
            
            else if(j - i + 1 == K){      // K size hone pe check karo
                maxi = max(maxi, sum);    // maximimum lete jao, 
                sum -= Arr[i];
                i++; j++;                 // window slide karte jao ...
            }
        }
        return maxi;
    }
};
