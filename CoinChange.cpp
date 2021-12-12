#define MAX_AMOUNT 10e4+1
#define MIN(x, y) x > y ? y : x

class Solution {
public:
    int coinChange(vector<int>& coins, const int amount) {
        int dp[amount+1];
        for(int i = 0; i <= amount; ++i)
            dp[i] = MAX_AMOUNT;
        dp[0] = 0;
        for(int i = 0; i <= amount; i++)
        {
            for(auto j: coins)
            {
                if(i - j >= 0)
                    dp[i] = MIN(dp[i - j] + 1, dp[i]);
            }
        }
        
        return dp[amount] == MAX_AMOUNT ? -1 : dp[amount];
    }
};