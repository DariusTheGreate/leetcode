class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::map<int, int> mapper;
        for(size_t i = 0; i < nums.size(); ++i){
                mapper[nums[i]]++;
        }
        
        for (const auto& [key, value] : mapper) {
            if(value == 1)
                return key;
        }   
        
        return 0;
    }
};