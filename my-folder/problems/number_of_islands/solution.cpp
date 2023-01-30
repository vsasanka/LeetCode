class Solution {
public:
    void recursion(vector<vector<char>>& grid, int row, int col){
        int m = grid.size(), n = grid[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '0'){
            return ;
        }

        grid[row][col] = '0';

        recursion(grid, row+1, col);
        recursion(grid, row-1, col);
        recursion(grid, row, col+1);
        recursion(grid, row, col-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        int m = grid.size(), n = grid[0].size();

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == '1'){
                    recursion(grid, i, j);
                    numIslands++;
                }
            }
        }
        
        return numIslands;
    }
};