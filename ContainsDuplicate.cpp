class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::map<int, int> mapper;
        for(size_t i = 0; i < nums.size(); ++i){
            std::cout << nums[i] << " ";
            if(!mapper[nums[i]]){
                std::cout << "not exsist   ";
                mapper[nums[i]]++;
            }
            else{
                return true;
            }
        }
        
        return false;
    }
};