
// Sliding Window ka jo pattern hai usko acchese samajh lo pehle

// sabse pehle 2 variables 
int i=0,j=0 ; // pe set karo. aur ek  result variable jo bhi lagega..
int res = 0 ;
while(j< s.size())  //--> we need a loop till when to slide the window.
// some operation to do example..
sum += Arr[j]; 
//  K size ke window tak j++ ;
if(j - i + 1 < K) j++ ; 
.
.
// When window size  == K hoga tab check karna shuru karo
else if(j - i + 1 == K)
{
   //Some condition to fullfill ;

   // Abb bani hui window ko slide karte jaao  -> beware this is inside the (j-i+1== k) Loop !!!
   i++;
   j++;
}
return res ; // return the result variable.


// Maximum sum of Subarray of Size K
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
                maxi = max(maxi, sum);    // maximimum check karte jao, 
                sum -= Arr[i];            // Purana udate jao,
                i++; j++;                 // window slide karte jao ...
            }
        }
        return maxi;
    }
};


// LeetCode 438. Find All Anagrams in a String

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {  // s-  lambi string , p - pattern
        vector<int> res ; 
        unordered_map<char, int > mp ; 
        for( auto it  : p)
        {
            mp[it]++ ; 
        }           // Map banake usko populate karo - we need to calculate the occurance of alphabets in the pattern.

        int count = mp.size();
        int k = p.size() ;
        int i = 0 , j=0 ;

        while(j<s.size())  // Match karke map se udate raho.... RIGHT SIDE SE
        {
            if(mp.find(s[j])!= mp.end())
            {
                mp[s[j]]-- ; 
                if(mp[s[j]]==0) count-- ;
            }                        

            if(j-i+1 <k) j++ ;  // K size ki window hone tak badhte raho  ---> s[j]
 
            else if(j-i+1 ==k)     // K size ki window hone hone wale calculation..
            {
                if(count ==0)  res.push_back(i) ;  // answer wali condition..

                if(mp.find(s[i])!= mp.end())
                {
                    mp[s[i]]++ ;
                    if(mp[s[i]]== 1) count++  ;
                }                            // Naye wale char jodte jao ... LEFT SIDE SE ---> s[i)

                i++;
                j++ ;       // Window slide karte raho
            }
        }
        return res; 
    }
};
 

// Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> res;
        int i = 0;
        int j = 0;
        priority_queue<pair<int, int>> heap;

        while (j < arr.size()) 
        {
            heap.push({arr[j], j}); //do this calculation-- yaha tak sahi tha mai 

            if (j - i + 1 < k)  j++ ; // ye bhi sahi tha.
            
            
            else if (j - i + 1 == k) 
            {
               // Remove elements that are outside the current window
               // The condition to remove out-of-window elements (heap.top().second < i).
                while (!heap.empty() && heap.top().second < i) // ya condition madhe ghol kela
                {
                    heap.pop();
                }

                res.push_back(heap.top().first);  // finding the answer
                i++; // sliding the window ahead
                j++;
            }
        }
        return res;
    }
};
