#include <iostream>

class NumArray {
public:
    vector<int> sums; // on place i store sum from 0 to i
    
    NumArray(vector<int>& nums) 
    {
        sums.resize(nums.size()+1);
        sums[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            sums[i] = sums[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) 
    {
        if(left == 0)
            return sums[right];
        return sums[right] - sums[left-1];     
    }
};