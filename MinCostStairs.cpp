
#define MIN(x, y) x > y ? y : x

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
     /*
     cost = |2 4 55 4 12 0| ----> dp = |2 4 57 8 16 16|
     */   
        cost.push_back(0);
        
        int prev = cost[1];
        int prevprev = cost[0];
        int temp_prev = -1;
        for(int i = 2; i < cost.size(); ++i)
        {
            
            temp_prev = MIN(prev + cost[i], prevprev+cost[i]);   
            prevprev = prev;
            prev = temp_prev;
        }
        return prev;
        
    }
};