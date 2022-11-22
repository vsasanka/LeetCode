class Solution {
public:
    int recursion(vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp, int row, int col){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (row >= m || col >= n){
            return 0;
        }
        
        if (obstacleGrid[row][col] == 1){
            return 0;
        }
        
        if (row == m-1 && col == n-1){
            return 1;
        }
        
        if (dp[row][col] != 0){
            return dp[row][col];
        }
        
        dp[row][col] = recursion(obstacleGrid, dp, row+1, col);
        dp[row][col] += recursion(obstacleGrid, dp, row, col+1);
        
        // cout << dp[row][col] << endl;
        
        return dp[row][col];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int ans = recursion(obstacleGrid, dp, 0,0);
        
        // for (int i=0; i<m; i++){
        //     for (int j=0; j<n; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        return ans;
    }
};