class Solution {
public:
    int countVowelStrings(int n) {
        n = n + 1;
        int dp[n][5];
        for(int i = 0; i < 5; ++i)
            dp[0][i] = 1;
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < 5; ++j)
            {
                if(j==0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[n-1][4];
            
    }
};