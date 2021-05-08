class Solution {
    
private:
    void islands(vector<vector<char>>& grid, vector<vector<bool>>& nums, int i, int j){
        
        // cout << "Inside recursion : " << i << " " << j << " " << endl;
        if (grid[i][j]=='1'){
            nums[i][j] = true;
            
            if (j+1<grid[0].size() && grid[i][j+1]=='1' && nums[i][j+1]==false){
                islands(grid,nums, i, j+1);
            }
            
            if (i+1<grid.size() && grid[i+1][j]=='1' && nums[i+1][j]==false){
                islands(grid,nums, i+1, j);
            }
            
            if (i-1>=0 && grid[i-1][j]=='1' && nums[i-1][j]==false){
                islands(grid,nums, i-1, j);
            }
            
            if (j-1>=0 && grid[i][j-1]=='1' && nums[i][j-1]==false){
                islands(grid,nums, i, j-1);
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> nums;
        
        for (int i=0;i<grid.size();i++){
            vector<bool> bools;
            for (int j=0;j<grid[0].size();j++){
                bools.push_back(false);
            }
            nums.push_back(bools);
        }
        
        int count=0;
        // cout << "count begins ..." << endl;
        
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]=='1' && nums[i][j]==false){
                    cout << i << " " << j << " " << count << endl;
                    islands(grid,nums,i,j);
                    count++;
                    // cout << count << endl;
                }
            }
        }
        
        return count;
    }
};