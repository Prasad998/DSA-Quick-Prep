This file contains the snippets I can use for the corresponding coding patterns.



#include<bits/stdc++.h>
using namespace std;


Prefix SUM
class NumArray {
public:
    NumArray(vector<int>& nums) {
        vec = nums ;
        for(int i =1 ;i< nums.size();i++)
        {
            vec[i]  = vec[i-1]+ nums[i] ; 
        }
    }
    int sumRange(int left, int right) {
        if(left == 0) return vec[right] ;
        return vec[right] -  vec[left-1] ; 
    }
private: 
    vector<int> vec ; 
};
