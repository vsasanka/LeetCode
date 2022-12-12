class Solution {
public:
    int recursion(vector<vector<char>>& matrix, int row, int col, vector<vector<int>> &dp){
        int m = matrix.size();
        int n = matrix[0].size();
        
        if (row >= m || row < 0 || col >= n || col < 0 || matrix[row][col] == '0') return 0;
        
        if (dp[row][col] != 0) return dp[row][col];
        
        int a = recursion(matrix, row+1, col, dp);
        int b = recursion(matrix, row, col+1, dp);
        int c = recursion(matrix, row+1, col+1, dp);
        
        dp[row][col] = 1 + min(min(a,b),c);
        return dp[row][col];
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        int ans = 0;
        
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (matrix[i][j] == '1' && dp[i][j] == 0) recursion(matrix,i,j,dp);
                
                ans = max(ans, dp[i][j]*dp[i][j]);
            }
        }
        
        return ans;
    }
};