class Solution {
public:
    void recursion(vector<vector<int>>& grid,vector<vector<int>> &dp, int sum, int row, int col){
        int m = grid.size();
        int n = grid[0].size();

        if (row == m || col == n || row < 0 || col < 0){
            return ;
        }

        if (sum >= dp[row][col]) return ;

        dp[row][col] = min(dp[row][col], sum + grid[row][col]);

        recursion(grid, dp, sum + grid[row][col], row+1, col);
        recursion(grid, dp, sum + grid[row][col], row, col+1);
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp (grid.size(), vector<int>(grid[0].size(), INT_MAX));

        recursion(grid, dp, 0, 0, 0);

        int m = grid.size();
        int n = grid[0].size();

        return dp[m-1][n-1];
    }
};