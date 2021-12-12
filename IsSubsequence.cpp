#include <iostream>

class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int m = s.length()+1;
        const int n = t.length()+1;
        if(s == t)
            return true;
        if(n == 1)
            return false;
        const char* sc = s.c_str();
        const char* tc = t.c_str();
        
        int dp[m][n];
        for(int i = 0; i < m; ++i)
            dp[i][0] = 0;
        for(int i = 0; i < n; ++i)
            dp[0][i] = 0;
        
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if(sc[i-1] == tc[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = std::max(dp[i-1][j], std::max(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }
        
        return dp[m-1][n-1] == std::min(m-1,n-1);
        
    }
};