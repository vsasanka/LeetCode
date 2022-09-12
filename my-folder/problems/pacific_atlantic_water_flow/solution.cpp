class Solution {
    
private:
    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<bool>>&visited, int height){
        // if top or left is border -> mark the current cell 
        
        if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || 
           heights[x][y] < height || visited[x][y]) return ;
        
        visited[x][y] = true;
        
        dfs(heights, x+1,y, visited, heights[x][y]);
        dfs(heights, x-1,y, visited, heights[x][y]);
        dfs(heights, x,y+1, visited, heights[x][y]);
        dfs(heights, x,y-1, visited, heights[x][y]);
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // create boolean arrays for atlantic and pacific
        vector<vector<bool>> pacific, atlantic;
        int m = heights.size();
        int n = heights[0].size();
        pacific.resize(m, vector<bool>(n, false));
        atlantic.resize(m, vector<bool>(n, false));

        vector<vector<int>> res;
        
        // iterate dfs for first (pacific) and last (atlantic) rows
        for (int i=0; i<m; i++){
            dfs(heights, i, 0, pacific, -1);
            dfs(heights, i, n-1, atlantic, -1);
        }
        
        // iterate dfs for first and last columns (pacific and atlantic)
        for (int i=0; i<n; i++){
            dfs(heights, 0, i, pacific, -1);
            dfs(heights, m-1, i, atlantic, -1);
        }
        // compare the pacific and atlantic matrices and populate result
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (atlantic[i][j] && pacific[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        // return result
        return res;
    }
};