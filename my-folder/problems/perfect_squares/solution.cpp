class Solution {
public:
    int numSquares(int n) {
        int sq = int(sqrt(n));
        
        vector<int> ps;
        
        for (int i=1; i<=sq; i++){
            ps.push_back(i*i);
            // cout << ps[i-1] << " ";
        }
        
        vector<int> dp(n+1, n+1);
        
        dp[0] = 0;
        
        for (int i=1; i<=n; i++){
            
            for (int j=0; j<ps.size(); j++){
                int denom = ps[j];
                if (i - denom < 0) break;
                
                dp[i] = min(dp[i - denom] + 1, dp[i]);
            }
        }
        
        return dp[n];
    }
};