class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int prev = 0;
        int curr;
        for(curr = 1; curr < nums.size(); ++curr){
            if(nums[prev] != nums[curr])
                nums[++prev] = nums[curr];
        }
        
        return prev+1; 
    }
};