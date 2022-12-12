class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        
        int m = coins.size();
        int n = amount+1;
        
        for (int i=0; i<m; i++){
            dp[i][0] = 1;
        }
        
        for (int i=m-1; i>=0; i--){
            for (int j=1; j<n; j++){
                if (j - coins[i] >= 0) dp[i][j] += dp[i][j - coins[i]];
                if (i + 1 < m) dp[i][j] += dp[i+1][j];
            }
        }
        
        return dp[0][amount];
    }
};