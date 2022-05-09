class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> colm;
        vector<int> rowm;
        
        for (int i=0; i<grid.size(); i++){
            int max = 0;
            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j]>max){
                    max = grid[i][j];
                }
            }
            
            rowm.push_back(max);
        }
        
        for (int i=0; i<grid.size(); i++){
            int max = 0;
            for (int j=0; j<grid[0].size(); j++){
                if (grid[j][i]>max){
                    max = grid[j][i];
                }
            }
            
            colm.push_back(max);
        }
        
        int ans = 0;
        
        for (int i=0; i<grid.size(); i++){
            
            for (int j=0; j<grid[0].size(); j++){
                ans += min(rowm[i],colm[j]) - grid[i][j];
            }
            
        }
        
        return ans;
    }
};
