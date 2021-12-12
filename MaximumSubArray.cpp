#include <cmath>
#include <iostream>

class Solution {
public:
    int maxSubArray(vector<int>& prices) {
        int best = prices[0];
        int curr = prices[0];
        int bestLeft = -1;
        int bestRight = -1;
        int tempLeft = -1;
        int tempRight = -1;
        
            
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i] + curr)
            {
                curr = prices[i];
                tempLeft = i;
            }
            
            else if(prices[i] <= prices[i] + curr)
            {
                curr += prices[i];  
                tempRight = i;
            }
            
            if(curr > best)
            {
                best = curr;
                bestRight = i;
                bestLeft = tempLeft;
            }
                
        
        }
        std::cout << bestLeft << " " << bestRight;
        return best;
        
    }
    
    
};