class Solution {
    
private:
    int dfs(int k, int r, int c, vector<vector<vector<int>>> &dp, vector<vector<int>> &preSum, int m, int n){
        if (preSum[r][c] == 0) return 0;
        
        if (k == 0) return 1;
        
        int ans = 0;
        
        if (dp[k][r][c] != 0) return dp[k][r][c];
        
        for (int i=r; i<m; i++){
            if (preSum[r][c] - preSum[i][c] > 0){
                ans = (ans + dfs(k-1, i,c,dp, preSum,m,n))%((int)pow(10,9) + 7);
            }
        }
        
        for (int i=c; i<n; i++){
            if (preSum[r][c] - preSum[r][i] > 0){
                ans = (ans + dfs(k-1, r,i,dp, preSum,m,n))%((int)pow(10,9) + 7);
            }
        }
        
        return dp[k][r][c] = ans;
    }
    
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();
        
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(m, vector<int>(n, 0)));
        vector<vector<int>> preSum(m+1, vector<int>(n+1, 0));
        
        for (int i=m-1; i>=0; i--){
            for (int j=n-1; j>=0; j--){
                preSum[i][j] = preSum[i+1][j] + preSum[i][j+1] - preSum[i+1][j+1] + (pizza[i][j] == 'A' ? 1:0);
            }
        }
        
        return dfs(k-1,0,0,dp,preSum, m, n);
    }
};