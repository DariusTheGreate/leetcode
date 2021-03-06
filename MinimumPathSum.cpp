#define MAXLEN 200
#define MIN(x,y) x > y ? y : x

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[MAXLEN][MAXLEN];
        dp[0][0] = grid[0][0];
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[i].size(); ++j)
            {
                if(i == 0 && j == 0)
                    continue;
                else if(i == 0 && j != 0)                
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                else if(j == 0 && i != 0)
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                else
                    dp[i][j] = (MIN(dp[i-1][j], dp[i][j-1])) + grid[i][j];   
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};