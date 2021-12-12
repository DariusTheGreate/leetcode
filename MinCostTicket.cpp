#define MIN(x,y) x > y ? y : x

class Solution {
public:
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int len = 366;//days[days.size()-1];
        int passes[3] = {1,7,30};
        int dp[len+1] = {0};
        
        dp[0] = 0;
        dp[1] = costs[0];
        
        for(int i = len-1; i > 0; --i)
        {
            if(contains(days, i))//map
            {
                dp[i] = 10000000;
                for(int k = 0; k < 3; ++k)
                {
                    if(i + passes[k] > len)
                        continue;
                    dp[i] = MIN(dp[i+passes[k]] + costs[k], dp[i]);
                }
            }
            else
                dp[i]=dp[i+1];
        }
        
        return dp[days[0]];
    }
    
    bool contains(vector<int>& vect, int value)
    {
        for(int i = 0; i < vect.size(); ++i)
            if(vect[i] == value)
                return true;
        return false;
    }
};