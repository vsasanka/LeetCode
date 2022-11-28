class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for (int i=3; i<=n; i++){
            for (int j=1; j<i; j++){
                int temp = max(max(dp[i-j]*dp[j], (i-j)*j),max(dp[i-j]*j, (i-j)*dp[j]));
                dp[i] = max(temp, dp[i]);
            }
        }
        
        return dp[n];
    }
};